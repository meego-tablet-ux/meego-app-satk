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
#include "simimageprovider.h"

StkMainWindow::StkMainWindow(StkIf *stkIf, SimIf *simIf, QWidget *parent) :
    QMainWindow(parent)
{
    mStkIf = stkIf;
    mSimIf = simIf;
    // Store SimToolkit interface properties
    mStkProperties = new StkOfonoProperties(mStkIf,mSimIf);
    // Create a qml view
    mView = new QDeclarativeView;
    // Register image provider, deleted with the engine
    QDeclarativeEngine * engine = mView->engine();
    engine->addImageProvider(SIM_IMAGE_PROVIDER, new SimImageProvider(simIf));
    // Load a qml main menu
    mView->setSource(QUrl("qrc:/stkmenu.qml"));
    // Set it as central widget
    mView->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    this->setCentralWidget(mView);
    QObject *root = mView->rootObject();
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
    connect(root, SIGNAL(itemSelected(int)), this, SLOT(responseOkWithSelection(int)));
    connect(root, SIGNAL(goBack()), this, SLOT(close()));
    connect(root, SIGNAL(endSession()), this, SLOT(close()));
}

StkMainWindow::~StkMainWindow()
{
    delete mView;
}

void StkMainWindow::responseOkWithSelection(int selection)
{
    uchar sel = (uchar)selection;
    QDBusObjectPath stkAgentPath(STK_AGENT_PATH);
    mStkIf->SelectItem(sel,stkAgentPath);
}
