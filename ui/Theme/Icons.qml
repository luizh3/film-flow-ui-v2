pragma Singleton

import QtQuick

QtObject {
    id: root

    readonly property string _path: "qrc:/icons/%1"

    readonly property QtObject outlined: QtObject {
        readonly property string edit: _path.arg("edit")
        readonly property string play: _path.arg("play")
        readonly property string warning: _path.arg("warning")
        readonly property string error: _path.arg("error")
        readonly property string close: _path.arg("close")
        readonly property string search: _path.arg("search")
        readonly property string house: _path.arg("house")
        readonly property string favorite: _path.arg("favorite")
        readonly property string leftArrow: _path.arg("left-arrow")
        readonly property string upArrow: _path.arg("up-arrow")
        readonly property string rightArrow: _path.arg("right-arrow")
        readonly property string check: _path.arg("check")
        readonly property string replay: _path.arg("replay")
        readonly property string star: _path.arg("star-unfilled")
    }

    readonly property QtObject filled: QtObject {
        readonly property string star: _path.arg("star")
        readonly property string favorite: _path.arg("favorite-filled")
    }
}
