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


#include "stkmenumodel.h"

StkMenuModel::StkMenuModel(QObject *parent) :
    QAbstractListModel(parent)
{
    QHash<int, QByteArray> roles;
    roles[TitleRole] = "title";
    roles[IconRole] = "icon";
    setRoleNames(roles);
}


int StkMenuModel::rowCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return mItems.count();
}


QVariant StkMenuModel::data(const QModelIndex & index, int role) const
{
    if (index.row() < 0 || index.row() > mItems.count())
        return QVariant();
    switch (role) {
        case TitleRole:
            return mItems[index.row()].title();
        case IconRole:
            return mItems[index.row()].icon();
    }
    return QVariant();
}


void StkMenuModel::setMenuItems(const QList<StkMenuItem> &items)
{
    mItems = items;
}
