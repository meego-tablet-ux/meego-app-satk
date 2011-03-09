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


#ifndef STKYESNO_H
#define STKYESNO_H

#include <QWidget>
#include "stkwidget.h"

class QPixmap;
class QLabel;
class QPushButton;
class QDialogButtonBox;

class StkYesNo : public StkWidget
{
    Q_OBJECT
public:
    explicit StkYesNo(const QPixmap & pixmap, const QString & text, QWidget *parent = 0);
    virtual ~StkYesNo();

signals:

private:
    QLabel * mText;
    QLabel * mIcon;
    QPushButton * mEndButton;
    QDialogButtonBox * mYesNoBox;
};

#endif // STKYESNO_H
