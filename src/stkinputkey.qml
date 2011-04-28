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


    Label {
        id: title
        objectName: "title"
        text: "SIM Application Toolkit"
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: icon.right
        anchors.leftMargin: 10
        anchors.right: endRect.left
        anchors.rightMargin: 10
        anchors.bottom: editText.top
        anchors.bottomMargin: 10
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

    TextEntry {
        id: editText
        objectName: "editText"
        anchors.left: icon.right
        anchors.leftMargin: 10
        anchors.bottom: okRect.top
        anchors.bottomMargin: 10
        anchors.right: endRect.left
        anchors.rightMargin: 10
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
        id: backRect
        objectName: "backRect"
        width: 80
        height: 30
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        text: "Back"
        onClicked: {
            view.goBack()
        }
    }

    Button {
        id: okRect
        objectName: "okRect"
        width: 80
        height: 30
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        text: "Ok"
        onClicked: {
            view.accepted()
        }
    }

}



