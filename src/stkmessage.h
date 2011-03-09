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


#ifndef STKMESSAGE_H
#define STKMESSAGE_H

#include <QWidget>
#include "stkwidget.h"

class QPixmap;
class QLabel;
class QPushButton;

class StkMessage : public StkWidget
{
    Q_OBJECT
public:
    explicit StkMessage(const QPixmap & pixmap, const QString & text, QWidget *parent = 0);
    virtual ~StkMessage();

signals:

private:
    QLabel * mText;
    QLabel * mIcon;
    QPushButton * mEndButton;
};

#endif // STKMESSAGE_H
