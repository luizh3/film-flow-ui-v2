import QtQuick

import Ui.Components.Elements

ProgramReviewForm {
    id: root

    signal aboutMovie

    function _handleExpanded() {
        root.vIsExpanded = !root.vIsExpanded
    }

    function _handleAboutMovie() {
        root.aboutMovie()
    }

    function onLoaderReady() {

        if (loader.item instanceof FFSkeletonLoading) {
            return
        }

        loader.item.aboutMovieMouse.clicked.connect(root._handleAboutMovie)
        loader.item.readMoreMouse.clicked.connect(root._handleExpanded)
        loader.item.readMoreLabel.text = root.vIsExpanded ? qsTr("Read less") : qsTr(
                                                                "Read more...")
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
