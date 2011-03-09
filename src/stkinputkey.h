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


#ifndef STKINPUTKEY_H
#define STKINPUTKEY_H

#include <QWidget>
#include "stkwidget.h"

class QPixmap;
class QLabel;
class QPushButton;
class QLineEdit;
class QDialogButtonBox;

class StkInputKey : public StkWidget
{
    Q_OBJECT
public:
    explicit StkInputKey(const QPixmap & pixmap, const QString & text, QWidget *parent = 0);
    virtual ~StkInputKey();

signals:

private:
    QLabel * mText;
    QLabel * mIcon;
    QLineEdit * mEditKey;
    QPushButton * mBackButton;
    QDialogButtonBox * mOkBox;

private slots:
    void keyEntered();
};

#endif // STKINPUTKEY_H
