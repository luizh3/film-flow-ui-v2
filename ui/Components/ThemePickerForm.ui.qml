import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Ui.Theme

Item {
    id: root
    width: 360
    height: 400

    property alias colorsGridView: colorsGridView

    GridView {
        id: colorsGridView
        anchors.fill: parent

        clip: true
        cellWidth: 36 + Spacings.sm2
        cellHeight: 36 + Spacings.sm2
        model: colors
    }
}
