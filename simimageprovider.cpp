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


#include "simimageprovider.h"
#include "stkofonoutils.h"

SimImageProvider::SimImageProvider(SimIf *simIf) :
    QDeclarativeImageProvider (QDeclarativeImageProvider::Pixmap)
{
    mSimIf = simIf;
}


QPixmap SimImageProvider::requestPixmap(const QString &id, QSize *size,
                                        const QSize &requestedSize)
{
qDebug() << "request pixmap id: " << id << " char: " << id.at(0);
    QPixmap pixmap = StkOfonoUtils::findIcon(mSimIf, (uchar)(id.at(0).cell() - '0'));
qDebug() << "found pixmap " << pixmap.width() << "x" << pixmap.height();
    if (requestedSize.isValid())
        pixmap = pixmap.scaled(requestedSize);
    if (size)
        *size = pixmap.size();
qDebug() << "returning pixmap " << pixmap.width() << "x" << pixmap.height();
    return pixmap;
}
