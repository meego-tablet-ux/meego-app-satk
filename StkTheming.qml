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


import Qt 4.7
import MeeGo.Components 0.1

Item {
    /* references to the Meego default theme */
    Theme { id: theme }

    /* view properties */
    property int viewWidth: 480
    property int viewHeight: 640
    property string viewBackgroundColor: "#a0a0b0"

    /* title properties */
    property string titleFontColor: theme.dialogTitleFontColor
    property int titleFontPixelSize: theme.dialogTitleFontPixelSize

    /* panel properties */
    property int panelColumnWidth: 90
    property int panelLineHeight: 50
    property string panelBackgroundColor: "#808090"

    /* button properties */
    property int buttonWidth: 80
    property int buttonHeight: 40
    property int buttonFontPixelSize: theme.fontPixelSizeMediumLarge


    /* menu properties */
    property string menuItemFontColor: theme.contextMenuFontColor
    property int menuItemFontPixelSize: theme.fontPixelSizeMediumLarge
}
