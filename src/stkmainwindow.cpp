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

#include "stkmainwindow.h"
#include "stkdefines.h"

StkMainWindow::StkMainWindow(StkIf *stkIf, QWidget *parent) :
    QMainWindow(parent)
{
    mStkIf = stkIf;
    // Store SimToolkit interface properties
    mStkProperties = new StkOfonoProperties(mStkIf);
    // Create a main menu as central widgt
    mStkMenu = new StkMenu(mStkProperties->mainMenuIcon(),mStkProperties->mainMenuTitle(),mStkProperties->mainMenuItems(),this);
    this->setCentralWidget(mStkMenu);
    this->setWindowTitle(mStkProperties->mainMenuTitle());
    this->setWindowIcon(QIcon(mStkProperties->mainMenuIcon()));

    // connect signals
    connect(mStkMenu, SIGNAL(itemSelected(uchar)), this, SLOT(responseOkWithSelection(uchar)));
    connect(mStkMenu, SIGNAL(goBack()), this, SLOT(close()));
    connect(mStkMenu, SIGNAL(endSession()), this, SLOT(close()));
}

void StkMainWindow::responseOkWithSelection(uchar selection)
{
    QDBusObjectPath stkAgentPath(STK_AGENT_PATH);
    mStkIf->SelectItem(selection,stkAgentPath);
}
