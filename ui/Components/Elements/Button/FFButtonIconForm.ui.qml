import QtQuick
import QtQuick.Controls

import Ui.Theme 1.0

import "../"

Button {
    id: root
    implicitWidth: 42
    implicitHeight: 42
    icon.width: 18
    icon.height: 18
    padding: Spacings.lg
    spacing: Spacings.sm2
    font: Fonts.caption260
    palette.buttonText: Colors.neutral100

    required property string vIcon
    property bool vHasNotification: false

    property int _radius: Radius.sm

    property string _color: "transparent"
    property string _colorIcon: icon.vColor
    property string _hoverColor: Colors.grey300
    property string _colorIconHover: root._colorIcon

    background: Rectangle {
        opacity: root.hovered && root.enabled ? 0.8 : 1
        radius: root._radius
        color: root.hovered && root.enabled ? root._hoverColor : root._color

        Behavior on opacity {
            NumberAnimation {
                duration: 150
                easing.type: Easing.InOutQuad
            }
        }

    }

    FFIcon {
        id: icon
        vColor: root.hovered && root.enabled ? root._colorIconHover : root._colorIcon
        source: root.vIcon
        sourceSize: Qt.size( 18, 18 )
        anchors.centerIn: parent
    }

    Rectangle {
        width: 8
        height: 8
        radius: 360
        color: Colors.error
        x: icon.x + ( icon.width / 2 )
        y: icon.y + 2
        visible: root.vHasNotification
    }

    // TODO change this code, reimplement tooltip of button
    ToolTip {
         visible: root.hovered && root.ToolTip.text !== ""
         text: root.ToolTip.text
         palette.toolTipText: Colors.grey50
         font: Fonts.label170
         background: Rectangle {
             color: Colors.grey700
             radius: Radius.xl
         }
     }

}
