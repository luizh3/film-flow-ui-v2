import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Ui.Theme
import Ui.Models
import Ui.Components.Elements

ColumnLayout {
    id: root
    spacing: Spacings.md2

    property alias vTitle: label.text

    required property int vTypeProgram
    required property string vKey

    property alias listView: listView

    property alias buttonPrevius: buttonPrevius
    property alias buttonNext: buttonNext

    RowLayout {
        Layout.fillWidth: true

        Label {
            id: label
            font: Fonts.body270
            text: qsTr("Movies")
            color: Colors.grey200
            Layout.fillWidth: true
        }

        Row {
            spacing: Spacings.md
            Layout.alignment: Qt.AlignRight | Qt.AlignHCenter

            Layout.rightMargin: Spacings.md

            FFButtonIcon {
                id: buttonPrevius
                vIcon: Icons.outlined.leftArrow
                width: 32
                height: 32
            }

            FFButtonIcon {
                id: buttonNext
                vIcon: Icons.outlined.rightArrow
                width: 32
                height: 32
            }
        }
    }

    NumberAnimation {
        id: moveAnimation
        target: listView
        property: "contentX"
        duration: 400
        easing.type: Easing.InOutQuad
    }

    ListView {
        id: listView
        Layout.fillHeight: true
        Layout.fillWidth: true
        spacing: Spacings.md
        clip: true
        orientation: ListView.Horizontal
        snapMode: ListView.SnapOneItem
        highlightMoveDuration: 400
        reuseItems: true
        cacheBuffer: listView.width / 2

        model: MoviesListModel {
            tpProgram: root.vTypeProgram
            key: root.vKey
        }

        populate: Transition {
            NumberAnimation {
                property: "opacity"
                from: 0
                to: 1
                duration: 10000
            }
        }

        move: Transition {
            NumberAnimation {
                properties: "x,y"
                duration: 1000
            }
        }
    }
}
