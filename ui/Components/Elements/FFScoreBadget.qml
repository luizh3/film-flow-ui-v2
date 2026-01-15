import QtQuick
import QtQuick.Controls

import Ui.Theme

Item {
    id: root
    // TODO ajustar
    implicitWidth: root.vSize
                   === FFScoreBadget.Size.Medium ? 26 + 32 + label.anchors.leftMargin : 16
                                                   + 32 + label.anchors.leftMargin

    implicitHeight: icon.height

    required property double vScore

    property int vSize: FFScoreBadget.Size.Medium

    enum Size {
        Medium,
        Small
    }

    FFIcon {
        id: icon
        source: Icons.outlined.star
        anchors.verticalCenter: parent.verticalCenter
        sourceSize: Qt.size(root.vSize === FFScoreBadget.Size.Medium ? 20 : 16,
                            root.vSize === FFScoreBadget.Size.Medium ? 20 : 16)
        vColor: Colors.orange300
    }

    Label {
        id: label
        font: root.vSize === FFScoreBadget.Size.Medium ? Fonts.body270 : Fonts.caption270
        text: root.vScore.toFixed(1)
        color: Colors.orange300
        anchors.left: icon.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: Spacings.sm
    }
}
