/*
 * satk - SIM application toolkit
 * Copyright © 2011, Intel Corporation.
 *
 * This program is licensed under the terms and conditions of the
 * Apache License, version 2.0.  The full text of the Apache License is at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Written by - Luc Yriarte <luc.yriarte@linux.intel.com>
 */

#include <QtDBus>
#include "ofonodbustypes.h"
#include "stkofonoutils.h"
#include "stkdefines.h"


QPixmap StkOfonoUtils::findIcon(uchar id)
{ // #### TODO implement
    return TEST_PIXMAP;
}

QString StkOfonoUtils::findIconUrl(uchar id)
{ // #### TODO implement
    return TEST_ICON_URL;
}

QList<StkIf*> StkOfonoUtils::findSimToolkitInterfaces(const QDBusConnection &connection, MgrIf *mgrIf)
{
    QList<StkIf*> simToolkitInterfaces;
    QDBusError dbusError;
    // org.ofono.Manager interface GetModems method
    QDBusPendingReply<OfonoModemList> modemsCall = mgrIf->GetModems();
    modemsCall.waitForFinished();
    if (modemsCall.isError()) {
        dbusError = modemsCall.error();
        qDebug() << "Error:" << dbusError.name() << ":" << dbusError.message();
        return simToolkitInterfaces;
    }
    // loop foreach modem, find all org.ofono.SimToolkit interfaces
    foreach(const OfonoModem &pms, modemsCall.value()) {
        // loop interfaces to find "org.ofono.SimToolkit"
        foreach(const QString &interface, pms.varmap.value("Interfaces").toStringList()) {
            if (interface == "org.ofono.SimToolkit") {
                // Instanciate proxy for org.ofono.SimToolkit interface
                simToolkitInterfaces.append(new StkIf("org.ofono",pms.objpath.path(),connection,NULL));
                break;
            }
        }
    }
    return simToolkitInterfaces;
}

int StkOfonoUtils::registerSimToolkitAgent(QDBusConnection &connection, StkAgentService *stkAgentService, StkIf *stkIf)
{
    QDBusError dbusError;
    QDBusObjectPath stkAgentPath(STK_AGENT_PATH);
    if (!connection.registerObject(stkAgentPath.path(),stkAgentService)) {
        dbusError = connection.lastError();
        qDebug() << "registerObject Error:" << dbusError.name() << ":" << dbusError.message();
        return -1;
    }
    // Register SimToolkitAgent with org.ofono.SimToolkit interface RegisterAgent method
    QDBusPendingReply<> stkRegisterCall = stkIf->RegisterAgent(stkAgentPath);
    stkRegisterCall.waitForFinished();
    if (stkRegisterCall.isError()) {
        dbusError = stkRegisterCall.error();
        qDebug() << "RegisterAgent error:" << dbusError.name() << ":" << dbusError.message();
        return -1;
    }
    return 0;
}

int StkOfonoUtils::unRegisterSimToolkitAgent(StkIf *stkIf)
{
    QDBusError dbusError;
    QDBusObjectPath stkAgentPath(STK_AGENT_PATH);
    QDBusPendingReply<> stkRegisterCall = stkIf->UnregisterAgent(stkAgentPath);
    stkRegisterCall.waitForFinished();
    if (stkRegisterCall.isError()) {
        dbusError = stkRegisterCall.error();
        qDebug() << "UnregisterAgent error:" << dbusError.name() << ":" << dbusError.message();
        return -1;
    }
    return 0;
}
