import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Ui.Theme
import Ui.Components.Elements

Rectangle {
    id: root
    height: 72
    color: mouseArea.containsMouse ? Colors.grey400 : Colors.grey700
    radius: 4

    required property bool vIsLoading
    required property string vTitle
    required property string vPosterUrl
    required property double vAverage
    required property string vGenres
    required property string vOverview

    property alias loader: loader
    property alias mouseArea: mouseArea

    property alias loadingComponent: loadingComponent
    property alias idleComponent: idleComponent

    Loader {
        id: loader
        anchors.fill: parent
        sourceComponent: loadingComponent
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        id: mouseArea
    }

    Component {
        id: loadingComponent

        FFSkeletonLoading {
            anchors.fill: parent
            color: Colors.grey500
            radius: 4

            FFSkeletonLoading {
                width: 48
                height: 64
                color: Colors.grey600
                radius: 4
                anchors.leftMargin: 4
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }

    Component {
        id: idleComponent

        Item {
            anchors.fill: parent
            anchors.leftMargin: 4

            RowLayout {
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width
                spacing: 6

                FFImageRounded {
                    id: sourceItem
                    vSource: root.vPosterUrl !== "" ? root.vPosterUrl : "qrc:/icons/not-found"
                    vRadius: 8
                    Layout.preferredWidth: 48
                    Layout.preferredHeight: 64
                }

                ColumnLayout {
                    spacing: 6
                    Layout.fillWidth: true

                    Label {
                        text: root.vTitle
                        font: Fonts.label170
                        color: Colors.neutral100
                    }

                    Label {
                        Layout.fillWidth: true
                        Layout.rightMargin: Spacings.lg
                        Layout.preferredHeight: 24
                        text: root.vOverview
                        font: Fonts.label140
                        color: Colors.grey50
                        wrapMode: Text.Wrap
                        elide: Text.ElideRight
                    }
                }
            }
        }
    }
}
