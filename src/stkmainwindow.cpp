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

#include <QtDeclarative>
#include "stkmainwindow.h"
#include "stkmenumodel.h"
#include "stkdefines.h"

StkMainWindow::StkMainWindow(StkIf *stkIf, QWidget *parent) :
    QMainWindow(parent)
{
    mStkIf = stkIf;
    // Store SimToolkit interface properties
    mStkProperties = new StkOfonoProperties(mStkIf);
    // Create a main menu as central widget
    this->mView = new QDeclarativeView;
    this->mView->setSource(QUrl("qrc:/stkmenu.qml"));
    this->mView->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    this->setCentralWidget(this->mView);
    QObject *root = this->mView->rootObject();
    QObject *icon = root->findChild<QObject*>("icon");
    if (icon)
        icon->setProperty("source", mStkProperties->mainMenuIconUrl());
    QObject *title = root->findChild<QObject*>("title");
    if (title)
        title->setProperty("text", mStkProperties->mainMenuTitle());
    QDeclarativeContext *context = mView->rootContext();
    StkMenuModel * menuModel = new StkMenuModel();
    menuModel->setMenuItems(mStkProperties->mainMenuItems());
    context->setContextProperty("menuModel",menuModel);
    // connect signals
    QObject * view = root/*->findChild<QObject*>("view")*/;
qDebug() << "View:" << view;
    if (view) {
        connect(view, SIGNAL(itemSelected(int)), this, SLOT(responseOkWithSelection(int)));
        connect(view, SIGNAL(goBack()), this, SLOT(close()));
        connect(view, SIGNAL(endSession()), this, SLOT(close()));
    }
}

StkMainWindow::~StkMainWindow()
{
    delete this->mView;
}

void StkMainWindow::responseOkWithSelection(int selection)
{
    uchar sel = (uchar)selection;
    QDBusObjectPath stkAgentPath(STK_AGENT_PATH);
    mStkIf->SelectItem(sel,stkAgentPath);
}
