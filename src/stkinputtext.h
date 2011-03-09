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


#ifndef STKINPUTTEXT_H
#define STKINPUTTEXT_H

#include <QWidget>
#include "stkwidget.h"

class QPixmap;
class QLabel;
class QPushButton;
class QLineEdit;
class QDialogButtonBox;

class StkInputText : public StkWidget
{
    Q_OBJECT
public:
    explicit StkInputText(const QPixmap & pixmap, const QString & text, QWidget *parent = 0);
    virtual ~StkInputText();

    void setDefaultText(const QString & defaultText);
    void setCharBounds(int minChars, int maxChars);
    void setHideTyping(bool hideTyping=true);
    void setNumeric(bool numeric=true);

signals:

private:
    QLabel * mText;
    QLabel * mIcon;
    QLineEdit * mEditText;
    QPushButton * mBackButton;
    QDialogButtonBox * mOkBox;

    QString mDefaultText;
    int mMinChars;
    int mMaxChars;
    bool mHideTyping;
    bool mNumeric;

private slots:
    void textEntered();
};

#endif // STKINPUTTEXT_H
