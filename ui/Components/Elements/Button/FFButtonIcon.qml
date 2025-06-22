import QtQuick

import Ui.Theme

FFButtonIconForm {
    id: root

    enum Type {
        Secundary,
        FlatPrimary,
        FlatSecundary
    }

    property int vType: FFButtonIcon.Type.Secundary

    onVTypeChanged: root._setType()

    function _toSecundaryType() {        
        root._color = Colors.secundary;
        root._hoverColor = Colors.secundary;
        root._colorIconHover = Colors.neutral100;
        root._colorIcon = Colors.neutral100;
        root._radius = Radius.sm;
    }

    function toFlatSecundary() {
        root._color = "transparent";
        root._hoverColor = Colors.grey300;
        root._colorIconHover = Colors.neutral100;
        root._colorIcon = Colors.grey400;
        root._radius = Radius.rounded
    }

    function toFlatPrimary() {
        root._color = "transparent";
        root._hoverColor = Colors.grey300;
        root._colorIconHover = Colors.neutral100;
        root._colorIcon = Colors.neutral100;
        root._radius = Radius.rounded
    }

    function _setType() {
        switch( root.vType ) {
        case FFButtonIcon.Type.Secundary:
            root._toSecundaryType()
            break;
        case FFButtonIcon.Type.FlatPrimary:
            root.toFlatPrimary();
            break;
        case FFButtonIcon.Type.FlatSecundary:
            root.toFlatSecundary();
            break;
        }
    }

    Component.onCompleted: root._setType()

}
