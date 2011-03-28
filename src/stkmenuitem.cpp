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


#include "stkmenuitem.h"

StkMenuItem::StkMenuItem(const QString &icon, const QString &title)
{
    mIcon = icon;
    mTitle = title;
}

QString StkMenuItem::icon() const
{
    return mIcon;
}

QString StkMenuItem::title() const
{
    return mTitle;
}

