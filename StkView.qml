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
    \file StkView.qml
    \section StkView
    \brief Multiple char input.

    \subsection Signals
    \li accepted()
    \li rejected()
    \li textEntered(string text)
    \li itemSelected(int selection)
    \li goBack()
    \li endSession()

    \subsection Properties
    \li bool showEndButton: true
    \li bool showBackButton: true

    \subsection Objects
    - \b title : Title bar.
      - Properties
        - text: "SIM Application Toolkit"
    - \b icon : Main icon.
      - Properties
        - source
    - \b panel : StkPanel
      - Signals
        - goBack()
        - endSession()
      - Properties
        - showBackButton: true
        - showEndButton: true
*/

import Qt 4.7
import MeeGo.Components 0.1

Rectangle {
    id: container

    property alias showEndButton: panel.showEndButton
    property alias showBackButton: panel.showBackButton

    property alias theme: theme
    property alias stkTheme: stkTheme

    property alias title: title
    property alias icon: icon
    property alias panel: panel

    width: stkTheme.viewWidth
    height: stkTheme.viewHeight

    Theme { id: theme }
    StkTheming { id: stkTheme }
    color: stkTheme.viewBackgroundColor

    signal accepted()
    onAccepted: console.log("StkView Accepted")
    signal rejected()
    onRejected: console.log("StkView Rejected")
    signal textEntered(string text)
    onTextEntered: console.log("StkView Text entered: " + text)
    signal itemSelected(int selection)
    onItemSelected: console.log("StkView Item selected: " + selection)
    signal goBack()
    onGoBack: console.log("StkView Go back")
    signal endSession()
    onEndSession: console.log("StkView End session")

    StkPanel {
        id: panel
        objectName: "panel"
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        onGoBack: view.goBack();
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
        anchors.right: parent.right
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

}
