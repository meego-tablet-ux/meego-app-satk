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
#include <QtGui/QApplication>
#include <QDBusConnection>
#include <QtDebug>

/* SIM Toolkit app and main window */
#include "stkapplication.h"
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
    StkApplication app(argc, argv);

    // Parse arguments
    if (argc > 2) {
        printf("%s\n",SATK_USAGE);
        return mainErr;
    }
    // Run in menu mode by default
    bool agentMode = false;
    if (argc == 2) {
        QString satkMode(argv[1]);
        if (satkMode == "agent")
            agentMode = true;
        else if (satkMode != "menu") {
            printf("%s\n",SATK_USAGE);
            return mainErr;
        }
    }

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

    // Look for SimManager and SimToolkit interfaces
    if (!app.initOfonoConnection(systemBus,&mgrIf)) {
        // in agent mode, just wait for SIM initialization,
        // otherwise exit
        if (!agentMode) {
            qDebug() << "Can't connect to a SimToolkit interface, exiting";
            return mainErr;
        }
    }

    // use just the first element of each interfaces list
    StkIf *firstStkIf = app.stkIf();
    SimIf *firstSimIf = app.simIf();

    // Hook StkAgentIfAdaptor and StkAgentService together
    StkAgentService * stkAgentService = new StkAgentService(firstSimIf);
    StkAgentIfAdaptor stkAgentIfAdaptor(stkAgentService);

    // Register stkAgentService
    bool registered = true;
    if (StkOfonoUtils::registerSimToolkitAgent(systemBus, stkAgentService, firstStkIf) != 0) {
        registered = false;
        // Don't run in agent mode if a stkAgentService is already registered
        if (agentMode) {
            qDebug() << "Agent registration failed, exiting";
            return mainErr;
        }
    }

    // hook Sim and Stk interfaces to the main window
    StkMainWindow mainWindow(firstStkIf,firstSimIf,stkAgentService);
    // Open SimToolkit main window in menu mode only
    if (!agentMode)
        mainWindow.show();

    // Run SimToolkit application
    mainErr = app.exec();

    // Unregister stkAgentService if we registered it
    if (registered)
        StkOfonoUtils::unRegisterSimToolkitAgent(firstStkIf);

    // StkAgentService is deleted by StkAgentIfAdaptor destructor

    return mainErr;
}
