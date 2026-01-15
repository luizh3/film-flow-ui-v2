import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Ui.Theme

Item {
    width: 300
    height: 50
    id: root

    required property var vModel

    property alias vCurrentIndex: optionsList.currentIndex

    property alias optionsList: optionsPopup.optionsList
    property alias optionsPopup: optionsPopup
    property alias comboSelector: comboSelector

    property string _currentImage: ""
    property string _currentText: ""

    readonly property bool _isPopupOpened: root.optionsPopup.opened

    component ComboIndicator: Item {
        id: comboIndicator
        width: 24
        height: 24
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.rightMargin: Spacings.sm2

        required property bool vIsActive

        FFIcon {
            id: arrowIcon
            anchors.centerIn: parent
            source: Icons.outlined.leftArrow
            rotation: comboIndicator.vIsActive ? 270 : 90
            transformOrigin: Item.Center
            vColor: Colors.grey50

            Behavior on rotation {
                NumberAnimation {
                    duration: Durations.fast
                }
            }
        }
    }

    component RadioOption: Rectangle {
        id: radioOption

        radius: 360
        Layout.preferredHeight: 18
        Layout.preferredWidth: 18
        color: Colors.neutral100
        border.color: radioOption.vIsSelected ? Colors.primary : Colors.grey400
        border.width: 1

        required property bool vIsSelected

        Rectangle {
            radius: 360
            height: 12
            width: 12
            color: radioOption.vIsSelected ? Colors.primary : Colors.neutral100
            anchors.centerIn: parent
        }
    }

    component ItemComboDelegate: Rectangle {

        id: itemComboDelegate
        width: ListView.view.width
        color: itemComboDelegate._isCurrentSelected ? Colors.grey600 : Colors.grey700
        height: 50
        radius: Radius.sm

        required property string vText
        required property string vImage
        required property bool vIsSelected
        required property int index

        property bool _isCurrentSelected: ListView.view.currentIndex === index
        property alias mouseArea: mouseArea

        RowLayout {
            width: parent.width
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: Spacings.sm2
            anchors.rightMargin: Spacings.sm2
            anchors.left: parent.left
            anchors.right: parent.right
            spacing: Spacings.sm2

            Image {
                source: itemComboDelegate.vImage
                Layout.preferredWidth: 36
                Layout.preferredHeight: 36
                fillMode: Image.PreserveAspectFit
            }

            Label {
                font: itemComboDelegate._isCurrentSelected ? Fonts.label170 : Fonts.label140
                color: Colors.grey50
                Layout.fillWidth: true
                text: itemComboDelegate.vText
                elide: Text.ElideRight
            }

            RadioOption {
                vIsSelected: itemComboDelegate._isCurrentSelected
            }
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
        }
    }

    Rectangle {
        id: comboSelector
        radius: Radius.xl
        anchors.fill: parent
        color: Colors.grey700

        property alias mouseArea: mouseArea

        Row {
            spacing: Spacings.sm
            leftPadding: Spacings.sm2
            rightPadding: Spacings.sm2
            anchors.verticalCenter: parent.verticalCenter

            Image {
                source: root._currentImage
                width: 36
                height: 36
                fillMode: Image.PreserveAspectFit
                anchors.verticalCenter: parent.verticalCenter
            }

            Label {
                text: root._currentText
                font: Fonts.label140
                anchors.verticalCenter: parent.verticalCenter
                color: Colors.grey50
            }
        }

        ComboIndicator {
            vIsActive: root._isPopupOpened
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
        }
    }

    Popup {
        id: optionsPopup
        x: comboSelector.x
        y: comboSelector.y + comboSelector.height + Spacings.sm2
        width: comboSelector.width
        height: Math.min(optionsList.childrenRect.height + Spacings.md2, 200)

        property alias optionsList: optionsList

        background: Rectangle {
            color: Colors.grey700
            radius: Radius.sm
        }

        contentItem: ListView {
            id: optionsList
            clip: true
        }
    }
}
