import QtQuick
import Ui.Components

import Ui.Screens
import Ui.Models

ProgramsScreenForm {
    id: root

    function _handleMovieSelected(id, tpProgram) {
        const element = NavigateManager.navigateScreen(
                          ScreenManager.Route.MOVIE, {
                              "vMovieId": id,
                              "vProgramType": tpProgram
                          })
        element.doStart()
    }

    function _handleSearch(text) {
        root.vDsQuery = text
    }

    function _handleTotalProgramsFound(totalPrograms) {
        root.foundResultsLabel.text = qsTr("Found %0 results").arg(
                    totalPrograms)
    }

    moviesGrid.model: SearchProgramListModel {
        onTotalProgramsFound: totalPrograms => root._handleTotalProgramsFound(
                                  totalPrograms)
        vDsQuery: root.vDsQuery
    }

    header.onSearch: text => root._handleSearch(text)
    header.profileOption.onSelected: () => NavigateManager.navigateScreen(
                                         ScreenManager.Route.PROFILE)

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
}
