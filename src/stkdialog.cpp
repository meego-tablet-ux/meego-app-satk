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
#include <QtDeclarative>
#include "stkdialog.h"
#include "stkmenumodel.h"

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
    connect(mStkWidget, SIGNAL(itemSelected(int)), this, SLOT(responseOkWithSelection(int)));
    connect(mStkWidget, SIGNAL(textEntered(QString)), this, SLOT(responseOkWithText(QString)));
    // default response: end session
    agentResponse = End;
}

StkDialog::StkDialog(const QString &iconUrl, const QString &title, const QString &qmlViewUrl,
          const QList<StkMenuItem> &menuItems, QWidget *parent) :
    QDialog(parent)
{
    // Create QML View as central widget
    this->mView = new QDeclarativeView;
    this->mView->setSource(QUrl(qmlViewUrl));
    this->mView->setResizeMode(QDeclarativeView::SizeRootObjectToView);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(this->mView);
    setLayout(layout);
    // Find qml objects and connect signals
    QObject *object;
    QObject *root = this->mView->rootObject();
    // Main icon and title
    object = root->findChild<QObject*>("icon");
    if (object)
        object->setProperty("source", iconUrl);
    object = root->findChild<QObject*>("title");
    if (object)
        object->setProperty("text", title);
    // SIM Toolkit Menu
    object = root->findChild<QObject*>("menuView");
    if (object) {
        // set model "menuModel" for ListView "menuView"
        QDeclarativeContext *context = mView->rootContext();
        StkMenuModel * menuModel = new StkMenuModel();
        menuModel->setMenuItems(menuItems);
        context->setContextProperty("menuModel",menuModel);
        connect(root, SIGNAL(itemSelected(int)), this, SLOT(responseOkWithSelection(int)));
    }
    // End button
    object = root->findChild<QObject*>("endRect");
    if (object)
        connect(root, SIGNAL(endSession()), this, SLOT(responseEnd()));
    // Back button
    object = root->findChild<QObject*>("backRect");
    if (object)
        connect(root, SIGNAL(goBack()), this, SLOT(responseBack()));
    // Yes button
    object = root->findChild<QObject*>("yesRect");
    if (object)
        connect(root, SIGNAL(accepted()), this, SLOT(responseYes()));
    // No button
    object = root->findChild<QObject*>("noRect");
    if (object)
        connect(root, SIGNAL(rejected()), this, SLOT(responseNo()));
// #### TODO   connect(mStkWidget, SIGNAL(textEntered(QString)), this, SLOT(responseOkWithText(QString)));
    // default response: end session
    agentResponse = End;
}


