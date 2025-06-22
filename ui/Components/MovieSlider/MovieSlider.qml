import QtQuick

import controls 1.0

MovieSliderForm {
    id: root

    function _updateValues(movie) {
        root.vBackdropUrl = movie.backdropUrl
        root.vTitle = movie.title
        root.vAverage = movie.average
    }

    MovieSliderControl {
        id: control

        onMovieChanged: function (movie) {
            root._updateValues(movie)
            root.vIsLoading = false
        }
    }

    function _doStart() {
        control.doStart()
    }

    Component.onCompleted: root._doStart()

    buttonNext.onClicked: control.next()
    buttonPrevius.onClicked: control.previous()
}
