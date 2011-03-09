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


#ifndef STKMENU_H
#define STKMENU_H

#include <QWidget>
#include "stkwidget.h"

class QPixmap;
class QLabel;
class QPushButton;
class QListWidget;
class QListWidgetItem;
class QDialogButtonBox;

class StkMenu : public StkWidget
{
    Q_OBJECT
public:
    explicit StkMenu(const QPixmap & pixmap, const QString & text, const QList<QListWidgetItem *> items, QWidget *parent = 0);
    virtual ~StkMenu();

    void setCurrentRow(int row);

signals:

private:
    QLabel * mText;
    QLabel * mIcon;
    QListWidget * mMenuList;
    QPushButton * mEndButton;
    QPushButton * mBackButton;
    QDialogButtonBox * mOkBox;

private slots:
    void itemSelected();
};

#endif // STKMENU_H
