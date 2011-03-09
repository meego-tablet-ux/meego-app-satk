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


#ifndef STKPOPUP_H
#define STKPOPUP_H

#include <QWidget>
#include "stkwidget.h"

class QPixmap;
class QLabel;
class QPushButton;
class QDialogButtonBox;

class StkPopup : public StkWidget
{
    Q_OBJECT
public:
    explicit StkPopup(const QPixmap & pixmap, const QString & text, QWidget *parent = 0);
    virtual ~StkPopup();

signals:

private:
    QLabel * mText;
    QLabel * mIcon;
    QPushButton * mEndButton;
    QPushButton * mBackButton;
    QDialogButtonBox * mOkBox;
};

#endif // STKPOPUP_H
