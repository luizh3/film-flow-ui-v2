import QtQuick
import QtQuick.Layouts

Item {

    property alias canvas: canvas

    ColumnLayout {
        anchors.fill: parent

        Canvas {
            id: canvas
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: parent.height
            antialiasing: true
        }
    }

}
