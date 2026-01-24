import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Ui.Theme

GenericPopup {
    width: 280
    height: 280

    property alias notificationsList: notificationsList

    contentItem: ColumnLayout {

        Label {
            font: Fonts.caption270
            color: Colors.grey50
            text: qsTr("Notifications")
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 1
            color: Colors.grey500
        }

        ListView {
            id: notificationsList
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            spacing: 0
            cacheBuffer: notificationsList.height / 2

            ScrollBar.vertical: ScrollBar {}
        }
    }
}
