import QtQuick 2.15

import Ui.Components
import Ui.Theme
import Ui.Models

import controls 1.0

MovieScreenForm {
    id: root

    backButtonNavigation.onClicked: root._handleCancel()

    function _handleCancel() {
        control.doCancel()
    }

    function doStart() {
        control.doStart(root.vMovieId, root.vProgramType)
    }

    function _handleFinished() {
        root.close()
    }

    vIsLoading: control.isLoading
    vMovie: control.movie

    MovieControl {
        id: control

        onFinished: root._handleFinished()
    }

    footerScroll.buttonScroll.onPressed: function () {
        scrollFlickable.contentY = 0
    }

    footerScroll.opacity: scrollFlickable.contentY > 300 ? 1 : 0

    writeReviewButton.onClicked: root._handleWriteReview()

    reviewsList.model: ReviewsListModel {
        id: reviewsListModel
        fetchModeType: ReviewsListModel.ByProgram
        movieId: root.vMovieId
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
        width: ListView.view.width
        vDateCreated: "24/10/2025"
        vUserImage: "https://images.pexels.com/photos/104827/cat-pet-animal-domestic-104827.jpeg"
        vTitle: programReview.title
        vUserName: "test"
        vDescription: programReview.description
        vIsLikedByMe: programReview.isLikedByMe
        vLikesCount: programReview.likesCount
    }

    function _handleWriteReview() {
        const reviewModal = popupManager.push(reviewProgramModalComponent, {
                                                  "vProgramType": vMovie.programType,
                                                  "vProgramTitle": vMovie.title,
                                                  "vMovieId": vMovie.id
                                              })

        reviewModal.success.connect(function doSuccess(newReview) {
            control.doUpdateReview(newReview)
        })

        reviewModal.setReview(vMovie.myReview)
    }

    Component {
        id: reviewProgramModalComponent

        ReviewProgramModal {}
    }
}
