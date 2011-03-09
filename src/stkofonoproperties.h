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


#ifndef STKOFONOPROPERTIES_H
#define STKOFONOPROPERTIES_H

#include <QObject>
#include <QString>
#include <QPixmap>
#include <QList>
#include <QListWidgetItem>
#include "stkif.h"


class StkOfonoProperties : public QObject
{
    Q_OBJECT
public:
    explicit StkOfonoProperties(StkIf *stkIf, QObject *parent = 0);
    QList<QListWidgetItem *> mainMenuItems();
    QString mainMenuTitle();
    QPixmap mainMenuIcon();

signals:

private:
    QVariantMap mProperties;
};

#endif // STKOFONOPROPERTIES_H
