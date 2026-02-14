import QtQuick 2.15

import Ui.Components
import Ui.Theme
import Ui.Models
import Ui.Screens

import Controls 1.0

MovieScreenForm {
    id: root

    function _handleCancel() {
        control.doCancel()
    }

    function doStart() {
        control.doStart(root.vMovieId, root.vProgramType)
    }

    function _handleFinished() {
        root.close()
    }

    function _handleWriteReview() {
        const reviewModal = popupManager.push(reviewProgramModalComponent, {
                                                  "vProgramType": vMovie.programType,
                                                  "vProgramTitle": vMovie.title,
                                                  "vMovieId": vMovie.id
                                              })

        reviewModal.success.connect(function doSuccess(newReview) {
            reviewsListModel.resetReviews()
        })

        reviewModal.setReview(vMovie.myReview)
    }

    function _resetContentScrollFlickable() {
        scrollFlickable.contentY = 0
    }

    vIsLoading: control.isLoading
    vMovie: control.movie

    backButtonNavigation.onClicked: root._handleCancel()

    footerScroll.buttonScroll.onPressed: root._resetContentScrollFlickable()

    footerScroll.opacity: scrollFlickable.contentY > 300 ? 1 : 0

    writeReviewButton.onClicked: root._handleWriteReview()

    vIsLoadingReviews: reviewsListModel.isLoading

    reviewsList.model: ReviewsListModel {
        id: reviewsListModel
        fetchModeType: ReviewsListModel.ByProgram
        movieId: root.vMovieId
    }

    scrollFlickable {
        Behavior on contentY {
            NumberAnimation {
                duration: Durations.normal
                easing.type: Easing.OutCubic
            }
        }
    }

    reviewsList.delegate: ProgramReview {
        id: programReview

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

        vReviewId: programReview.id
        vProgramTitle: programReview.programTitle
        vIsShowAboutMovie: false
        vLoadingColor: Colors.grey500
        vIsLoading: programReview.isLoading
        vScore: programReview.score
        vDateCreated: "24/10/2025"
        vUserImage: "https://images.pexels.com/photos/104827/cat-pet-animal-domestic-104827.jpeg" // TODO change for te user photo
        vTitle: programReview.title
        vUserName: "test"
        vDescription: programReview.description
        vIsLikedByMe: programReview.isLikedByMe
        vLikesCount: programReview.likesCount

        width: ListView.view.width
    }

    Component {
        id: reviewProgramModalComponent

        ReviewProgramModal {}
    }

    MovieControl {
        id: control

        onFinished: root._handleFinished()
    }
}
