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
    \file StkInputKey.qml
    \section StkInputKey
    \brief Single char input.

    \subsection Signals
    \li accepted()
    \li textEntered(string text)
    \li goBack()
    \li endSession()

    \subsection Objects
    - \b editText : Single char input.
      - Properties
        - text
        - isNumeric: false
    - \b okRect : "Ok" button.
      - Signals
        - accepted()
      - Properties
        - text: "Ok"
*/

import Qt 4.7
import MeeGo.Components 0.1
import "qrc:/StkUiCheck.js" as StkUiCheck

StkView {
    id: view
    objectName: "view"

    signal accepted()
    onAccepted: {
        console.log("Accepted")
        view.textEntered(editText.text)
    }
    signal textEntered(string text)
    onTextEntered: console.log("Text entered: " + text)
    signal goBack()
    onGoBack: console.log("Go back")
    signal endSession()
    onEndSession: console.log("End session")

    panel.anchors.top: title.bottom

    TextEntry {
        id: editText
        objectName: "editText"
        width: 120
        height: 80
        anchors.top: title.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        textInput.horizontalAlignment: TextInput.AlignHCenter
        textInput.focus: true
        textInput.font.pixelSize: 48
        property bool isNumeric: false
        onTextChanged: {
            if (text.length > 0) {
                text = text.charAt(text.length-1);
                if (isNumeric && !StkUiCheck.checkNumericChar(text))
                    text = "";
            }
        }
    }

    StkButton {
        id: okRect
        objectName: "okRect"
        anchors.top: editText.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr( "Ok")
        onClicked: {
            view.accepted()
        }
    }

}



