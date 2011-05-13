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
    \file StkPlaySound.qml
    \section StkPlaySound
    \brief Message box, playing audio tone, dismissable.

    \subsection Signals
    \li accepted()
    \li endSession()

    \subsection Objects
    - \b title : Title bar.
      - Properties
        - text: "SIM Application Toolkit"
    - \b icon : Main icon.
      - Properties
        - source
    - \b okRect : "Ok" button.
      - Signals
        - accepted()
      - Properties
        - text: "Ok"
    - \b audioTone
      - Properties
        - source: "qrc:/audio/error.wav"
        - loops: SoundEffect.Infinite
*/

import Qt 4.7
import QtMultimediaKit 1.1
import MeeGo.Components 0.1

Rectangle {
    id: view
    objectName: "view"
    width: 480
    height: 320

    Theme { id: theme }
    color: theme.dialogBackgroundColor

    signal accepted()
    onAccepted: console.log("Accepted")
    signal endSession()
    onEndSession: console.log("End session")

    StkPanel {
        id: panel
        objectName: "panel"
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        showBackButton:false
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
        anchors.bottom: okRect.top
        anchors.bottomMargin: 10
        anchors.right: panel.left
        anchors.rightMargin: 10
        wrapMode: Text.WordWrap
        color: theme.dialogTitleFontColor
        font.pixelSize: theme.fontPixelSizeLarge
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
        id: okRect
        objectName: "okRect"
        width: 80
        height: 30
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        text: qsTr( "Ok")
        onClicked: {
            view.accepted()
        }
    }

    SoundEffect {
        id: audioTone
        objectName: "audioTone"
        source: "qrc:/audio/error.wav"
        loops: SoundEffect.Infinite
    }

}



