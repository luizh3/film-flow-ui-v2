import QtQuick

import Presenter.Models
import Presenter.Controls

import Ui.Components.Elements

ReviewProgramModalForm {

    id: root

    signal success(var newReview)

    required property string vProgramTitle
    required property string vMovieId
    required property var vProgramType

    property ReviewModel review: ReviewModel {
        title: root.titleField.vText
        description: root.descriptionField.vText
        score: root.ratingStars.vCurrentValue
        movieId: root.vMovieId
        programTitle: root.vProgramTitle
        // TODO Because the enum is in the core, qmlls is unable to understand where its definition is located.
        programType: root.vProgramType
    }

    function setReview(reviewBind) {

        if (!reviewBind) {
            return
        }

        root.titleField.vText = reviewBind.title
        root.descriptionField.vText = reviewBind.description
        root.ratingStars.setInitialScore(reviewBind.score)
        root.vMovieId = reviewBind.movieId
        root.review.reviewId = reviewBind.reviewId
    }

    closeButton.onClicked: root.close()
    cancelButton.onClicked: root.close()
    confirmButton.onClicked: root._handleConfirm()

    function _handleOnError(message) {
        root.setEnabledFields(true)
        root.confirmButton.vState = FFButton.State.Active
        root.confirmButton.vType = FFButton.Type.Error
    }

    function _handleOnSuccess(newReview) {
        root.success(newReview)
        root.close()
    }

    function _handleConfirm() {
        root.setEnabledFields(false)
        root.confirmButton.vState = FFButton.State.Loading
        control.doConfirm(root.review)
    }

    function setEnabledFields(isEnabled) {
        root.enabled = isEnabled
    }

    programTitleLabel.text: root.vProgramTitle

    ReviewProgramModalControl {
        id: control

        onError: message => root._handleOnError(message)
        onSuccess: newReview => root._handleOnSuccess(newReview)
    }
}
