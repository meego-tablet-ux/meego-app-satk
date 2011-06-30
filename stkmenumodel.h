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


#ifndef STKMENUMODEL_H
#define STKMENUMODEL_H

#include <QAbstractListModel>
#include <QModelIndex>
#include <QVariant>
#include <QList>
#include "stkmenuitem.h"

class StkMenuModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum MenuItemRoles {
        TitleRole = Qt::UserRole + 1,
        IconRole
    };

    explicit StkMenuModel(QObject *parent = 0);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    void setMenuItems(const QList<StkMenuItem> &items);

signals:

public slots:

private:
    QList <StkMenuItem> mItems;
};

#endif // STKMENUMODEL_H
