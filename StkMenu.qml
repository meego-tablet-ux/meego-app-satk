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
    \file StkMenu.qml
    \section StkMenu
    \brief Menu list view.

    \subsection Signals
    \li itemSelected(int selection)
    \li goBack()
    \li endSession()

    \subsection Objects
    - \b menuView : Menu list view.
      - Signals
        - itemSelected(int selection)
      - Properties
        - menuModel
      - Delegate roles
        - title
        - icon
*/

import Qt 4.7
import MeeGo.Components 0.1

StkView {
    id: view
    objectName: "view"

    signal itemSelected(int selection)
    onItemSelected: console.log("Item selected: " + selection)
    signal goBack()
    onGoBack: console.log("Go back")
    signal endSession()
    onEndSession: console.log("End session")

    ListView {
        id: menuView
        objectName: "menuView"
        model: menuModel
        delegate: menuDelegate
        highlight: Rectangle {
            color: theme.fontColorHighlight
            width: menuView.width
        }
        highlightFollowsCurrentItem: true
        anchors.top: icon.bottom
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.right: panel.left
        anchors.rightMargin: 10
        signal itemSelected(int selection)
        onItemSelected: {
            currentIndex = selection;
            view.itemSelected(selection)
        }
    }

    Component {
        id: menuDelegate
        Row {
            spacing: 10
            Image {
                width: 32
                height: 32
                anchors.verticalCenter: parent.verticalCenter
                source: icon
                MouseArea {
                    anchors.fill: parent
                    onClicked: menuView.itemSelected(index)
                }
            }
            Text {
                height: 48
                verticalAlignment: Text.AlignVCenter
                color: stkTheme.menuItemFontColor
                font.pixelSize: stkTheme.menuItemFontPixelSize
                text: title
                MouseArea {
                    width: menuView.width
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.bottom: parent.bottom
                    onClicked: menuView.itemSelected(index)
                }
            }
        }
    }

}



