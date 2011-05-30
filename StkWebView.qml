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
    \file StkWebView.qml
    \section StkWebView
    \brief Web browser box, dismissable.

    \subsection Signals
    \li accepted()

    \subsection Objects
    - \b browserView : Web browser view.
      - Properties
        - url:  "http://127.0.0.1/"
    - \b okRect : "Ok" button.
      - Signals
        - accepted()
      - Properties
        - text: "Ok"
*/

import Qt 4.7
import QtWebKit 1.0
import MeeGo.Components 0.1

StkView {
    id: view
    objectName: "view"

    signal accepted()
    onAccepted: console.log("Accepted")

    Flickable {
        id: browserView
        objectName: "browserView"
        anchors.top: title.bottom
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.bottom: okRect.top
        anchors.bottomMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        contentWidth: childrenRect.width
        contentHeight: childrenRect.height
        property alias url: browserContent.url
        WebView {
            id: browserContent
            objectName: "browserContent"
            preferredWidth: parent.width
            preferredHeight: parent.height
            url: "http://127.0.0.1/"
            onWidthChanged: browserView.contentWidth = width
            onHeightChanged: browserView.contentHeight = height
            onLoadFinished: browserView.contentY = -1 // redraw browserView
        }
    }

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



