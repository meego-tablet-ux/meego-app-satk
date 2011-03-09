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

#include "stkyesno.h"

StkYesNo::StkYesNo(const QPixmap & pixmap, const QString & text, QWidget *parent) :
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
    // yes/no button box
    mYesNoBox = new QDialogButtonBox(QDialogButtonBox::Yes|QDialogButtonBox::No,Qt::Horizontal,this);

    // layout widgets
    // grid layout 3x2
    QGridLayout *grid = new QGridLayout(this);
    // main icon topleft
    grid->addWidget(mIcon,0,0,Qt::AlignLeft);
    // end session button topright
    grid->addWidget(mEndButton,0,1,Qt::AlignRight|Qt::AlignTop);
    // main text message middle left
    grid->addWidget(mText,1,0,1,2,Qt::AlignHCenter);
    // yes/no button box bottom left
    grid->addWidget(mYesNoBox,2,0,Qt::AlignHCenter);

    // connect signals
    connect(mEndButton, SIGNAL(clicked()), this, SIGNAL(endSession()));
    connect(mYesNoBox, SIGNAL(accepted()), this, SIGNAL(accepted()));
    connect(mYesNoBox, SIGNAL(rejected()), this, SIGNAL(rejected()));
}

StkYesNo::~StkYesNo()
{
    close();
    delete mText;
    delete mIcon;
    delete mEndButton;
    delete mYesNoBox;
}
