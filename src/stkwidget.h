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


#ifndef STKWIDGET_H
#define STKWIDGET_H

#include <QWidget>

class StkWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StkWidget(QWidget *parent = 0);

signals:
    void accepted();
    void rejected();
    void goBack();
    void endSession();
    void itemSelected(uchar selection);
    void textEntered(QString text);
};

#endif // STKWIDGET_H
