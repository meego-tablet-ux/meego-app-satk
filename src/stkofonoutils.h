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
#include "stkif.h"
#include "stkagentservice.h"

class StkOfonoUtils
{
public:
    static QPixmap findIcon(uchar id);
    static QString findIconUrl(uchar id);
    static QList<StkIf*> findSimToolkitInterfaces(const QDBusConnection &connection, MgrIf *mgrIf);
    static int registerSimToolkitAgent(QDBusConnection &connection, StkAgentService *stkAgentService, StkIf *stkIf);
    static int unRegisterSimToolkitAgent(StkIf *stkIf);
};

#endif // STKOFONOUTILS_H
