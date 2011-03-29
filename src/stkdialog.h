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


#ifndef STKDIALOG_H
#define STKDIALOG_H

#include <QtDebug>

#include <QtGui/QDialog>
#include <QtCore/QString>
#include <QtCore/QVariant>
#include <QtDeclarative/QDeclarativeView>
#include <QList>

#include "stkwidget.h"
#include "stkdefines.h"
#include "stkmenuitem.h"

class StkDialog : public QDialog
{
    Q_OBJECT
public:
    explicit StkDialog(StkWidget * stkWidget, QWidget *parent = 0);
    explicit StkDialog(const QString &iconUrl, const QString &title, const QString &qmlViewUrl,
                       const QList<StkMenuItem> &menuItems = QList<StkMenuItem>(), QWidget *parent = 0);

    inline AgentResponse getAgentResponse()
    {
        return agentResponse;
    }

    inline QVariant getResponseData()
    {
        return responseData;
    }


private:
    AgentResponse agentResponse;
    QVariant responseData;
    StkWidget * mStkWidget;
    QDeclarativeView *mView;

public slots:
    inline void responseYes()
    {
        agentResponse = Yes;
        accept();
    }

    inline void responseNo()
    {
        agentResponse = No;
        reject();
    }

    inline void responseOkWithSelection(int selection)
    {
        agentResponse = Ok;
        responseData = selection;
        accept();
    }

    inline void responseOkWithText(QString text)
    {
        agentResponse = Ok;
        responseData = text;
        accept();
    }

    inline void responseBack()
    {
        agentResponse = Back;
        reject();
    }

    inline void responseEnd()
    {
        agentResponse = End;
        reject();
    }

};

#endif // STKDIALOG_H
