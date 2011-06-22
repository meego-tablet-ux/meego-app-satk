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


#include <QtDebug>
#include <QIcon>
#include <QDBusArgument>
#include <QVariantMap>
#include <QMapIterator>
#include "ofonodbustypes.h"
#include "stkofonoutils.h"
#include "stkofonoproperties.h"


StkOfonoProperties::StkOfonoProperties(StkIf *stkIf, SimIf *simIf, QObject *parent) :
    QObject(parent)
{
    mStkIf = stkIf;
    mSimIf = simIf;
    // org.ofono.SimToolkit interface GetProperties method
    QDBusPendingReply<QVariantMap> stkPropsCall = mStkIf->GetProperties();
    stkPropsCall.waitForFinished();
    if (stkPropsCall.isError()) {
        QDBusError error = stkPropsCall.error();
        qDebug() << "Error:" << error.name() << ":" << error.message();
    } else {
        // get properties map
        mProperties = stkPropsCall.value();
    }
}


QList<StkMenuItem> StkOfonoProperties::mainMenuItems()
{
    QList<StkMenuItem> items;
    // "MainMenu" property
    QVariant varMenu = mProperties.value("MainMenu");
    QDBusArgument arg = varMenu.value<QDBusArgument>();
    // demarshall a(sy) QDBusArgument to a QList<OfonoMenuEntry> registered as OfonoMenuList
    OfonoMenuList menuList;
    arg >> menuList;
    foreach (const OfonoMenuEntry entry, menuList)
        items.append(StkMenuItem(StkOfonoUtils::findIconUrl(entry.icon), entry.label));
    return items;
}


QString StkOfonoProperties::mainMenuTitle()
{
    return mProperties.value("MainMenuTitle").toString();
}


QString StkOfonoProperties::mainMenuIconUrl()
{
    return StkOfonoUtils::findIconUrl((uchar)mProperties.value("MainMenuIcon").toChar().toAscii());
}
