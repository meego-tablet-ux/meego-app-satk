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


#include "stkapplication.h"
#include "stkofonoutils.h"


StkApplication::StkApplication(int &argc, char **argv, int version) :
    QApplication(argc, argv, version)
{
    mMgrIf = NULL;
    mSimIf = NULL;
    mStkIf = NULL;
    mConnection = NULL;
}

StkApplication::~StkApplication()
{
    // only the interfaces lists were allocated here
    deleteInterfaces();
}

void StkApplication::deleteInterfaces()
{
    // delete all org.ofono.SimToolkit interfaces
    while (!mStkIfs.isEmpty()) {
        delete mStkIfs.first();
        mStkIfs.removeFirst();
    }
    // delete all org.ofono.SimManager interfaces
    while (!mSimIfs.isEmpty()) {
        delete mSimIfs.first();
        mSimIfs.removeFirst();
    }
}

bool StkApplication::initOfonoConnection(const QDBusConnection &connection, MgrIf *mgrIf)
{
    mMgrIf = NULL;
    mSimIf = NULL;
    mStkIf = NULL;
    mConnection = NULL;
    deleteInterfaces();
    mConnection = &connection;
    mMgrIf = mgrIf;
    // find org.ofono.SimManager interfaces for all modems
    mSimIfs = StkOfonoUtils::findSimInterfaces(*mConnection, mMgrIf);
    if (mSimIfs.isEmpty()) {
        registerMgrPropertyChanged(mMgrIf);
        return false;
    }
    mSimIf = mSimIfs.first();
    // find org.ofono.SimToolkit interfaces for all modems
    mStkIfs = StkOfonoUtils::findSimToolkitInterfaces(*mConnection, mMgrIf);
    if (mStkIfs.isEmpty()) {
        registerMgrPropertyChanged(mMgrIf);
        return false;
    }
    mStkIf = mStkIfs.first();
    return true;
}

bool StkApplication::registerMgrPropertyChanged(MgrIf *mgrIf)
{
    mMgrIf = mgrIf;
    // Connect mgrIf signals
    return connect(mMgrIf, SIGNAL(PropertyChanged(QString, QDBusVariant)), this, SLOT(mgrPropertyChanged(QString, QDBusVariant)));
}

bool StkApplication::registerSimPropertyChanged(SimIf *simIf)
{
    mSimIf = simIf;
    // Connect simIf signals
    return connect(mSimIf, SIGNAL(PropertyChanged(QString, QDBusVariant)), this, SLOT(simPropertyChanged(QString, QDBusVariant)));
}

void StkApplication::mgrPropertyChanged(const QString &property, const QDBusVariant &value)
{
    qDebug() << "mgrPropertyChanged: " << property << " variant string : " << value.variant().toString();
}

void StkApplication::simPropertyChanged(const QString &property, const QDBusVariant &value)
{
    qDebug() << "mgrPropertyChanged: " << property << " variant string : " << value.variant().toString();
}
