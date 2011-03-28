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
    // loop foreach modem, find the first org.ofono.SimToolkit interface
    // in order to pass it to the SimToolkit main window
    foreach(const OfonoModem &pms, modemsCall.value()) {
        bool foundSimToolkit = false;
        // loop interfaces to find "org.ofono.SimToolkit"
        foreach(const QString &interface, pms.varmap.value("Interfaces").toStringList())
        {
            if (interface == "org.ofono.SimToolkit")
            {
                foundSimToolkit = true;
                break;
            }
        }
        if (foundSimToolkit)
        {
            // Instanciate proxy for org.ofono.SimToolkit interface
            simToolkitInterfaces.append(new StkIf("org.ofono",pms.objpath.path(),connection,NULL));
        }
    }
    return simToolkitInterfaces;
}
