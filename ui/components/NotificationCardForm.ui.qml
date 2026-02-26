import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Ui.Theme
import Ui.Components.Elements

Item {
    id: root
    height: 45

    required property string vIcon
    required property string vDescription
    required property bool vIsLoading
    required property string vActorAvatarUrl

    property alias loader: loader

    property alias loadingComponent: loadingComponent
    property alias idleComponent: idleComponent

    Loader {
        id: loader
        anchors.fill: parent
        sourceComponent: loadingComponent
    }

    Component {
        id: loadingComponent

        FFSkeletonLoading {
            anchors.fill: parent
            color: Colors.grey600
            radius: Radius.xl
        }
    }

    Component {
        id: idleComponent

        Rectangle {
            color: mouseArea.containsMouse ? Colors.grey600 : Colors.grey700
            anchors.fill: parent
            radius: Radius.sm

            RowLayout {
                anchors.fill: parent
                spacing: Spacings.sm2

                FFProfileIcon {
                    vHasHover: false
                    vIcon: root.vActorAvatarUrl
                    Layout.leftMargin: Spacings.sm2

                    Rectangle {
                        width: 16
                        height: 16
                        radius: 360
                        color: Colors.red400
                        anchors.bottom: parent.bottom
                        anchors.right: parent.right

                        FFIcon {
                            source: root.vIcon
                            sourceSize: Qt.size(8, 8)
                            vColor: Colors.grey50
                            Layout.alignment: Qt.AlignVCenter
                            anchors.centerIn: parent
                        }
                    }
                }

                Label {
                    font: Fonts.label140
                    text: root.vDescription
                    color: Colors.grey50
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    wrapMode: Text.Wrap
                    elide: Text.ElideRight
                    Layout.rightMargin: Spacings.sm
                }
            }

            MouseArea {
                id: mouseArea
                anchors.fill: parent
                hoverEnabled: true
                cursorShape: Qt.PointingHandCursor
            }
        }
    }
}
