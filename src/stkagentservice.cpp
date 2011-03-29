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


#include "stkagentservice.h"

/* Qt includes */
#include <QtDebug>
#include <QtGui/QApplication>
#include <QIcon>

/* oFono SIM Toolkit utilities*/
#include "stkofonoutils.h"

/* SIM Toolkit widgets */
#include "stkmenumodel.h"
/* SIM Toolkit generic container dialog */
#include "stkdialog.h"

/* Fallback return values */
#define FALLBACK_BOOL       false
#define FALLBACK_UCHAR      255
#define FALLBACK_QSTRING    ""


StkAgentService::StkAgentService(QObject *parent) :
    QObject(parent)
{
}


void StkAgentService::Cancel()
{
    // handle method call org.ofono.SimToolkitAgent.Cancel
qDebug() << "Cancel" ;
    closeLastWidget();
}


bool StkAgentService::ConfirmCallSetup(const QString &info, uchar icon)
{
    // handle method call org.ofono.SimToolkitAgent.ConfirmCallSetup
    bool out0 = FALLBACK_BOOL;
qDebug() << "ConfirmCallSetup: " << info << "(" << icon << ")";
    closeLastWidget();
    StkDialog dlg(StkOfonoUtils::findIconUrl(icon),info,"qrc:/stkyesno.qml");
    dlg.exec();
    AgentResponse ret = dlg.getAgentResponse();
    switch (ret) {
    case Yes:
        out0 = true;
        break;
    case No:
        out0 = false;
        break;
    case End:
        connection().send(message().createErrorReply(STK_ERR_END,""));
        break;
    default:
        Q_ASSERT(false);
    }
    return out0;
}


bool StkAgentService::ConfirmLaunchBrowser(const QString &info, uchar icon, const QString &url)
{
    // #### TODO #### launch browser with url parameter
    // handle method call org.ofono.SimToolkitAgent.ConfirmLaunchBrowser
    bool out0 = FALLBACK_BOOL;
qDebug() << "ConfirmLaunchBrowser: " << info << "(" << icon << ")" << " -- url: " << url;
    closeLastWidget();
    StkDialog dlg(StkOfonoUtils::findIconUrl(icon),info,"qrc:/stkyesno.qml");
    dlg.exec();
    AgentResponse ret = dlg.getAgentResponse();
    switch (ret) {
    case Yes:
        out0 = true;
        break;
    case No:
        out0 = false;
        break;
    case End:
        connection().send(message().createErrorReply(STK_ERR_END,""));
        break;
    default:
        Q_ASSERT(false);
    }
    return out0;
}


void StkAgentService::DisplayActionInformation(const QString &text, uchar icon)
{
    // handle method call org.ofono.SimToolkitAgent.DisplayActionInformation
qDebug() << "DisplayActionInformation: " << text << "(" << icon << ")";
    closeLastWidget();
    StkDialog *dlg = new StkDialog(StkOfonoUtils::findIconUrl(icon),text,"qrc:/stkmessage.qml");
    widgetStack.append(dlg);
    dlg->show();
}


void StkAgentService::DisplayText(const QString &title, uchar icon, bool urgent)
{
    // #### TODO #### blocking message dialog if urgent ?
    // handle method call org.ofono.SimToolkitAgent.DisplayText
qDebug() << "DisplayText: " << title << "(" << icon << ")" << " urgent: " << urgent;
    closeLastWidget();
    StkDialog *dlg = new StkDialog(StkOfonoUtils::findIconUrl(icon),title,"qrc:/stkmessage.qml");
    widgetStack.append(dlg);
    dlg->show();
}


void StkAgentService::LoopTone(const QString &tone, const QString &text, uchar icon)
{
    // #### TODO #### loop playing tone
    // handle method call org.ofono.SimToolkitAgent.LoopTone
qDebug() << "LoopTone: " << tone << " : " << text << "(" << icon << ")";
    closeLastWidget();
    StkDialog *dlg = new StkDialog(StkOfonoUtils::findIconUrl(icon),text + "(playing: " + tone + ")","qrc:/stkmessage.qml");
    widgetStack.append(dlg);
    dlg->show();
}


void StkAgentService::PlayTone(const QString &tone, const QString &text, uchar icon)
{
    // #### TODO #### play tone, block while playing
    // handle method call org.ofono.SimToolkitAgent.PlayTone
qDebug() << "PlayTone: " << tone << " : " << text << "(" << icon << ")";
    closeLastWidget();
    StkDialog dlg(StkOfonoUtils::findIconUrl(icon),text + "(playing: " + tone + ")","qrc:/stkpopup.qml");
    dlg.exec();
}


void StkAgentService::Release()
{
    // handle method call org.ofono.SimToolkitAgent.Release
qDebug() << "Release" ;
    while (closeLastWidget()) {}
    QApplication::instance()->exit();
}


bool StkAgentService::RequestConfirmation(const QString &title, uchar icon)
{
    // handle method call org.ofono.SimToolkitAgent.RequestConfirmation
    bool out0 = FALLBACK_BOOL;
qDebug() << "RequestConfirmation: " << title << "(" << icon << ")";
    closeLastWidget();
    StkDialog dlg(StkOfonoUtils::findIconUrl(icon),title,"qrc:/stkpopup.qml");
    dlg.exec();
    AgentResponse ret = dlg.getAgentResponse();
    switch (ret) {
    case Yes:
        out0 = true;
        break;
    case No:
        out0 = false;
        break;
    case Back:
        connection().send(message().createErrorReply(STK_ERR_BACK,""));
        break;
    case End:
        connection().send(message().createErrorReply(STK_ERR_END,""));
        break;
    default:
        Q_ASSERT(false);
    }
    return out0;
}


QString StkAgentService::RequestDigit(const QString &title, uchar icon)
{
    // handle method call org.ofono.SimToolkitAgent.RequestDigit
    QString out0 = FALLBACK_QSTRING;
qDebug() << "RequestDigit: " << title << "(" << icon << ")";
    closeLastWidget();
    /* #### TODO #### handle numeric and boundaries constraints
    StkDialog dlg(new StkInputKey(StkOfonoUtils::findIcon(icon),title));*/
    StkDialog dlg(StkOfonoUtils::findIconUrl(icon),title,"qrc:/stkinputkey.qml");
    dlg.exec();
    AgentResponse ret = dlg.getAgentResponse();
    switch (ret) {
    case Ok:
        out0 = dlg.getResponseData().toString();
        break;
    case Back:
        connection().send(message().createErrorReply(STK_ERR_BACK,""));
        break;
    default:
        Q_ASSERT(false);
    }
    return out0;
}


QString StkAgentService::RequestDigits(const QString &title, uchar icon, const QString &defaultValue, uchar minChars, uchar maxChars, bool hideTyping)
{
    // handle method call org.ofono.SimToolkitAgent.RequestDigits
    QString out0 = defaultValue;
qDebug() << "RequestDigits: " << title << "(" << icon << ")" << " (" << defaultValue << ") [" << minChars << ".." << maxChars << "] passwd:" << hideTyping;
    closeLastWidget();
    /* #### TODO #### handle numeric and boundaries constraints
    StkInputText * inputText = new StkInputText(StkOfonoUtils::findIcon(icon),title);
    inputText->setDefaultText(defaultValue);
    inputText->setCharBounds(minChars,maxChars);
    inputText->setHideTyping(hideTyping);
    inputText->setNumeric(true);
    StkDialog dlg(inputText);*/
    StkDialog dlg(StkOfonoUtils::findIconUrl(icon),title,"qrc:/stkinputtext.qml",defaultValue);
    dlg.exec();
    AgentResponse ret = dlg.getAgentResponse();
    switch (ret) {
    case Ok:
        out0 = dlg.getResponseData().toString();
        break;
    case Back:
        connection().send(message().createErrorReply(STK_ERR_BACK,""));
        break;
    default:
        Q_ASSERT(false);
    }
    return out0;
}


QString StkAgentService::RequestInput(const QString &title, uchar icon, const QString &defaultValue, uchar minChars, uchar maxChars, bool hideTyping)
{
    // handle method call org.ofono.SimToolkitAgent.RequestInput
    QString out0 = defaultValue;
qDebug() << "RequestInput: " << title << "(" << icon << ")" << " (" << defaultValue << ") [" << minChars << ".." << maxChars << "] passwd:" << hideTyping;
    closeLastWidget();
    /* #### TODO #### handle numeric and boundaries constraints
    StkInputText * inputText = new StkInputText(StkOfonoUtils::findIcon(icon),title);
    inputText->setDefaultText(defaultValue);
    inputText->setCharBounds(minChars,maxChars);
    inputText->setHideTyping(hideTyping);
    inputText->setNumeric(false);
    StkDialog dlg(inputText);*/
    StkDialog dlg(StkOfonoUtils::findIconUrl(icon),title,"qrc:/stkinputtext.qml",defaultValue);
    dlg.exec();
    AgentResponse ret = dlg.getAgentResponse();
    switch (ret) {
    case Ok:
        out0 = dlg.getResponseData().toString();
        break;
    case Back:
        connection().send(message().createErrorReply(STK_ERR_BACK,""));
        break;
    default:
        Q_ASSERT(false);
    }
    return out0;
}


QString StkAgentService::RequestKey(const QString &title, uchar icon)
{
    // handle method call org.ofono.SimToolkitAgent.RequestKey
    QString out0 = FALLBACK_QSTRING;
qDebug() << "RequestKey: " << title << "(" << icon << ")";
    closeLastWidget();
    /* #### TODO #### handle numeric and boundaries constraints
    StkDialog dlg(new StkInputKey(StkOfonoUtils::findIcon(icon),title));*/
    StkDialog dlg(StkOfonoUtils::findIconUrl(icon),title,"qrc:/stkinputkey.qml");
    dlg.exec();
    AgentResponse ret = dlg.getAgentResponse();
    switch (ret) {
    case Ok:
        out0 = dlg.getResponseData().toString();
        break;
    case Back:
        connection().send(message().createErrorReply(STK_ERR_BACK,""));
        break;
    default:
        Q_ASSERT(false);
    }
    return out0;
}


uchar StkAgentService::RequestSelection(const QString &title, uchar icon, OfonoMenuList items, short defaultValue)
{
    // handle method call org.ofono.SimToolkitAgent.RequestSelection
    uchar out0 = FALLBACK_UCHAR;
qDebug() << "RequestSelection: " << title << "(" << icon << ")" << " default: " << defaultValue;
    closeLastWidget();
     QList<StkMenuItem> dlgitems;
    foreach (const OfonoMenuEntry entry, items)
        dlgitems.append(StkMenuItem(StkOfonoUtils::findIconUrl(entry.icon), entry.label));
    StkDialog dlg(StkOfonoUtils::findIconUrl(icon),title,"qrc:/stkmenu.qml","",dlgitems,int(defaultValue));
    dlg.exec();
    AgentResponse ret = dlg.getAgentResponse();
    switch (ret) {
    case Ok:
        out0 = (uchar)dlg.getResponseData().toInt();
       break;
    case Back:
        connection().send(message().createErrorReply(STK_ERR_BACK,""));
        break;
    case End:
        connection().send(message().createErrorReply(STK_ERR_END,""));
        break;
    default:
        Q_ASSERT(false);
    }
    return out0;
}


/* private functions */

bool StkAgentService::closeLastWidget()
{
    if (!widgetStack.isEmpty()) {
        QWidget * widget = widgetStack.takeLast();
qDebug() << "closing widget: " << widget;
        widget->close();
        delete widget;
    }
    return !widgetStack.isEmpty();
}
