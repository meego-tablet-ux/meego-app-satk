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
    \file StkPopup.qml
    \section StkPopup
    \brief Message box, dismissable.

    \subsection Signals
    \li accepted()
    \li goBack()
    \li endSession()

    \subsection Objects
    - \b okRect : "Ok" button.
      - Signals
        - accepted()
      - Properties
        - text: "Ok"
*/

import Qt 4.7
import MeeGo.Components 0.1

StkView {
    id: view
    objectName: "view"

    signal accepted()
    onAccepted: console.log("Accepted")
    signal goBack()
    onGoBack: console.log("Go back")
    signal endSession()
    onEndSession: console.log("End session")

    Button {
        id: okRect
        objectName: "okRect"
        width: stkTheme.buttonWidth
        height: stkTheme.buttonHeight
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        text: qsTr( "Ok")
        onClicked: {
            view.accepted()
        }
    }

}



