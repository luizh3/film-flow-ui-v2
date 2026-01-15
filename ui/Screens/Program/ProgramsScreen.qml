import QtQuick
import QtQuick.Controls
import Ui.Components

import Ui.Screens

ProgramsScreenForm {
    id: root

    moviesGrid.delegate: CardMovie {

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

        onSelected: root._handleMovieSelected(id, tpProgram)
    }

    function _handleMovieSelected(id, tpProgram) {
        const element = screenManager.navigate(ScreenManager.Route.MOVIE, {
                                                   "vMovieId": id,
                                                   "vProgramType": tpProgram
                                               })
        element.doStart()
    }

    function _handleSearch(text) {
        root.vDsQuery = text
    }

    header.onSearch: text => root._handleSearch(text)
    header.profileOption.onSelected: () => screenManager.navigate(
                                         ScreenManager.Route.PROFILE)
}
