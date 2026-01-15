import QtQuick
import QtQuick.Controls
import Ui.Components.Elements
import Ui.Theme

Button {
    id: root

    width: 200
    height: 60
    spacing: Spacings.lg

    property bool vSelected: true

    objectName: "SideBarItem"

    required property string vIcon
    required property string vText
    required property int vType

    background: Rectangle {
        color: root.vSelected || root.hovered ? Colors.grey500 : Colors.grey600
        radius: Radius.sm

        Rectangle {
            width: 4
            height: parent.height
            color: Colors.primary
            topLeftRadius: Spacings.sm
            bottomLeftRadius: Spacings.sm
            visible: root.vSelected
        }

        Behavior on color {
            ColorAnimation {
                duration: Durations.normal
            }
        }
    }

    contentItem: Item {

        FFIcon {
            id: icon
            source: root.vIcon
            vColor: root.vSelected ? Colors.primary : Colors.grey200
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: Spacings.xl3
            sourceSize: Qt.size(18, 18)
        }

        Label {
            text: root.vText
            font: root.vSelected ? Fonts.caption260 : Fonts.caption250
            color: Colors.grey200
            anchors.left: icon.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: Spacings.lg
        }
    }
}
