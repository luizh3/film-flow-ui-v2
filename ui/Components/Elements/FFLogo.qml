import QtQuick.Controls
import QtQuick

import Ui.Theme

Row {
    id: root

    property font vFont: Fonts.body270

    Label {
        text: "Film"
        font: root.vFont
        color: Colors.primary600
    }

    Label {
        text: "Flow"
        color: Colors.neutral100
        font: root.vFont
    }
}
