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
    \file StkPanel.qml
    \section StkPanel
    \brief Control panel providing "End session" and "Go back" buttons for SIM Toolkit.

    \subsection Signals
    \li endSession()
    \li goBack()

    \subsection Properties
    \li bool showEndButton: true
    \li bool showBackButton: true

    \subsection Objects
    - \b endRect : "End" button
      - Signals
        - endSession()
      - Properties
        - text: "End"
    - \b backRect : "Back" button
      - Signals
        - goBack()
      - Properties
        - text: "Back"
*/

import Qt 4.7
import MeeGo.Components 0.1

Rectangle {
    id: container
    width: stkTheme.panelColumnWidth

    StkTheming { id: stkTheme }
    color: stkTheme.panelBackgroundColor

    property alias showEndButton: endRect.visible
    property alias showBackButton: backRect.visible

    signal goBack()
    onGoBack: console.log("StkPanel: Go back")
    signal endSession()
    onEndSession: console.log("StkPanel: End session")

    StkButton {
        id: endRect
        objectName: "endRect"
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr( "End")
        onClicked: {
            container.endSession()
        }
    }

    StkButton {
        id: backRect
        objectName: "backRect"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr( "Back")
        onClicked: {
            container.goBack()
        }
    }

}
