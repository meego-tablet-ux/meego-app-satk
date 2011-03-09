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


#ifndef OFONODBUSTYPES_H
#define OFONODBUSTYPES_H

#include <QString>
#include <QList>
#include <QMap>
#include <QtDBus/QtDBus>


/*
 * Interface: org.ofono.Manager
 * Method: GetModems
 * Argument: Out0
 */

typedef struct
{
    QDBusObjectPath objpath;            /* o */
    QVariantMap varmap;                 /* a{sv} */
} OfonoModem;
Q_DECLARE_METATYPE(OfonoModem)       /* oa{sv} */

inline QDBusArgument &operator<<(QDBusArgument &arg,const OfonoModem &pms)
{
    arg.beginStructure();
    arg << pms.objpath << pms.varmap;
    arg.endStructure();
    return arg;
}

inline const QDBusArgument &operator>>(const QDBusArgument &arg,OfonoModem &pms)
{
    arg.beginStructure();
    arg >> pms.objpath >> pms.varmap;
    arg.endStructure();
    return arg;
}

typedef QList<OfonoModem> OfonoModemList;
Q_DECLARE_METATYPE(OfonoModemList)   /* a(oa{sv}) */


/*
 * Interface: org.ofono.SimToolkitAgent
 * Method: RequestSelection
 * Argument: In2
 */

typedef struct
{
    QString label;                      /* s */
    uchar icon;                         /* y */
} OfonoMenuEntry;
Q_DECLARE_METATYPE(OfonoMenuEntry)      /* sy */

inline QDBusArgument &operator<<(QDBusArgument &arg,const OfonoMenuEntry &ome)
{
    arg.beginStructure();
    arg << ome.label << ome.icon;
    arg.endStructure();
    return arg;
}

inline const QDBusArgument &operator>>(const QDBusArgument &arg,OfonoMenuEntry &ome)
{
    arg.beginStructure();
    arg >> ome.label >> ome.icon;
    arg.endStructure();
    return arg;
}

typedef QList<OfonoMenuEntry> OfonoMenuList;
Q_DECLARE_METATYPE(OfonoMenuList)       /* a{sy} */


/* Register all meta types declared above */

inline void registerOfonoDbusTypes()
{
    qDBusRegisterMetaType<OfonoModem>();
    qDBusRegisterMetaType<OfonoModemList>();
    qDBusRegisterMetaType<OfonoMenuEntry>();
    qDBusRegisterMetaType<OfonoMenuList>();
}



#endif // OFONODBUSTYPES_H
