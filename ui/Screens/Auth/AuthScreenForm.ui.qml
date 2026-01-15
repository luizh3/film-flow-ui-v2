import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Ui.Components
import Ui.Theme

Item {
    implicitWidth: 1280
    implicitHeight: 768

    property alias stackView: stackView

    RowLayout {
        anchors.fill: parent
        spacing: 0

        StackView {
            id: stackView
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredWidth: 636
            Layout.preferredHeight: 720
        }

        Rectangle {
            Layout.preferredWidth: 1
            Layout.fillHeight: true
            color: Colors.grey500
        }

        ImageGradient {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }
}
