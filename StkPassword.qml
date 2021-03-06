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
    \file StkPassword.qml
    \section StkPassword
    \brief Multiple char password input.

    \subsection Signals
    \li accepted()
    \li textEntered(string text)
    \li goBack()
    \li endSession()

    \subsection Objects
    - \b editText : Multiple char input.
      - Properties
        - text
        - isNumeric: false
        - hideTyping: true
        - minChars: -1
        - maxChars: -1
    - \b formatMsgBox : Format error dialog box.
      - Properties
        - title: "Attention"
        - text: ""
        - acceptButtonText: "Ok"
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
        console.log("Accepted");
        console.log("Text len: ", editText.text.length, ", bounds: [", editText.minChars, "..", editText.maxChars, "], numeric: ", editText.isNumeric);
        if (editText.minChars != -1 && editText.text.length < editText.minChars) {
            formatMsgBox.text = qsTr("You entered ") + editText.text.length + qsTr(" characters.") + "\n" +
            qsTr("Please enter at least ") + editText.minChars + qsTr(" characters.");
            formatMsgBox.show();
            return;
        }
        if (editText.maxChars != -1 && editText.text.length > editText.maxChars) {
            formatMsgBox.text = qsTr("You entered ") + editText.text.length + qsTr(" characters.") + "\n" +
            qsTr("Please enter no more than ") + editText.maxChars + qsTr(" characters.");
            formatMsgBox.show();
            return;
        }
        if (editText.isNumeric && !StkUiCheck.checkNumericString(editText.text)) {
            formatMsgBox.text = qsTr("Please enter numbers only");
            formatMsgBox.show();
            return;
        }
        view.textEntered(editText.text)
    }
    signal textEntered(string text)
    onTextEntered: console.log("Text entered: " + text)
    signal goBack()
    onGoBack: console.log("Go back")
    signal endSession()
    onEndSession: console.log("End session")

    panel.anchors.top: editText.bottom

    TextEntry {
        id: editText
        objectName: "editText"
        anchors.top: title.bottom
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        textInput.horizontalAlignment: TextInput.AlignHCenter
        textInput.focus: true
        textInput.echoMode: TextInput.Password
        property bool isNumeric: false
        property bool hideTyping: true
        property int minChars: -1
        property int maxChars: -1
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

    ModalMessageBox {
        id: formatMsgBox
        showAcceptButton: true
        showCancelButton: false
        fogClickable: false
        acceptButtonText: qsTr( "Ok")
    }

}





