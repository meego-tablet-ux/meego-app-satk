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


#ifndef SIMIMAGEPROVIDER_H
#define SIMIMAGEPROVIDER_H

#include <QDeclarativeImageProvider>
#include "simif.h"


class SimImageProvider : public QDeclarativeImageProvider
{
public:
    SimImageProvider(SimIf *simIf);
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);
private:
    SimIf *mSimIf;
};

#endif // SIMIMAGEPROVIDER_H
