import Ui.Theme
import Ui.Components
import Ui.Components.Elements
import QtQuick.Layouts
import QtQuick.Controls

GenericModal {
    width: 736
    height: 685

    property alias closeButton: closeButton
    property alias cancelButton: cancelButton
    property alias confirmButton: confirmButton

    property alias reviewTitleLabel: reviewTitleLabel
    property alias programTitleLabel: programTitleLabel

    property alias descriptionField: descriptionField
    property alias titleField: titleField
    property alias ratingStars: ratingStars

    ColumnLayout {
        anchors.fill: parent
        spacing: Spacings.xl4
        anchors.leftMargin: Spacings.xl3
        anchors.rightMargin: Spacings.xl3
        anchors.topMargin: Spacings.xl2
        anchors.bottomMargin: Spacings.xl2

        RowLayout {
            Layout.fillWidth: true

            ColumnLayout {
                Layout.fillWidth: true
                spacing: Spacings.sm

                Label {
                    id: reviewTitleLabel
                    font: Fonts.title370
                    color: Colors.neutral100
                    text: "Review by Luiz"
                    Layout.fillWidth: true
                }

                Label {
                    id: programTitleLabel
                    font: Fonts.label140
                    color: Colors.neutral100
                    text: "Review by Luiz"
                    Layout.fillWidth: true
                }
            }

            FFButtonIcon {
                id: closeButton
                vIcon: Icons.outlined.close
            }
        }

        FFRatingStars {
            id: ratingStars
            Layout.fillWidth: true
        }

        FFTextField {
            id: titleField
            Layout.fillWidth: true
            vLabel: qsTr("Title")
            vPlaceHolderText: ""
        }

        FFTextArea {
            id: descriptionField
            Layout.fillWidth: true
            vLabel: qsTr("Write a review")
            vPlaceHolderText: ""
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: Spacings.xl

            FFButton {
                id: cancelButton
                Layout.fillWidth: true
                text: qsTr("Cancel")
                vIcon: Icons.outlined.close
                vType: FFButton.Type.Secundary
            }

            FFButton {
                id: confirmButton
                Layout.fillWidth: true
                text: qsTr("Confirm")
                vIcon: Icons.outlined.check
            }
        }
    }
}
