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


/*!
    \file StkMessage.qml
    \section StkMessage
    \brief Message box, non-dismissable.

    \subsection Signals
    \li endSession()

*/

import Qt 4.7
import MeeGo.Components 0.1

StkView {
    id: view
    objectName: "view"

    signal endSession()
    onEndSession: console.log("End session")
}



