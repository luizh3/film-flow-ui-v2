pragma ComponentBehavior: Bound

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

    property alias loadingComponent: loadingComponent
    property alias idleComponent: idleComponent

    property alias loader: loader

    Loader {
        id:loader
        anchors.fill: parent
        sourceComponent: loadingComponent
    }

    Component {
        id: loadingComponent

        FFSkeletonLoading {
            anchors.fill: parent;
            color: Colors.grey600
            radius: 16
        }
    }

    Component {
        id: idleComponent

        FFImageRounded {
            id: sourceItem
            anchors.fill: parent
            vSource: root.vSource
            vRadius: 16

            Rectangle {
                anchors.fill: sourceItem
                radius: 14
                gradient: Gradient {
                    GradientStop { position: 1.0; color: Qt.rgba( 0, 0, 0, 1 ) }
                    GradientStop { position: 0.8; color: Qt.rgba( 0, 0, 0, 0.9 ) }
                    GradientStop { position: 0.6; color: Qt.rgba( 0.15, 0.15, 0.15, 0.8 ) }
                    GradientStop { position: 0.4; color: Qt.rgba( 0.15, 0.15, 0.15, 0.3 ) }
                    GradientStop { position: 0.2; color: Qt.rgba( 0.15, 0.15, 0.15, 0.3 ) }
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
                    width: parent.width - ( parent.anchors.leftMargin + parent.anchors.bottomMargin )
                    elide: Text.ElideRight
                }

                FFScoreBadget {
                   vScore: root.vAverage
                   vSize: FFScoreBadget.Size.Small
                }
            }
        }
    }
}
