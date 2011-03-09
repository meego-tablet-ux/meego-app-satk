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
#include <QGridLayout>

#include "stkmessage.h"

StkMessage::StkMessage(const QPixmap & pixmap, const QString & text, QWidget *parent) :
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

    // layout widgets
    // grid layout 2x2
    QGridLayout *grid = new QGridLayout(this);
    // main icon topleft
    grid->addWidget(mIcon,0,0,Qt::AlignLeft);
    // end session button topright
    grid->addWidget(mEndButton,0,1,Qt::AlignRight|Qt::AlignTop);
    // main text message middle left
    grid->addWidget(mText,1,0,1,2,Qt::AlignHCenter);

    // connect signals
    connect(mEndButton, SIGNAL(clicked()), this, SIGNAL(endSession()));
}

StkMessage::~StkMessage()
{
    close();
    delete mText;
    delete mIcon;
    delete mEndButton;
}
