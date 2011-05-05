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

#include "stkdefines.h"
#include "stkmenuitem.h"
#include "simimageprovider.h"

class StkDialog : public QDialog
{
    Q_OBJECT
public:
    explicit StkDialog(SimImageProvider * imageProvider, const QString &iconUrl,
                       const QString &title, const QString &qmlViewUrl, QWidget *parent = 0);

    inline AgentResponse getAgentResponse()
    {
        return agentResponse;
    }

    inline QVariant getResponseData()
    {
        return responseData;
    }

    inline void setDefaultText(const QString &defaultText)
    {
        mDefaultText = defaultText;
    }

    inline void setNumeric(const bool numeric)
    {
        mNumeric = numeric;
    }

    inline void setHideTyping(const bool hideTyping)
    {
        mHideTyping = hideTyping;
    }

    inline void setCharBounds(const int minChars, const int maxChars)
    {
        mMinChars = minChars;
        mMaxChars = maxChars;
    }

    inline void setMenuItems(const QList<StkMenuItem> &menuItems)
    {
        mMenuItems = menuItems;
    }

    inline void setSelection(const int selection)
    {
        mSelection = selection;
    }

    inline void setLoopTone(const bool loopTone)
    {
        mLoopTone = loopTone;
    }

private:
    // result data, inline getters
    AgentResponse agentResponse;
    QVariant responseData;
    // QML view specifics, inline setters
    // for "editText" items
    QString mDefaultText;
    bool mNumeric;
    bool mHideTyping;
    int mMinChars;
    int mMaxChars;
    // for "menuView" items
    QList<StkMenuItem> mMenuItems;
    int mSelection;
    // for "audioTone" items
    bool mLoopTone;
    // QML view support
    QDeclarativeView *mView;
    // constructor parameters
    SimImageProvider * mImageProvider;
    QString mIconUrl;
    QString mTitle;
    QString mQmlViewUrl;

public:
    void initView();

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
