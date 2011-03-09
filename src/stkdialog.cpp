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


#include <QVBoxLayout>
#include "stkdialog.h"

StkDialog::StkDialog(StkWidget * stkWidget, QWidget *parent) :
    QDialog(parent)
{
    mStkWidget = stkWidget;
    // layout widget
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(mStkWidget);
    setLayout(layout);
    // connect signals
    connect(mStkWidget, SIGNAL(accepted()), this, SLOT(responseYes()));
    connect(mStkWidget, SIGNAL(rejected()), this, SLOT(responseNo()));
    connect(mStkWidget, SIGNAL(goBack()), this, SLOT(responseBack()));
    connect(mStkWidget, SIGNAL(endSession()), this, SLOT(responseEnd()));
    connect(mStkWidget, SIGNAL(itemSelected(uchar)), this, SLOT(responseOkWithSelection(uchar)));
    connect(mStkWidget, SIGNAL(textEntered(QString)), this, SLOT(responseOkWithText(QString)));
    // default response: end session
    agentResponse = End;
}
