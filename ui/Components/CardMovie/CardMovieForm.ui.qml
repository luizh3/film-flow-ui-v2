pragma ComponentBehavior

import QtQuick
import QtQuick.Controls

import Ui.Theme
import Ui.Components.Elements

Item {
    id: root

    implicitWidth: 204
    implicitHeight: 266

    required property string vSource
    required property string vTitle
    required property double vAverage

    required property bool vIsLoading

    property alias mouseArea: mouseArea

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
    }

    FFImageRounded {
        id: sourceItem
        anchors.fill: parent
        vSource: root.vSource !== "" ? root.vSource : "qrc:/icons/not-found"
        vRadius: Radius.md

        Rectangle {
            id: rectangleHover
            color: Colors.grey600
            anchors.fill: parent
            radius: Radius.md
            opacity: mouseArea.containsMouse ? 0.5 : 0

            Behavior on opacity {
                NumberAnimation {
                    duration: Durations.normal
                }
            }
        }

        Rectangle {
            anchors.fill: sourceItem
            radius: 14
            gradient: Gradient {
                GradientStop {
                    position: 1.0
                    color: Qt.rgba(0, 0, 0, 1)
                }
                GradientStop {
                    position: 0.8
                    color: Qt.rgba(0, 0, 0, 0.9)
                }
                GradientStop {
                    position: 0.6
                    color: Qt.rgba(0.15, 0.15, 0.15, 0.8)
                }
                GradientStop {
                    position: 0.4
                    color: Qt.rgba(0.15, 0.15, 0.15, 0.3)
                }
                GradientStop {
                    position: 0.2
                    color: Qt.rgba(0.15, 0.15, 0.15, 0.3)
                }
            }
        }

        Column {
            spacing: Spacings.sm
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.leftMargin: Spacings.md2
            anchors.bottomMargin: Spacings.md
            width: parent.width

            Label {
                font: Fonts.caption270
                text: root.vTitle
                color: Colors.grey50
                width: parent.width - (parent.anchors.leftMargin + parent.anchors.bottomMargin)
                elide: Text.ElideRight
            }

            FFScoreBadget {
                vScore: root.vAverage
                vSize: FFScoreBadget.Size.Small
            }
        }

        FFSkeletonLoading {
            id: skeletonLoading
            anchors.fill: parent
            color: Colors.grey600
            radius: 12
            opacity: sourceItem.image.status === Image.Ready
                     && !root.vIsLoading ? 0 : 1

            Behavior on opacity {
                NumberAnimation {
                    duration: Durations.normal
                }
            }
        }
    }
}
