import Qt 4.7
import MeeGo.Components 0.1

Rectangle {
    id: view
    objectName: "view"
    width: 480
    height: 320
    color: "#20400080"

    signal itemSelected(int selection)
    onItemSelected: console.log("Item selected: " + selection)
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
        wrapMode: Text.WordWrap
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

    ListView {
        id: menuView
        objectName: "menuView"
        model: menuModel
        delegate: menuDelegate
        anchors.top: title.bottom
        anchors.topMargin: 10
        anchors.left: icon.right
        anchors.leftMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.right: endRect.left
        anchors.rightMargin: 10
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

}



