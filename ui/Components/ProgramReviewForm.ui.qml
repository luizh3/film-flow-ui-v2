import QtQuick
import QtQuick.Controls

import Ui.Components.Elements
import Ui.Theme

Rectangle {
    id: root
    width: 720
    color: Colors.grey600
    border.color: Colors.grey400
    radius: Radius.sm
    border.width: 1

    implicitHeight: loader.implicitHeight + Spacings.xl

    required property string vReviewId
    required property string vUserImage
    required property string vUserName
    required property string vDateCreated
    required property string vTitle
    required property string vDescription
    required property double vScore
    required property bool vIsLoading
    required property string vLoadingColor
    required property bool vIsShowAboutMovie
    required property var vProgramTitle
    required property bool vIsLikedByMe
    required property int vLikesCount

    property bool vIsExpanded: false

    property alias loadingComponent: loadingComponent
    property alias idleComponent: idleComponent

    property alias loader: loader

    Loader {
        id: loader
        anchors.fill: parent
        sourceComponent: loadingComponent
    }

    Component {
        id: loadingComponent

        FFSkeletonLoading {
            width: parent.width
            implicitHeight: 200
            color: root.vLoadingColor
            radius: Radius.sm
            visible: root.vIsLoading
        }
    }

    Component {
        id: idleComponent

        Column {
            id: contentColumn
            anchors.fill: parent
            anchors.margins: Spacings.md
            spacing: Spacings.sm2

            property alias likedButton: likedButton
            property alias readMoreMouse: readMoreMouse
            property alias readMoreLabel: readMoreLabel
            property alias aboutMovieMouse: aboutMovieMouse

            Row {
                spacing: Spacings.md
                width: parent.width

                FFProfileIcon {
                    vIcon: root.vUserImage
                    implicitHeight: 42
                    implicitWidth: 42
                    anchors.verticalCenter: parent.verticalCenter
                    vHasHover: false
                }

                Column {
                    spacing: Spacings.xs

                    Label {
                        font: Fonts.caption270
                        text: root.vUserName
                        color: Colors.grey50
                    }

                    Label {
                        font: Fonts.label140
                        text: root.vDateCreated
                        color: Colors.grey100
                    }
                }

                Rectangle {
                    width: 1
                    height: parent.height
                    color: Colors.grey400
                }

                FFScoreBadget {
                    vScore: root.vScore
                    vSize: FFScoreBadget.Size.Medium
                    anchors.verticalCenter: parent.verticalCenter
                }

                Rectangle {
                    width: 1
                    height: parent.height
                    color: Colors.grey400
                    visible: root.vIsShowAboutMovie
                }

                Item {
                    height: parent.height
                    width: childrenRect.width
                    visible: root.vIsShowAboutMovie

                    MouseArea {
                        id: aboutMovieMouse
                        anchors.fill: parent
                        hoverEnabled: true
                        cursorShape: Qt.PointingHandCursor
                    }

                    Column {
                        height: parent.height

                        Label {
                            font: Fonts.label140
                            text: qsTr("About")
                            color: Colors.grey50
                        }

                        Row {
                            spacing: Spacings.xs

                            Label {
                                font: Fonts.caption250
                                text: root.vProgramTitle
                                color: aboutMovieMouse.containsMouse ? Colors.primary300 : Colors.grey50

                                Behavior on color {
                                    ColorAnimation {
                                        duration: Durations.fast
                                    }
                                }
                            }

                            FFIcon {
                                source: Icons.outlined.rightArrow
                                sourceSize: Qt.size(14, 14)
                                vColor: aboutMovieMouse.containsMouse ? Colors.primary300 : Colors.grey50
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }
                    }
                }
            }

            Rectangle {
                width: parent.width
                height: 1
                color: Colors.grey400
            }

            Column {
                spacing: Spacings.sm2
                width: parent.width

                Label {
                    font: Fonts.caption170
                    text: root.vTitle
                    color: Colors.grey50
                }

                Column {
                    width: parent.width
                    spacing: Spacings.xs

                    Label {
                        id: descriptionLabel
                        width: parent.width
                        font: Fonts.label140
                        color: Colors.grey50
                        wrapMode: Text.WordWrap
                        text: root.vDescription
                        clip: true

                        readonly property real _lineHeight: font.pixelSize * 1.35
                        readonly property int _collapsedLines: 2
                        readonly property real _collapsedHeight: _lineHeight * _collapsedLines

                        height: root.vIsExpanded ? implicitHeight : Math.min(
                                                       _collapsedHeight,
                                                       implicitHeight)

                        Behavior on height {
                            NumberAnimation {
                                duration: Durations.normal
                            }
                        }
                    }

                    Label {
                        id: readMoreLabel
                        font: Fonts.label170
                        color: Colors.neutral100

                        visible: descriptionLabel.implicitHeight > descriptionLabel._collapsedHeight

                        MouseArea {
                            id: readMoreMouse
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                        }
                    }
                }

                FFButtonReaction {
                    id: likedButton

                    vIsSelected: root.vIsLikedByMe
                    vIcon: Icons.outlined.favorite
                    vIconSelected: Icons.filled.favorite
                    vIconColor: likedButton.vIsSelected ? Colors.red400 : Colors.grey50
                    vLikesCount: root.vLikesCount
                }
            }
        }
    }
}
