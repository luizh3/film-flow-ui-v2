pragma ComponentBehavior

import QtQuick

import Ui.Theme
import Ui.Components

// TODO maybe create a Ui.Screens.Commons to move screenManager
import Ui.Screens

import Presenter.Controls

ReviewScreenForm {
    id: root

    function _handleMovieSelected(id, tpProgram) {
        const element = NavigateManager.navigateScreen(
                          ScreenManager.Route.MOVIE, {
                              "vMovieId": id,
                              "vProgramType": tpProgram
                          })
        element.doStart()
    }

    function _handleTotalReviewsFound(totalReviews) {
        foundResultsLabel.text = qsTr("Found %0 results").arg(totalReviews)
    }

    header.searchProgramTextField.enabled: false
    header.searchProgramTextField.vPlaceHolderText: qsTr("Search for a review")
    header.profileOption.onSelected: () => NavigateManager.navigateScreen(
                                         ScreenManager.Route.PROFILE)

    Connections {
        target: reviewsListControl

        function onTotalReviewsFound(totalReviews) {
            root._handleTotalReviewsFound(totalReviews)
        }
    }

    reviewsList.model: reviewsListControl.model

    ReviewsListControl {
        id: reviewsListControl
        fetchModeType: ReviewsListControl.ByUser
    }

    reviewsList.delegate: Item {
        id: currentDelegate
        width: ListView.view.width
        height: childrenRect.height

        required property string description
        required property string title
        required property double score
        required property string id
        required property bool isLoading
        required property string movieId
        required property string programTitle
        required property var programType
        required property bool isLikedByMe
        required property int likesCount
        required property var author

        ProgramReview {
            vReviewId: currentDelegate.id
            vProgramTitle: currentDelegate.programTitle
            vIsShowAboutMovie: true
            vLoadingColor: Colors.grey600
            vIsLoading: currentDelegate.isLoading
            vScore: currentDelegate.score
            width: parent.width - (2 * Spacings.xl3)
            anchors.horizontalCenter: parent.horizontalCenter
            vDateCreated: "24/10/2025"
            vUserImage: currentDelegate.author?.avatarUrl
                        || "qrc:/imagens/no-user.png"
            vTitle: currentDelegate.title
            vUserName: currentDelegate.author?.name ?? ""
            vDescription: currentDelegate.description
            vIsLikedByMe: currentDelegate.isLikedByMe
            vLikesCount: currentDelegate.likesCount

            onAboutMovie: root._handleMovieSelected(currentDelegate.movieId,
                                                    currentDelegate.programType)
        }
    }
}
