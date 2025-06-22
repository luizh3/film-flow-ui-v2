import QtQuick
import QtQuick.Effects

Item {
    id: root

    required property string vSource
    required property int vRadius
    property int vMargin: 0

    Image {
        id: sourceItem
        height: parent.height
        width: parent.width
        anchors.fill: parent
        visible: false
        source: root.vSource
    }

    MultiEffect {
        source: sourceItem
        anchors.fill: sourceItem
        maskEnabled: true
        maskSource: mask
    }

    Item {
        id: mask
        anchors.fill: sourceItem
        layer.enabled: true
        visible: false

        Rectangle {
            anchors.fill: parent
            radius: root.vRadius
            anchors.margins: root.vMargin
        }
    }
}
