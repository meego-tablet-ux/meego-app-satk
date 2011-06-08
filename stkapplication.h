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
#include "simif.h"
#include "stkif.h"

class StkApplication : public QApplication
{
    Q_OBJECT
public:
    explicit StkApplication(int &argc, char **argv, int version = QT_VERSION);
    ~StkApplication();

    bool initOfonoConnection(const QDBusConnection &connection, MgrIf *mgrIf);

    bool registerMgrPropertyChanged(MgrIf *mgrIf);
    bool registerSimPropertyChanged(SimIf *simIf);

    inline MgrIf *mgrIf()
    {
        return mMgrIf;
    }

    inline SimIf *simIf()
    {
        return mSimIf;
    }

    inline StkIf *stkIf()
    {
        return mStkIf;
    }

signals:

private:
    MgrIf *mMgrIf;
    SimIf *mSimIf;
    StkIf *mStkIf;
    const QDBusConnection *mConnection;

    // interfaces freed at destruction
    QList<SimIf*> mSimIfs;
    QList<StkIf*> mStkIfs;

    void deleteInterfaces();

private slots:
    void mgrPropertyChanged(const QString &property, const QDBusVariant &value);
    void simPropertyChanged(const QString &property, const QDBusVariant &value);


};

#endif // STKAPPLICATION_H
