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
#include <QDialogButtonBox>
#include <QGridLayout>

#include "stkpopup.h"

StkPopup::StkPopup(const QPixmap & pixmap, const QString & text, QWidget *parent) :
    StkWidget(parent)
{
    // create widgets
    // main icon
    mIcon = new QLabel(this);
    mIcon->setPixmap(pixmap);
    // main text message
    mText = new QLabel(text, this);
    // end session button
    mEndButton = new QPushButton("End",this);
    // back button
    mBackButton = new QPushButton("Back",this);
    // ok button box
    mOkBox = new QDialogButtonBox(QDialogButtonBox::Ok,Qt::Horizontal,this);

    // layout widgets
    // grid layout 3x2
    QGridLayout *grid = new QGridLayout(this);
    // main icon topleft
    grid->addWidget(mIcon,0,0,Qt::AlignLeft);
    // end session button topright
    grid->addWidget(mEndButton,0,1,Qt::AlignRight|Qt::AlignTop);
    // main text message middle left
    grid->addWidget(mText,1,0,1,2,Qt::AlignHCenter);
    // ok button box bottom left
    grid->addWidget(mOkBox,2,0,Qt::AlignHCenter);
    // back button bottom right
    grid->addWidget(mBackButton,2,1,Qt::AlignRight);

    // connect signals
    connect(mEndButton, SIGNAL(clicked()), this, SIGNAL(endSession()));
    connect(mBackButton, SIGNAL(clicked()), this, SIGNAL(goBack()));
    connect(mOkBox, SIGNAL(accepted()), this, SIGNAL(accepted()));
}

StkPopup::~StkPopup()
{
    close();
    delete mText;
    delete mIcon;
    delete mEndButton;
    delete mBackButton;
    delete mOkBox;
}
