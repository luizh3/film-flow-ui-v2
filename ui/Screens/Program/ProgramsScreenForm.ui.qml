import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Ui.Theme
import Ui.Components
import Ui.Components.Elements

import Ui.Models

Rectangle {
    id: root

    implicitWidth: 1024
    implicitHeight: 768

    property alias moviesGrid: moviesGrid
    property alias header: header

    color: Colors.grey500

    property string vDsQuery: ""

    component FeedbackInformationSearch: Rectangle {
        id: feedbackInformationSearch
        width: 1024
        height: 728

        radius: Radius.sm
        color: Colors.grey600

        required property string vIcon
        required property string vIconColor
        required property string vTitle
        required property string vDescription

        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            anchors.centerIn: parent
            spacing: Spacings.md

            FFIcon {
                source: feedbackInformationSearch.vIcon
                sourceSize: Qt.size(96, 96)
                vColor: feedbackInformationSearch.vIconColor
                Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
            }

            ColumnLayout {
                Layout.fillWidth: true
                Layout.fillHeight: true
                spacing: Spacings.xs

                Text {
                    text: feedbackInformationSearch.vTitle
                    font: Fonts.caption150
                    color: Colors.grey50
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                }

                Text {
                    text: feedbackInformationSearch.vDescription
                    font: Fonts.label140
                    color: Colors.grey100
                    Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter
                }
            }
        }
    }

    ColumnLayout {
        anchors.fill: parent

        Header {
            id: header
            Layout.fillWidth: true
            rightPadding: Spacings.xl3
            leftPadding: Spacings.xl3
            bottomPadding: Spacings.xl2
            topPadding: Spacings.xl2
            vOpacity: 0.0
            vIsUsingSearchPopup: false
        }

        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: Spacings.md

            RowLayout {
                Layout.fillWidth: true
                Layout.leftMargin: Spacings.xl3
                Layout.rightMargin: Spacings.xl3

                Label {
                    font: Fonts.caption170
                    color: Colors.grey50
                    text: qsTr("No filters")
                    Layout.fillWidth: true
                }

                Label {
                    font: Fonts.caption250
                    color: Colors.grey50
                    text: qsTr("Found 100 results")
                }
            }

            GridView {
                id: moviesGrid
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.leftMargin: Spacings.xl3
                visible: moviesGrid.count !== 0

                clip: true
                cellWidth: 204 + Spacings.sm2
                cellHeight: 266 + Spacings.md

                model: SearchProgramListModel {
                    vDsQuery: root.vDsQuery
                }

                ScrollBar.vertical: ScrollBar {}
            }

            FeedbackInformationSearch {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.leftMargin: Spacings.xl3
                Layout.rightMargin: Spacings.xl3
                Layout.bottomMargin: Spacings.lg
                visible: !moviesGrid.visible

                property bool _hasNoResults: root.vDsQuery !== ""
                                             && moviesGrid.count === 0

                vIcon: _hasNoResults ? Icons.outlined.close : Icons.outlined.search
                vIconColor: _hasNoResults ? Colors.primary : Colors.grey100
                vTitle: _hasNoResults ? qsTr("No results founded") : qsTr(
                                            "Search for a program")
                vDescription: qsTr("Type a title, genre or actor to start searching")
            }
        }
    }
}
