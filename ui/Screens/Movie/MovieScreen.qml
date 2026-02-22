import QtQuick 2.15

import Ui.Components
import Ui.Theme
import Ui.Screens

import Presenter.Controls

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
        const reviewModal = NavigateManager.navigateModal(
                              reviewProgramModalComponent, {
                                  "vProgramType": vMovie.programType,
                                  "vProgramTitle": vMovie.title,
                                  "vMovieId": vMovie.id
                              })

        reviewModal.success.connect(function doSuccess(newReview) {
            reviewsListModel.resetReviews()
            control.doRefresh(root.vMovieId, root.vProgramType)
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

    vIsLoadingReviews: reviewsListControl.model.isLoading

    reviewsList.model: reviewsListControl.model

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
        required property var author
        required property string createdDate

        vReviewId: programReview.id
        vProgramTitle: programReview.programTitle
        vIsShowAboutMovie: false
        vLoadingColor: Colors.grey500
        vIsLoading: programReview.isLoading
        vScore: programReview.score
        vDateCreated: programReview.createdDate
        vUserImage: programReview.author?.avatarUrl
                    || "qrc:/imagens/no-user.png"
        vTitle: programReview.title
        vUserName: programReview.author?.name ?? ""
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

    ReviewsListControl {
        id: reviewsListControl
        fetchModeType: ReviewsListControl.ByProgram
        movieId: root.vMovieId
    }
}
