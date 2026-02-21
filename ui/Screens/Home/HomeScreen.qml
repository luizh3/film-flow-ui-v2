pragma ComponentBehavior

import QtQuick
import Presenter.Controls

import Ui.Screens
import Ui.Components
import Ui.Theme

HomeScreenForm {
    id: root

    function _handleSectionsChanged(sections) {
        root.vSections = sections
    }

    function _doStart() {
        control.doStart()
    }

    function _handleMovieSelected(id, tpProgram) {
        const element = NavigateManager.navigateScreen(
                          ScreenManager.Route.MOVIE, {
                              "vMovieId": id,
                              "vProgramType": tpProgram
                          })
        element.doStart()
    }

    function isContentOverlay() {
        return scrolView.originY !== scrolView.contentY
    }

    function _resetContentSrollView() {
        scrolView.contentY = 0
    }

    Component.onCompleted: root._doStart()

    header.onProgramSelected: (id, tpProgram) => _handleMovieSelected(id,
                                                                      tpProgram)

    header.profileOption.onSelected: () => NavigateManager.navigateScreen(
                                         ScreenManager.Route.PROFILE)

    header.vOpacity: root.isContentOverlay() ? 1.0 : 0.0

    footerScroll.buttonScroll.onPressed: root._resetContentSrollView()

    scrolView {
        Behavior on contentY {
            NumberAnimation {
                duration: Durations.normal
                easing.type: Easing.OutCubic
            }
        }
    }

    footerScroll.opacity: scrolView.contentY > 300 ? 1 : 0

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

    HomeControl {
        id: control

        onSectionsChanged: sections => root._handleSectionsChanged(sections)
    }
}
