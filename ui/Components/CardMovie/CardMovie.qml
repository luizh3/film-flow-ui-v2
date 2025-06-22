import QtQuick

CardMovieForm {
    id: root

    state: "loading"

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
