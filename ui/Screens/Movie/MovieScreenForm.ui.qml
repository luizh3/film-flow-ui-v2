import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls

import Ui.Theme
import Ui.Components
import Ui.Components.Elements

GenericScreen {
    id: root
    implicitWidth: 1024
    implicitHeight: 768

    color: Colors.grey500

    required property var vMovieId
    required property var vProgramType

    property var vMovie
    property bool vIsLoading: true

    property alias backButtonNavigation: backButtonNavigation
    property alias writeReviewButton: writeReviewButton
    property alias footerScroll: footerScroll
    property alias scrollFlickable: scrollFlickable
    property alias reviewsList: reviewsList

    component FooterScroll: Item {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: 50

        property alias buttonScroll: buttonScroll

        Behavior on opacity {
            NumberAnimation {
                duration: Durations.normal
            }
        }

        FFButtonScroll {
            id: buttonScroll
            anchors.centerIn: parent
        }
    }

    component FeedbackReviewsFounded: Item {
        height: childrenRect.height

        Rectangle {
            id: contentFeedbackBackground
            width: parent.width
            height: contentFeedbackItem.height + Spacings.lg
            color: Colors.grey500
            radius: Radius.sm
            opacity: 0.7
        }

        Item {
            id: contentFeedbackItem
            width: parent.width
            height: childrenRect.height
            anchors.centerIn: contentFeedbackBackground

            ColumnLayout {
                width: parent.width
                spacing: Spacings.xs

                FFIcon {
                    source: Icons.outlined.star
                    sourceSize: Qt.size(48, 48)
                    vColor: Colors.grey50
                    Layout.alignment: Qt.AlignHCenter
                }

                Label {
                    text: qsTr("No reviews yet")
                    font: Fonts.caption160
                    color: Colors.grey50
                    Layout.alignment: Qt.AlignHCenter
                }

                Label {
                    text: qsTr("This title has not received any reviews.")
                    font: Fonts.label140
                    color: Colors.grey100
                    Layout.alignment: Qt.AlignHCenter
                }
            }
        }
    }

    ImageGradient {
        anchors.fill: parent
        vSource: vMovie?.backdropUrl ?? ""

        FFSkeletonLoading {
            anchors.fill: parent
            color: Colors.grey600
            visible: root.vIsLoading
        }

        ColumnLayout {
            anchors.fill: parent
            spacing: Spacings.xl

            FFButtonNavigation {
                id: backButtonNavigation
                vText: qsTr("Movie")
                vHoverText: qsTr("Movie")

                Layout.leftMargin: Spacings.xl
                Layout.topMargin: Spacings.xl
            }

            Flickable {
                id: scrollFlickable
                Layout.fillWidth: true
                Layout.fillHeight: true

                clip: true
                ScrollBar.vertical: ScrollBar {}

                contentWidth: parent.width
                contentHeight: contentItem.implicitHeight + Spacings.md + footerScroll.height

                Behavior on contentY {
                    NumberAnimation {
                        duration: Durations.normal
                        easing.type: Easing.OutCubic
                    }
                }

                Column {
                    id: contentItem
                    width: parent.width
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.leftMargin: Spacings.xl
                    anchors.rightMargin: Spacings.xl
                    spacing: Spacings.xl

                    Row {
                        width: parent.width
                        spacing: Spacings.lg

                        FFImageRounded {
                            id: sourceItem
                            vSource: vMovie?.posterUrl && vMovie.posterUrl
                                     !== "" ? vMovie.posterUrl : "qrc:/icons/not-found"
                            vRadius: Radius.sm
                            width: 250
                            height: 380

                            FFSkeletonLoading {
                                anchors.fill: parent
                                color: Colors.grey500
                                radius: Radius.xl
                                visible: root.vIsLoading
                                         || sourceItem.image.status !== Image.Ready
                            }
                        }

                        Column {
                            width: parent.width - sourceItem.width - parent.spacing
                            spacing: Spacings.xl

                            Label {
                                id: label
                                font: Fonts.title270
                                text: vMovie?.title ?? ""
                                color: Colors.grey50
                                wrapMode: Text.Wrap
                            }

                            FFSkeletonLoading {
                                id: skAbout
                                width: parent.width
                                color: Colors.grey500
                                radius: Radius.xl
                                visible: root.vIsLoading
                                height: 45
                            }

                            Row {
                                visible: !skAbout.visible
                                spacing: Spacings.md
                                width: parent.width

                                FFScoreBadget {
                                    vScore: vMovie?.average ?? ""
                                    vSize: FFScoreBadget.Size.Medium
                                    anchors.verticalCenter: parent.verticalCenter
                                }

                                Label {
                                    font: Fonts.caption170
                                    text: "24/10/2015"
                                    color: Colors.grey50
                                    anchors.verticalCenter: parent.verticalCenter
                                }

                                Row {
                                    spacing: Spacings.sm
                                    anchors.verticalCenter: parent.verticalCenter

                                    Label {
                                        font: Fonts.caption170
                                        text: "Reviews"
                                        color: Colors.grey50
                                        anchors.verticalCenter: parent.verticalCenter
                                    }

                                    Label {
                                        font: Fonts.caption170
                                        text: "( 155 )"
                                        color: Colors.orange300
                                        anchors.verticalCenter: parent.verticalCenter
                                    }
                                }
                            }

                            FFSkeletonLoading {
                                id: skGenres
                                width: parent.width
                                color: Colors.grey500
                                radius: Radius.xl
                                visible: root.vIsLoading
                                height: 45
                            }

                            Flow {
                                visible: !skGenres.visible
                                spacing: Spacings.md
                                width: parent.width

                                Repeater {
                                    model: vMovie?.genres ?? []

                                    FFBadget {

                                        required property string name

                                        vText: name
                                    }
                                }
                            }

                            FFSectionHeader {
                                vText: qsTr("Overview")
                            }

                            Label {
                                font: Fonts.label140
                                color: Colors.grey50
                                wrapMode: Text.Wrap
                                text: vMovie?.overview ?? ""
                                width: parent.width

                                FFSkeletonLoading {
                                    width: parent.width
                                    height: 145
                                    color: Colors.grey500
                                    radius: Radius.xl
                                    visible: root.vIsLoading
                                }
                            }
                        }
                    }

                    Column {
                        width: parent.width
                        spacing: Spacings.md

                        Row {
                            width: parent.width
                            spacing: Spacings.lg

                            FFSectionHeader {
                                vText: qsTr("Reviews")
                            }

                            FFSkeletonLoading {
                                width: writeReviewButton.width
                                height: writeReviewButton.height
                                color: Colors.grey500
                                radius: Radius.md
                                visible: root.vIsLoading
                                anchors.verticalCenter: parent.verticalCenter
                            }

                            FFButton {
                                id: writeReviewButton
                                vIcon: Icons.outlined.edit
                                text: vMovie?.myReview ? qsTr("Edit") : qsTr(
                                                             "Write")
                                vType: FFButton.Type.Secundary
                                height: Spacings.xl
                                anchors.verticalCenter: parent.verticalCenter
                                visible: !root.vIsLoading
                            }
                        }

                        ListView {
                            id: reviewsList
                            width: parent.width
                            height: childrenRect.height
                            clip: true
                            spacing: Spacings.md
                            visible: reviewsList.count !== 0
                        }

                        FeedbackReviewsFounded {
                            visible: !reviewsList.visible
                            width: parent.width
                        }
                    }
                }
            }
        }
    }

    FooterScroll {
        id: footerScroll
    }
}
