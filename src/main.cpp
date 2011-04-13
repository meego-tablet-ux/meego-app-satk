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

/* Qt includes */
#include <QtDebug>
#include <QtGui/QApplication>
#include <QDBusConnection>
#include <QListWidgetItem>

/* SIM Toolkit main window */
#include "stkmainwindow.h"

/* oFono DBus interfaces */
#include "mgrif.h"
#include "stkif.h"
#include "stkagentifadaptor.h"

/* oFono DBus services */
#include "stkagentservice.h"

/* oFono SIM Toolkit properties*/
#include "stkofonoproperties.h"

/* oFono SIM Toolkit utilities*/
#include "stkofonoutils.h"

/* oFono DBus types */
#include "ofonodbustypes.h"

/* local defines */
#include "stkdefines.h"


int main(int argc, char *argv[])
{
    int mainErr = -1;
    QApplication a(argc, argv);

    // Register meta types defined in ofonodbustypes.h"
    registerOfonoDbusTypes();

    // DBus Connection systemBus
    QDBusConnection systemBus = QDBusConnection::systemBus();
    if( !systemBus.isConnected() ) {
        QDBusError dbusError = systemBus.lastError();
        qDebug() << "Error:" << dbusError.name() << ":" << dbusError.message();
        return mainErr;
    }

    // Instanciate proxy for org.ofono.Manager interface
    MgrIf mgrIf("org.ofono","/",systemBus,NULL);

    // find org.ofono.SimToolkit interfaces for all modems
    QList<StkIf*> stkIfs = StkOfonoUtils::findSimToolkitInterfaces(systemBus,&mgrIf);
    if (stkIfs.isEmpty()) {
        qDebug() << "No org.ofono.SimToolkit interface found, exiting";
        return mainErr;
    }

    // find org.ofono.SimManager interfaces for all modems
    QList<SimIf*> simIfs = StkOfonoUtils::findSimInterfaces(systemBus,&mgrIf);
    if (simIfs.isEmpty()) {
        qDebug() << "No  org.ofono.SimManager interface found, exiting";
        return mainErr;
    }

    // use just the first element of each interfaces list
    StkIf *firstStkIf = stkIfs.first();
    SimIf *firstSimIf = simIfs.first();

    // Hook StkAgentIfAdaptor and StkAgentService together
    StkAgentService * stkAgentService = new StkAgentService(firstSimIf);
    StkAgentIfAdaptor stkAgentIfAdaptor(stkAgentService);

    // hook Sim and Stk interfaces to the main window
    StkMainWindow mainWindow(firstStkIf,firstSimIf);

    // Register stkAgentService and run main application
    if (StkOfonoUtils::registerSimToolkitAgent(systemBus, stkAgentService, firstStkIf) == 0) {
        // open SimToolkit main window
        mainWindow.show();
        // run SimToolkit application
        mainErr = a.exec();
        // Unregister stkAgentService
        StkOfonoUtils::unRegisterSimToolkitAgent(firstStkIf);
    }

    // delete all org.ofono.SimToolkit interfaces
    while (!stkIfs.isEmpty()) {
        delete stkIfs.first();
        stkIfs.removeFirst();
    }
    // delete all org.ofono.SimManager interfaces
    while (!simIfs.isEmpty()) {
        delete simIfs.first();
        simIfs.removeFirst();
    }
    // StkAgentService is deleted by StkAgentIfAdaptor destructor

    return mainErr;
}
