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
        clip: true
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
}



