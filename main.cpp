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

    // Initiate connection with oFono
    bool ofonoConnectionReady = app.initOfonoConnection(agentMode);

    StkMainWindow * mainWindow = NULL;
    if (agentMode) {
        // oFono connection can be deferred, but agent must be registered
        if (ofonoConnectionReady && !app.agentServiceRegistered()) {
            qDebug() << "Error: cannot register agent service";
            return mainErr;
        }
    }
    else // Main menu mode
    {   // Agent can be already registered, but
        // oFono connection must be up from the start
        if (!ofonoConnectionReady) {
            qDebug() << "Error: oFono connection not ready";
            return mainErr;
        }
        // hook Sim and Stk interfaces to the main window
        // Open SimToolkit main window in menu mode only
        mainWindow = new StkMainWindow(app.stkIf(),app.simIf(),app.stkAgentService());
        mainWindow->show();
    }

    // Run SimToolkit application
    mainErr = app.exec();

    if (mainWindow != NULL)
        delete mainWindow;

    return mainErr;
}
