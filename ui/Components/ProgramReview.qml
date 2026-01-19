import QtQuick

import Ui.Components.Elements

import controls 1.0

ProgramReviewForm {
    id: root

    signal aboutMovie

    function _handleExpanded() {
        root.vIsExpanded = !root.vIsExpanded
    }

    function _handleAboutMovie() {
        root.aboutMovie()
    }

    function _handleLiked(isLiked) {

        if (isLiked) {
            control.like(root.vReviewId)
            return
        }

        control.unlike(root.vReviewId)
    }

    function onLoaderReady() {

        if (loader.item instanceof FFSkeletonLoading) {
            return
        }

        loader.item.likedButton.selected.connect(root._handleLiked)
        loader.item.aboutMovieMouse.clicked.connect(root._handleAboutMovie)
        loader.item.readMoreMouse.clicked.connect(root._handleExpanded)
        loader.item.readMoreLabel.text = root.vIsExpanded ? qsTr("Read less") : qsTr(
                                                                "Read more...")
    }

    function _handleRollbackLike() {
        loader.item.likedButton.doDeselected()
    }

    function _handleRollbackUnlike() {
        loader.item.likedButton.doSelected()
    }

    ProgramReviewControl {
        id: control

        onRollbackLike: root._handleRollbackLike()
        onRollbackUnlike: root._handleRollbackUnlike()
    }

    loader.onLoaded: root.onLoaderReady()

    states: [
        State {
            name: "loading"
            when: root.vIsLoading

            PropertyChanges {
                root {
                    loader {
                        sourceComponent: root.loadingComponent
                    }
                }
            }
        },
        State {
            name: "idle"
            when: !root.vIsLoading

            PropertyChanges {
                root {
                    loader {
                        sourceComponent: root.idleComponent
                    }
                }
            }
        }
    ]
}
