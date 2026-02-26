import QtQuick

FFButtonNavigationForm {
    id: root

    signal clicked

    buttonIcon.onClicked: root.clicked()
}
