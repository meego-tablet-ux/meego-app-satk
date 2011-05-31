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

StkView {
    id: view
    objectName: "view"

    signal accepted()
    onAccepted: console.log("Accepted")
    signal endSession()
    onEndSession: console.log("End session")

    StkButton {
        id: okRect
        objectName: "okRect"
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



