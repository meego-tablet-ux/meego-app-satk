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


#ifndef STKMAINWINDOW_H
#define STKMAINWINDOW_H

#include <QMainWindow>
#include "stkif.h"
#include "stkofonoproperties.h"
#include "stkmenu.h"

class StkMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit StkMainWindow(StkIf *stkIf, QWidget *parent = 0);

signals:

private:
    StkIf *mStkIf;
    StkOfonoProperties * mStkProperties;
    StkMenu *mStkMenu;

private slots:
    void responseOkWithSelection(uchar selection);
};

#endif // STKMAINWINDOW_H
