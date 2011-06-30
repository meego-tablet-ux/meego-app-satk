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


#ifndef STKOFONOUTILS_H
#define STKOFONOUTILS_H

#include <QPixmap>
#include <QDBusConnection>
#include "mgrif.h"
#include "modemif.h"
#include "stkif.h"
#include "simif.h"
#include "stkagentservice.h"

class StkOfonoUtils
{
public:
    static QPixmap findIcon(SimIf * simIf, uchar id);
    static QString findIconUrl(uchar id);
    static OfonoModemList findModems(MgrIf *mgrIf);
    static QList<ModemIf*> findModemInterfaces(const QDBusConnection &connection,
                                               MgrIf *mgrIf);
    static QList<SimIf*> findSimInterfaces(const QDBusConnection &connection,
                                           MgrIf *mgrIf);
    static QList<StkIf*> findSimToolkitInterfaces(const QDBusConnection &connection,
                                                  MgrIf *mgrIf);
    static int registerSimToolkitAgent(QDBusConnection &connection,
                                       StkAgentService *stkAgentService, StkIf *stkIf);
    static int unRegisterSimToolkitAgent(StkIf *stkIf);
};

#endif // STKOFONOUTILS_H
