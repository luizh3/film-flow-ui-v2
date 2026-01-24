import QtQuick
import QtQuick.Controls

import Ui.Theme
import Ui.Components
import Ui.Components.Elements

import QtQuick.Particles

Item {
    id: root
    implicitWidth: 1024
    implicitHeight: 768

    property var vSections: []
    property alias repeaterSections: repeaterSections
    property alias header: header

    ImageGradient {
        id: imageGradient
        anchors.fill: parent
        vSource: movieSlider.vBackdropUrl

        FFSkeletonLoading {
            anchors.fill: parent
            color: Colors.grey500
            opacity: movieSlider.vIsLoading
                     || imageGradient.sourceItem.status !== Image.Ready ? 1 : 0

            Behavior on opacity {
                NumberAnimation {
                    duration: Durations.normal
                }
            }
        }

        // ParticleSystem {
        //     id: particleSystem
        //     running: true
        // }

        // Emitter {
        //     id: snowEmitter
        //     system: particleSystem
        //     width: parent.width
        //     height: 2
        //     anchors.top: parent.top
        //     emitRate: 20
        //     lifeSpan: 6000
        //     size: 10
        //     velocity: AngleDirection {
        //         angle: 90
        //         magnitude: 50
        //         magnitudeVariation: 20
        //     }
        // }

        // ImageParticle {
        //     system: particleSystem
        //     source: "qrc:/icons/light"
        //     colorVariation: 0.2
        //     entryEffect: ImageParticle.Fade
        // }
        Column {
            anchors.fill: parent

            Header {
                id: header
                width: parent.width
                anchors.left: parent.left
                anchors.right: parent.right
                rightPadding: Spacings.xl3
                leftPadding: Spacings.xl3
                bottomPadding: Spacings.xl2
                topPadding: Spacings.xl2
                vOpacity: scrolView.isContentOverlay() ? 1.0 : 0.0
            }

            Flickable {
                id: scrolView
                width: parent.width
                height: parent.height - header.height
                contentWidth: parent.width
                contentHeight: column.height + movieSlider.height
                clip: true

                ScrollBar.vertical: ScrollBar {}

                function isContentOverlay() {
                    return scrolView.originY !== scrolView.contentY
                }

                Control {
                    id: mainContentControl
                    anchors.fill: parent
                    anchors.leftMargin: Spacings.xl3

                    MovieSlider {
                        id: movieSlider
                    }

                    Column {
                        id: column
                        width: parent.width
                        spacing: Spacings.md
                        anchors.top: movieSlider.bottom
                        anchors.topMargin: Spacings.md

                        Repeater {
                            id: repeaterSections
                            model: root.vSections
                        }
                    }
                }
            }
        }
    }
}
