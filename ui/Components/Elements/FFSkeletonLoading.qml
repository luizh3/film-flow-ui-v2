import QtQuick

Rectangle {
    id: rectRoot
    color: "#d0d0d0"
    clip: true

    Rectangle {
        id: shimmer
        width: rectRoot.width
        height: rectRoot.height
        anchors.verticalCenter: parent.verticalCenter
        x: -width
        radius: rectRoot.radius
        gradient: Gradient {
            orientation: Gradient.Horizontal
            GradientStop {
                position: 0.0
                color: Qt.rgba(0.2, 0.2, 0.2, 0.0)
            }
            GradientStop {
                position: 0.1
                color: Qt.rgba(0.2, 0.2, 0.2, 0.1)
            }
            GradientStop {
                position: 0.2
                color: Qt.rgba(0.2, 0.2, 0.2, 0.2)
            }
            GradientStop {
                position: 0.3
                color: Qt.rgba(0.2, 0.2, 0.2, 0.5)
            }
            GradientStop {
                position: 0.4
                color: Qt.rgba(0.2, 0.2, 0.2, 0.8)
            }
            GradientStop {
                position: 0.5
                color: Qt.rgba(0.2, 0.2, 0.2, 1.0)
            }
            GradientStop {
                position: 0.6
                color: Qt.rgba(0.2, 0.2, 0.2, 0.8)
            }
            GradientStop {
                position: 0.7
                color: Qt.rgba(0.2, 0.2, 0.2, 0.5)
            }
            GradientStop {
                position: 0.8
                color: Qt.rgba(0.2, 0.2, 0.2, 0.2)
            }
            GradientStop {
                position: 0.9
                color: Qt.rgba(0.2, 0.2, 0.2, 0.1)
            }
            GradientStop {
                position: 1.0
                color: Qt.rgba(0.2, 0.2, 0.2, 0.0)
            }
        }

        SequentialAnimation on x {
            loops: Animation.Infinite

            // TODO permitir configurar os valores
            PropertyAnimation {
                from: -shimmer.width
                to: rectRoot.width
                duration: 2000
                easing.period: 5
                easing.type: Easing.InElastic
                easing.amplitude: 5
            }
        }
    }
}
