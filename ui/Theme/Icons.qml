pragma Singleton

import QtQuick

QtObject {
    id: root

    readonly property string _path: "qrc:/icons/%1"

    readonly property QtObject outlined: QtObject {
        readonly property string edit: root._path.arg("edit")
        readonly property string play: root._path.arg("play")
        readonly property string warning: root._path.arg("warning")
        readonly property string error: root._path.arg("error")
        readonly property string close: root._path.arg("close")
        readonly property string search: root._path.arg("search")
        readonly property string house: root._path.arg("house")
        readonly property string favorite: root._path.arg("favorite")
        readonly property string leftArrow: root._path.arg("left-arrow")
        readonly property string upArrow: root._path.arg("up-arrow")
        readonly property string rightArrow: root._path.arg("right-arrow")
        readonly property string check: root._path.arg("check")
        readonly property string replay: root._path.arg("replay")
        readonly property string star: root._path.arg("star-unfilled")
    }

    readonly property QtObject filled: QtObject {
        readonly property string star: root._path.arg("star")
        readonly property string favorite: root._path.arg("favorite-filled")
    }
}
