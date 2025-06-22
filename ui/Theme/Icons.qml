pragma Singleton
import QtQuick

QtObject {
    id: root

    readonly property string _path: "qrc:/icons/%1"

    readonly property string search: _path.arg("search")
    readonly property string house: _path.arg("house")
    readonly property string favorite: _path.arg("favorite")

}
