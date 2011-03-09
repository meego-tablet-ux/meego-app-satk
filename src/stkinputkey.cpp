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

#include "stkinputkey.h"

StkInputKey::StkInputKey(const QPixmap & pixmap, const QString & text, QWidget *parent) :
    StkWidget(parent)
{
    // create widgets
    // main icon
    mIcon = new QLabel(this);
    mIcon->setPixmap(pixmap);
    // main text message
    mText = new QLabel(text, this);
    // input key line edit
    mEditKey = new QLineEdit(this);
    mEditKey->setMaxLength(1);
    mEditKey->setAlignment(Qt::AlignHCenter);
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
    // input key line edit middle left
    grid->addWidget(mEditKey,2,0,1,2,Qt::AlignHCenter);
    // ok button box bottom left
    grid->addWidget(mOkBox,3,0,Qt::AlignHCenter);
    // back button bottom right
    grid->addWidget(mBackButton,3,1,Qt::AlignRight);

    // connect signals
    connect(mBackButton, SIGNAL(clicked()), this, SIGNAL(goBack()));
    connect(mOkBox, SIGNAL(accepted()), this, SLOT(keyEntered()));
}

StkInputKey::~StkInputKey()
{
    close();
    delete mText;
    delete mIcon;
    delete mEditKey;
    delete mBackButton;
    delete mOkBox;
}

void StkInputKey::keyEntered() {
    emit textEntered(mEditKey->text());
}
