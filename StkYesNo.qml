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
    \file StkYesNo.qml
    \section StkYesNo
    \brief Message box, accept / reject.

    \subsection Signals
    \li accepted()
    \li rejected()
    \li goBack()
    \li endSession()

    \subsection Objects
    - \b title : Title bar.
      - Properties
        - text: "SIM Application Toolkit"
    - \b icon : Main icon.
      - Properties
        - source
    - \b yesRect : "Yes" button.
      - Signals
        - accepted()
      - Properties
        - text: "Yes"
    - \b noRect : "No" button.
      - Signals
        - rejected()
      - Properties
        - text: "No"
*/

import Qt 4.7
import MeeGo.Components 0.1

Rectangle {
    id: view
    objectName: "view"
    width: stkTheme.viewWidth
    height: stkTheme.viewHeight

    Theme { id: theme }
    StkTheming { id: stkTheme }
    color: stkTheme.viewBackgroundColor

    signal accepted()
    onAccepted: console.log("Accepted")
    signal rejected()
    onRejected: console.log("Rejected")
    signal endSession()
    onEndSession: console.log("End session")

    StkPanel {
        id: panel
        objectName: "panel"
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        onEndSession: view.endSession();
    }

    Label {
        id: title
        objectName: "title"
        text: "SIM Application Toolkit"
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: icon.right
        anchors.leftMargin: 10
        anchors.bottom: yesRect.top
        anchors.bottomMargin: 10
        anchors.right: panel.left
        anchors.rightMargin: 10
        wrapMode: Text.WordWrap
        color: stkTheme.titleFontColor
        font.pixelSize: stkTheme.titleFontPixelSize
    }

    Image {
        id: icon
        objectName: "icon"
        width: 64
        height: 64
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
    }

    Button {
        id: yesRect
        objectName: "yesRect"
        width: stkTheme.buttonWidth
        height: stkTheme.buttonHeight
        anchors.horizontalCenterOffset: - (10 + width / 2)
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        text: qsTr( "Yes")
        onClicked: {
            view.accepted()
        }
    }

    Button {
        id: noRect
        objectName: "noRect"
        width: stkTheme.buttonWidth
        height: stkTheme.buttonHeight
        anchors.horizontalCenterOffset: 10 + width / 2
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        text: qsTr( "No")
        onClicked: {
            view.rejected()
        }
    }

}



