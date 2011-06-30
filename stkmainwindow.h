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


#ifndef STKMAINWINDOW_H
#define STKMAINWINDOW_H

#include <QMainWindow>
#include <QtDeclarative/QDeclarativeView>
#include "stkif.h"
#include "simif.h"
#include "stkagentservice.h"
#include "stkofonoproperties.h"

class StkMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit StkMainWindow(StkIf *stkIf, SimIf *simIf,
                           StkAgentService *stkAgentService, QWidget *parent = 0);
    ~StkMainWindow();

signals:

private:
    StkIf *mStkIf;
    SimIf *mSimIf;
    StkAgentService *mStkAgentService;
    StkOfonoProperties *mStkProperties;
    QDeclarativeView *mView;

    void createMainView();

private slots:
    void onEndSession();
    void responseOkWithSelection(int selection);
    void stkPropertyChanged(const QString &property, const QDBusVariant &value);
};

#endif // STKMAINWINDOW_H
