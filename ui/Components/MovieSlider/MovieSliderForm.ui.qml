import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import Ui.Components.Elements
import Ui.Theme

Item {
    id: root
    implicitWidth: 436
    implicitHeight: 278

    property string vBackdropUrl: ""
    property string vTitle: ""
    property double vAverage: 0.00
    property bool vIsLoading: true

    property alias buttonNext: buttonNext
    property alias buttonPrevius: buttonPrevius

    ColumnLayout {
        width: parent.width
        spacing: Spacings.xl2
        anchors.bottomMargin: 0

        Label {
            id: label
            font: Fonts.title270
            text: root.vTitle
            color: Colors.grey50
            wrapMode: Text.Wrap
            lineHeight: 0.8
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
            Layout.fillWidth: true
            Layout.preferredHeight: fontMetrics.height * 2
            Layout.maximumWidth: 600

            FFSkeletonLoading {
                anchors.fill: parent
                color: Colors.grey600
                radius: 4
                visible: root.vIsLoading
            }

            FontMetrics {
                id: fontMetrics
                font: label.font
            }
        }

        FFScoreBadget {
            vScore: root.vAverage

            FFSkeletonLoading {
                anchors.fill: parent
                color: Colors.grey600
                radius: 4
                visible: root.vIsLoading
            }
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: Spacings.xl

            FFButton {
                vIcon: Icons.outlined.play
                text: qsTr("Play")
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: Spacings.md

                FFButtonIcon {
                    id: buttonPrevius
                    vIcon: Icons.outlined.leftArrow
                }

                FFButtonIcon {
                    id: buttonNext
                    vIcon: Icons.outlined.rightArrow
                }
            }
        }
    }
}
