import Qt 4.7

Rectangle {
    id: view
    objectName: "view"
    width: 480
    height: 320
    color: "#20400080"
    signal itemSelected(int selection)
    onItemSelected: console.log("Item selected: " + selection)

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

    ListView {
        id: menuView
        objectName: "menuView"
        model: menuModel
        delegate: menuDelegate
        anchors.top: title.bottom
        anchors.topMargin: 10
        anchors.left: icon.right
        anchors.leftMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
    }

    Component {
        id: menuDelegate
        Row {
            spacing: 10
            Image {
                width: 32
                height: 32
                source: icon
                MouseArea {
                    anchors.fill: parent
                    onClicked: view.itemSelected(index)
                }
            }
            Text {
                text: title
                MouseArea {
                    anchors.fill: parent
                    onClicked: view.itemSelected(index)
                }
            }
        }
    }

}



