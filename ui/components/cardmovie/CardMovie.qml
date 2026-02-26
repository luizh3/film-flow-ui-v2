import QtQuick

CardMovieForm {
    id: root

    signal selected

    mouseArea.onClicked: root.selected()
}
