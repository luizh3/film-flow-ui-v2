pragma ComponentBehavior

import QtQuick

import Ui.Theme

FFRatingStarsForm {
    id: root

    function setInitialScore(score) {
        root.listView.currentIndex = score - 1
    }

    function _badgetColorByScore() {

        if (root.vCurrentValue <= 5) {
            return Colors.red400
        }

        if (root.vCurrentValue > 7) {
            return Colors.green400
        }

        return Colors.orange400
    }

    badgetScore.color: root._badgetColorByScore()

    listView.delegate: FFIcon {
        id: currentStar
        width: 24
        height: ListView.view.height

        required property int index

        source: Icons.filled.star
        vColor: ListView.view.currentIndex < index ? Colors.grey400 : Colors.orange500

        function _onSelected(index) {

            if (ListView.view.currentIndex === index) {
                ListView.view.currentIndex = -1
                return
            }

            ListView.view.currentIndex = index
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked: currentStar._onSelected(currentStar.index)
            hoverEnabled: true
        }
    }
}
