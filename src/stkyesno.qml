import Qt 4.7

Rectangle {
    id: view
    objectName: "view"
    width: 480
    height: 320
    color: "#20400080"

    signal accepted()
    onAccepted: console.log("Accepted")
    signal rejected()
    onRejected: console.log("Rejected")
    signal endSession()
    onEndSession: console.log("End session")

    Text {
        id: title
        objectName: "title"
        text: "SIM Application Toolkit"
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: icon.right
        anchors.leftMargin: 10
    }

    Image {
        id: icon
        objectName: "icon"
        width: 64
        height: 64
        sourceSize.height: 32
        sourceSize.width: 32
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
    }

    Rectangle {
        id: endRect
        objectName: "endRect"
        x: 380
        width: 80
        height: 30
        color: "#20408000"
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        Text {
            id: endText
            text: "End"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.fill: parent
        }
        MouseArea {
            anchors.fill: parent
            onClicked: view.endSession()
        }
    }

    Rectangle {
        id: yesRect
        objectName: "yesRect"
        width: 80
        height: 30
        color: "#20408000"
        anchors.horizontalCenterOffset: -50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        Text {
            id: yesText
            text: "Yes"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.fill: parent
        }
        MouseArea {
            anchors.fill: parent
            onClicked: view.accepted()
        }
    }

    Rectangle {
        id: noRect
        objectName: "noRect"
        width: 80
        height: 30
        color: "#20408000"
        anchors.horizontalCenterOffset: 50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        Text {
            id: noText
            text: "No"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.fill: parent
        }
        MouseArea {
            anchors.fill: parent
            onClicked: view.rejected()
        }
    }

}



