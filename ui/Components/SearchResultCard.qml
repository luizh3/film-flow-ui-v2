import QtQuick

SearchResultCardForm {
    id: root

    signal selected

    state: "loading"

    mouseArea.onClicked: root.selected()

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
