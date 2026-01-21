pragma Singleton

import QtQuick

import ThemeColorManager 1.0

QtObject {

    readonly property string secundary: grey800
    readonly property string error: red400

    readonly property string background: "#FFFFFF"
    readonly property string surface: grey600

    readonly property string neutral100: "#FFFFFF"

    readonly property string primary50: ThemeColorManager.primary50
    readonly property string primary100: ThemeColorManager.primary100
    readonly property string primary200: ThemeColorManager.primary200
    readonly property string primary300: ThemeColorManager.primary300
    readonly property string primary400: ThemeColorManager.primary400
    readonly property string primary500: ThemeColorManager.primary500
    readonly property string primary600: ThemeColorManager.primary600

    readonly property string grey50: "#ebebeb"
    readonly property string grey100: "#c0c0c0"
    readonly property string grey200: "#a2a2a2"
    readonly property string grey300: "#777777"
    readonly property string grey400: "#5d5d5d"
    readonly property string grey500: "#343434"
    readonly property string grey600: "#2f2f2f"
    readonly property string grey700: "#252525"
    readonly property string grey800: "#1d1d1d"
    readonly property string grey900: "#161616"

    readonly property string green400: "#4caf50"
    readonly property string red400: "#ea615d"

    readonly property string transparent: "transparent"
}
