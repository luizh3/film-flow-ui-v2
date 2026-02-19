import Ui.Components

import Controls 1.0

CardMovieListForm {
    id: root

    signal selected(var id, var tpProgram)

    function _handleSliderIncrement() {
        let newIndex = Math.min(listView.currentIndex + 4, listView.count - 1)
        listView.currentIndex = newIndex
    }

    function _handleSliderDecresce() {
        let newIndex = Math.max(listView.currentIndex - 4, 0)
        listView.currentIndex = newIndex
    }

    buttonNext.onClicked: root._handleSliderIncrement()
    buttonPrevius.onClicked: root._handleSliderDecresce()

    listView.model: moviesListControl.model

    listView.delegate: CardMovie {

        required property string id
        required property string title
        required property string posterUrl
        required property double average
        required property bool isLoading
        required property var tpProgram

        vSource: posterUrl
        vAverage: average
        vTitle: title
        vIsLoading: isLoading

        onSelected: root.selected(id, tpProgram)
    }

    MoviesListControl {
        id: moviesListControl
        tpProgram: root.vTypeProgram
        key: root.vKey
    }
}
