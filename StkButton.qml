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
    \file StkButton.qml
    \section StkButton
    \brief Overrides default Meego Button geometry
*/

import Qt 4.7
import MeeGo.Components 0.1

Button {
    width: stkTheme.buttonWidth
    height: stkTheme.buttonHeight
    font.pixelSize: stkTheme.buttonFontPixelSize
}
