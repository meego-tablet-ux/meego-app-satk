import Qt 4.7

Rectangle {
    id: view
    width: 480
    height: 320
    color: "#20400080"

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
}
