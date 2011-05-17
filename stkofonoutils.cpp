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

#include "sim_32x32.xpm"

QPixmap StkOfonoUtils::findIcon(SimIf * simIf, uchar id)
{
    if (!VALID_ICON_ID(id))
        return QPixmap(sim_32x32_xpm);
    // org.ofono.SimManager interface GetIcon method
    QDBusPendingReply<QByteArray> iconCall = simIf->GetIcon(id);
    iconCall.waitForFinished();
    if (iconCall.isError()) {
        QDBusError dbusError = iconCall.error();
        qDebug() << "findIcon DBus Error:" << dbusError.name() << ":" << dbusError.message();
        return QPixmap(sim_32x32_xpm);
    }
    QPixmap icon;
    if (!icon.loadFromData(iconCall.value(),"XPM")) {
        qDebug() << "Error decoding icon XPM data : " << iconCall.value().data();
        return QPixmap(sim_32x32_xpm);
    }
    return icon;
}

QString StkOfonoUtils::findIconUrl(uchar id)
{
    return SIM_ICON_PREFIX + QString::number((int)id);
}

OfonoModemList StkOfonoUtils::findModems(MgrIf *mgrIf)
{
    // org.ofono.Manager interface GetModems method
    QDBusPendingReply<OfonoModemList> modemsCall = mgrIf->GetModems();
    modemsCall.waitForFinished();
    if (modemsCall.isError()) {
        QDBusError dbusError = modemsCall.error();
        qDebug() << "findModems DBus Error:" << dbusError.name() << ":" << dbusError.message();
        return OfonoModemList();
    }
    return modemsCall.value();
}

QList<SimIf*> StkOfonoUtils::findSimInterfaces(const QDBusConnection &connection, MgrIf *mgrIf)
{
    QList<SimIf*> simInterfaces;
    OfonoModemList modems = StkOfonoUtils::findModems(mgrIf);
    // loop foreach modem, find all org.ofono.SimManager interfaces
    foreach(const OfonoModem &pms, modems) {
        // loop interfaces to find "org.ofono.SimManager"
        foreach(const QString &interface, pms.varmap.value("Interfaces").toStringList()) {
            if (interface == "org.ofono.SimManager") {
                // Instanciate proxy for org.ofono.SimManager interface
                simInterfaces.append(new SimIf("org.ofono",pms.objpath.path(),connection,NULL));
                break;
            }
        }
    }
    return simInterfaces;
}

QList<StkIf*> StkOfonoUtils::findSimToolkitInterfaces(const QDBusConnection &connection, MgrIf *mgrIf)
{
    QList<StkIf*> simToolkitInterfaces;
    OfonoModemList modems = StkOfonoUtils::findModems(mgrIf);
    // loop foreach modem, find all org.ofono.SimManager interfaces
    foreach(const OfonoModem &pms, modems) {
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
