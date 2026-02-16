pragma ComponentBehavior

import QtQuick

import Ui.Theme
import Ui.Models
import Ui.Components

// TODO maybe create a Ui.Screens.Commons to move screenManager
import Ui.Screens

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
        target: reviewsListModel

        function onTotalReviewsFound(totalReviews) {
            root._handleTotalReviewsFound(totalReviews)
        }
    }

    reviewsList.model: ReviewsListModel {
        id: reviewsListModel
        fetchModeType: ReviewsListModel.ByUser
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

        ProgramReview {
            vReviewId: id
            vProgramTitle: currentDelegate.programTitle
            vIsShowAboutMovie: true
            vLoadingColor: Colors.grey600
            vIsLoading: currentDelegate.isLoading
            vScore: currentDelegate.score
            width: parent.width - (2 * Spacings.xl3)
            anchors.horizontalCenter: parent.horizontalCenter
            vDateCreated: "24/10/2025"
            vUserImage: "https://i.pinimg.com/736x/31/4c/2b/314c2b6b26e17f4235697ecb8e4cd87e.jpg"
            vTitle: currentDelegate.title
            vUserName: "test"
            vDescription: currentDelegate.description
            vIsLikedByMe: currentDelegate.isLikedByMe
            vLikesCount: currentDelegate.likesCount

            onAboutMovie: root._handleMovieSelected(currentDelegate.movieId,
                                                    currentDelegate.programType)
        }
    }
}
