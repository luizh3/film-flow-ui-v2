import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Ui.Theme
import Ui.Models

import "../CardMovie"

ColumnLayout {
    id: root
    spacing: Spacings.md2

    property alias vTitle: label.text

    required property int vTypeProgram;
    required property string vKey;

    Label {
        id: label
        font: Fonts.body270
        text: qsTr( "Movies" )
        color: Colors.grey200
    }

    ListView {
        Layout.fillHeight: true
        Layout.fillWidth: true
        spacing: Spacings.md
        clip: true
        orientation: ListView.Horizontal

        model: MoviesListModel {
            tpProgram: root.vTypeProgram
            key: root.vKey
        }

        delegate: CardMovie {

            required property string title
            required property string posterUrl
            required property double average
            required property bool isLoading

            vSource: posterUrl
            vAverage: average
            vTitle: title
            vIsLoading: isLoading
        }

        populate: Transition  {
            NumberAnimation { property: "opacity"; from: 0; to: 1; duration: 10000 }
        }
    }
}
