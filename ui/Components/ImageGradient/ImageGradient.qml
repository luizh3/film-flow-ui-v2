import QtQuick
import QtQuick.Effects
import Ui.Theme

Rectangle {
    id: root
    implicitWidth: 1024
    implicitHeight: 728
    color: Colors.grey500

    property string vSource: "https://image.tmdb.org/t/p/original/v7GQxa9ZmdMZjt4JwZF54mvAiTv.jpg"

    property alias sourceItem: sourceItem

    Image {
        id: sourceItem
        source: root.vSource
        visible: true
        anchors.fill: parent
        sourceSize.width: parent.width
        fillMode: Image.PreserveAspectCrop
        asynchronous: true
        cache: false
    }

    MultiEffect {
        source: sourceItem
        anchors.fill: sourceItem
        brightness: 0.4
        saturation: 0.0
        blurEnabled: false
        blurMax: 0
        blur: 0
        colorizationColor: "#000000"
        colorization: 0.5
        visible: root.vSource !== ""
    }

    Rectangle {
        anchors.fill: sourceItem
        visible: root.vSource !== ""

        gradient: Gradient {
            GradientStop {
                position: 1.0
                color: Qt.rgba(0, 0, 0, 0.1)
            }
            GradientStop {
                position: 0.8
                color: Qt.rgba(0.15, 0.15, 0.15, 0.6)
            }
            GradientStop {
                position: 0.6
                color: Qt.rgba(0.15, 0.15, 0.15, 0.7)
            }
            GradientStop {
                position: 0.4
                color: Qt.rgba(0.15, 0.15, 0.15, 0.8)
            }
            GradientStop {
                position: 0.2
                color: Qt.rgba(0.15, 0.15, 0.15, 0.9)
            }
            orientation: Gradient.Horizontal
        }
    }
}
