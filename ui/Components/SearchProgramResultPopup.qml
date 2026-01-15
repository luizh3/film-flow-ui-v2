import QtQuick

import Ui.Theme

SearchProgramResultPopupForm {
    id: root

    signal selected(var id, var tpProgram)

    function _handleSelected(id, tpProgram) {
        root.close()
        root.selected(id, tpProgram)
    }

    listView.delegate: SearchResultCard {

        required property string id
        required property string title
        required property string posterUrl
        required property double average
        required property bool isLoading
        required property string genres
        required property var tpProgram
        required property var overview

        vIsLoading: isLoading
        vPosterUrl: posterUrl
        vAverage: average
        vGenres: genres
        vTitle: title
        vOverview: overview

        width: ListView.view.width

        onSelected: root._handleSelected(id, tpProgram)
    }

    function positionerByElement(element) {
        const elementInstance = element.mapToItem(parent, 0, element.height)
        root.x = elementInstance.x
        root.y = elementInstance.y + Spacings.md
    }
}
