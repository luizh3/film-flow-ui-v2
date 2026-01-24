import QtQuick
import QtQuick.Effects

Item {
    id: root

    required property string vSource
    required property int vRadius
    property int vMargin: 0
    property alias image: sourceItem

    Image {
        id: sourceItem
        anchors.fill: parent
        sourceSize.width: parent.width
        visible: false
        cache: false
        source: root.vSource
        asynchronous: true
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
