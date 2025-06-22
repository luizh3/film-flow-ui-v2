pragma ComponentBehavior: Bound

import QtQuick
import QtQuick.Effects

import Ui.Theme

Image {
    id: root

    property string vColor: Colors.neutral100

    layer.enabled: true
    layer.effect: MultiEffect {
        brightness: 1.0
        colorization: 1.0
        colorizationColor: root.vColor
    }
}
