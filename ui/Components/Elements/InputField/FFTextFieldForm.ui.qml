import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Ui.Theme

import "../Button"

Item  {
    id: root

    implicitWidth: 424
    implicitHeight: background.height +
                    ( label.visible ? label.height + background.anchors.topMargin : 0 ) +
                    ( labelError.visible ? labelError.height + labelError.anchors.topMargin : 0 );

    property string vIconRight: ""
    property string vIconLeft: ""
    property string vLabel: ""

    property var vValidator

    property int vType: FFTextField.Type.Primary

    property alias vPlaceHolderText: textField.placeholderText
    property alias vText: textField.text

    property alias _textError: labelError.text

    property alias buttonIconLeft: buttonIconLeft
    property alias buttonIconRight: buttonIconRight

    property alias label: label
    property alias background: background
    property alias textField: textField
    property alias labelError: labelError

    property alias vIsAcceptable: textField.acceptableInput;

    property bool _isInicialized: false;
    property bool vIsValid: !root._isInicialized || root.textField.acceptableInput

    Label {
        id: label
        font: Fonts.caption270
        width: parent.width
        anchors.top: parent.top
        color: Colors.neutral100
    }

    Rectangle {
        id: background
        implicitWidth: parent.width
        implicitHeight: 50
        border.width: 2
        radius: Radius.md
        color: Colors.grey700
        border.color: Colors.grey400
        anchors.top: label.visible ? label.bottom : root.top
        anchors.topMargin: label.visible ? Spacings.sm : 0

        RowLayout {
            spacing: 0
            anchors.fill: parent

            FFButtonIcon {
                id: buttonIconLeft
                vIcon: "qrc:/icons/search"
                vType: FFButtonIcon.Type.FlatSecundary
                Layout.leftMargin: Spacings.sm2
            }

            TextField  {
                id: textField

                Layout.fillWidth: true
                Layout.fillHeight: true

                placeholderText: qsTr( "Placeholder..." )

                font: Fonts.caption250
                color: Colors.neutral100
                selectionColor: Colors.grey300
                placeholderTextColor: Colors.grey200
                selectedTextColor: Colors.neutral100

                Layout.leftMargin: buttonIconLeft.visible ? 0 : Spacings.md
                Layout.rightMargin: buttonIconRight.visible ? 0 : Spacings.md

                background: Item {}
            }

            FFButtonIcon {
                id: buttonIconRight
                vIcon: "qrc:/icons/filter"
                vType: FFButtonIcon.Type.FlatSecundary
                Layout.rightMargin: Spacings.sm2
            }
        }
    }

    Label {
        id: labelError
        font: Fonts.label170
        width: parent.width
        anchors.top: background.bottom
        anchors.topMargin: Spacings.sm
        color: Colors.error
        wrapMode: Text.WordWrap
    }
}
