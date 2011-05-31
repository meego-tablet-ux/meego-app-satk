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

StkView {
    id: view
    objectName: "view"

    signal accepted()
    onAccepted: console.log("Accepted")
    signal rejected()
    onRejected: console.log("Rejected")
    signal endSession()
    onEndSession: console.log("End session")


    title.anchors.top: icon.bottom
    title.anchors.left: parent.left
    title.anchors.bottom: yesRect.top
    title.anchors.bottomMargin:10

    StkButton {
        id: yesRect
        objectName: "yesRect"
        anchors.horizontalCenterOffset: - (10 + width / 2)
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        text: qsTr( "Yes")
        onClicked: {
            view.accepted()
        }
    }

    StkButton {
        id: noRect
        objectName: "noRect"
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



