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


#ifndef STKAPPLICATION_H
#define STKAPPLICATION_H

#include <QApplication>
#include "mgrif.h"
#include "modemif.h"
#include "simif.h"
#include "stkif.h"
#include "stkagentservice.h"
#include "stkagentifadaptor.h"

class StkApplication : public QApplication
{
    Q_OBJECT
public:
    explicit StkApplication(int &argc, char **argv, int version = QT_VERSION);
    ~StkApplication();

    bool initOfonoConnection(bool agentMode);

    inline MgrIf *mgrIf()
    {
        return mMgrIf;
    }

    inline ModemIf *modemIf()
    {
        return mModemIf;
    }

    inline SimIf *simIf()
    {
        return mSimIf;
    }

    inline StkIf *stkIf()
    {
        return mStkIf;
    }

    inline StkAgentService *stkAgentService()
    {
        return mStkAgentService;
    }

    inline bool agentServiceRegistered()
    {
        return mAgentServiceRegistered;
    }

signals:

private:
    bool mAgentServiceRegistered;
    bool mAgentMode;
    // DBus interfaces
    MgrIf *mMgrIf;
    ModemIf *mModemIf;
    SimIf *mSimIf;
    StkIf *mStkIf;
    // interfaces explicitly freed at destruction
    QList<ModemIf*> mModemIfs;
    QList<SimIf*> mSimIfs;
    QList<StkIf*> mStkIfs;
    StkAgentService *mStkAgentService;
    StkAgentIfAdaptor *mStkAgentIfAdaptor;

    // methods
    void resetInterfaces();
    void deleteInterfaces();

    bool registerModemMgrChanges();
    bool registerModemPropertyChanged();
    bool registerSimPropertyChanged();

    bool registerStkAgentService();
    void unRegisterStkAgentService();

private slots:
    void mgrModemAdded(const QDBusObjectPath &in0, const QVariantMap &in1);
    void mgrModemRemoved(const QDBusObjectPath &in0);
    void modemPropertyChanged(const QString &property, const QDBusVariant &value);
    void simPropertyChanged(const QString &property, const QDBusVariant &value);
};

#endif // STKAPPLICATION_H
