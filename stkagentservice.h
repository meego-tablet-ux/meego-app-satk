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


#ifndef STKAGENTSERVICE_H
#define STKAGENTSERVICE_H

#include <QtCore/QObject>
#include <QList>
#include <QWidget>
#include <QtDBus>
#include "ofonodbustypes.h"
#include "simif.h"
#include "stkdialog.h"

class StkAgentService : public QObject, protected QDBusContext
{
    Q_OBJECT
public:
    explicit StkAgentService(SimIf * simIf, QObject *parent = 0);

public: // PROPERTIES
    inline bool exitOnRelease()
    {
        return mExitOnRelease;
    }

    inline void setExitOnRelease(bool exitOnRelease)
    {
        mExitOnRelease = exitOnRelease;
    }

public Q_SLOTS: // METHODS
    void Cancel();
    bool ConfirmCallSetup(const QString &info, uchar icon);
    bool ConfirmLaunchBrowser(const QString &info, uchar icon, const QString &url);
    bool ConfirmOpenChannel(const QString &info, uchar icon);
    void DisplayAction(const QString &text, uchar icon);
    void DisplayActionInformation(const QString &text, uchar icon);
    void DisplayText(const QString &title, uchar icon, bool urgent);
    void LoopTone(const QString &tone, const QString &text, uchar icon);
    void PlayTone(const QString &tone, const QString &text, uchar icon);
    void Release();
    bool RequestConfirmation(const QString &title, uchar icon);
    QString RequestDigit(const QString &title, uchar icon);
    QString RequestDigits(const QString &title, uchar icon, const QString &defaultValue, uchar minChars, uchar maxChars, bool hideTyping);
    QString RequestInput(const QString &title, uchar icon, const QString &defaultValue, uchar minChars, uchar maxChars, bool hideTyping);
    QString RequestKey(const QString &title, uchar icon);
    uchar RequestSelection(const QString &title, uchar icon, OfonoMenuList items, short defaultValue);
Q_SIGNALS: // SIGNALS

private:
    // true only on "End Session" from main menu window.
    bool mExitOnRelease;
    // Sim Interface for GetIcon API
    SimIf *mSimIf;
    // stack non modal dialogs to close on cancel
    QList<QWidget*> mWidgetStack;
    // create a new dialog and push it on the widget stack
    StkDialog * addNewWidget(const QString &info, uchar icon, const QString &qmlViewUrl);
    // close last widget, delete it, return true if stack non-empty afterwards
    bool closeLastWidget();
};

#endif // STKAGENTSERVICE_H
