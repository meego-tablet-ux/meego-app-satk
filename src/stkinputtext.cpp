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

#include <Qt>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QGridLayout>

#include "stkinputtext.h"


StkInputText::StkInputText(const QPixmap & pixmap, const QString & text, QWidget *parent) :
    StkWidget(parent)
{
    // initialize private variables
    mMinChars = -1;
    mMaxChars = -1;
    mHideTyping = false;
    mNumeric = false;

    // create widgets
    // main icon
    mIcon = new QLabel(this);
    mIcon->setPixmap(pixmap);
    // main text message
    mText = new QLabel(text, this);
    // input text edit
    mEditText = new QLineEdit(this);
    // back button
    mBackButton = new QPushButton("Back",this);
    // ok button box
    mOkBox = new QDialogButtonBox(QDialogButtonBox::Ok,Qt::Horizontal,this);

    // layout widgets
    // grid layout 4x2
    QGridLayout *grid = new QGridLayout(this);
    // main icon topleft
    grid->addWidget(mIcon,0,0,Qt::AlignLeft);
    // main text message middle left
    grid->addWidget(mText,1,0,1,2,Qt::AlignHCenter);
    // input text edit middle left
    grid->addWidget(mEditText,2,0,1,2,Qt::AlignHCenter);
    // ok button box bottom left
    grid->addWidget(mOkBox,3,0,Qt::AlignHCenter);
    // back button bottom right
    grid->addWidget(mBackButton,3,1,Qt::AlignRight);

    // connect signals
    connect(mBackButton, SIGNAL(clicked()), this, SIGNAL(goBack()));
    connect(mOkBox, SIGNAL(accepted()), this, SLOT(textEntered()));
}


StkInputText::~StkInputText()
{
    close();
    delete mText;
    delete mIcon;
    delete mEditText;
    delete mBackButton;
    delete mOkBox;
}


void StkInputText::setDefaultText(const QString & defaultText)
{
    mDefaultText = defaultText;
    mText->setText(mDefaultText);
}


void StkInputText::setCharBounds(int minChars, int maxChars)
{
    mMinChars = minChars;
    mMaxChars = maxChars;
    if (mMaxChars != -1)
        mEditText->setMaxLength(maxChars);
    // #### TODO #### Handle minChars input
}


void StkInputText::setHideTyping(bool hideTyping)
{
    mHideTyping = hideTyping;
    mEditText->setEchoMode(mHideTyping ? QLineEdit::PasswordEchoOnEdit : QLineEdit::Normal);
}


void StkInputText::setNumeric(bool numeric)
{
    mNumeric = numeric;
    // #### TODO #### Handle numeric input
}


void StkInputText::textEntered() {
    emit StkWidget::textEntered(mEditText->text());
}
