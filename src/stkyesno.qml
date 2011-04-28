import Qt 4.7
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
    signal rejected()
    onRejected: console.log("Rejected")
    signal endSession()
    onEndSession: console.log("End session")

    Label {
        id: title
        objectName: "title"
        text: "SIM Application Toolkit"
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: icon.right
        anchors.leftMargin: 10
        anchors.bottom: yesRect.top
        anchors.bottomMargin: 10
        anchors.right: endRect.left
        anchors.rightMargin: 10
        wrapMode: Text.WordWrap
        color: theme.dialogTitleFontColor
        font.pixelSize: theme.dialogTitleFontPixelSize
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
        id: endRect
        objectName: "endRect"
        width: 80
        height: 30
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        text: "End"
        onClicked: {
            view.endSession()
        }
    }

    Button {
        id: yesRect
        objectName: "yesRect"
        width: 80
        height: 30
        anchors.horizontalCenterOffset: -50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        text: "Yes"
        onClicked: {
            view.accepted()
        }
    }

    Button {
        id: noRect
        objectName: "noRect"
        width: 80
        height: 30
        anchors.horizontalCenterOffset: 50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        text: "No"
        onClicked: {
            view.rejected()
        }
    }

}



