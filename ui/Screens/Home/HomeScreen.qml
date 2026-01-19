import QtQuick
import controls 1.0

import Ui.Screens
import Ui.Components

HomeScreenForm {
    id: root

    function _handleSectionsChanged(sections) {
        root.vSections = sections
    }

    HomeControl {
        id: control

        onSectionsChanged: sections => root._handleSectionsChanged(sections)
    }

    function _doStart() {
        control.doStart()
    }

    Component.onCompleted: root._doStart()

    function _handleMovieSelected(id, tpProgram) {
        const element = screenManager.navigate(ScreenManager.Route.MOVIE, {
                                                   "vMovieId": id,
                                                   "vProgramType": tpProgram
                                               })
        element.doStart()
    }

    header.onProgramSelected: (id, tpProgram) => _handleMovieSelected(id,
                                                                      tpProgram)

    header.profileOption.onSelected: () => screenManager.navigate(
                                         ScreenManager.Route.PROFILE)

    repeaterSections.delegate: CardMovieList {
        required property string name
        required property string key
        required property int tpProgram

        width: parent.width
        height: 350
        vTitle: name
        vKey: key
        vTypeProgram: tpProgram

        onSelected: id => root._handleMovieSelected(id, tpProgram)
    }
}
