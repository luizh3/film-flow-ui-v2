pragma ComponentBehavior: Bound

SideBarSectionMenuForm {
    id: root

    signal selected( var vType )

    required property int vTypeSelected

    delegate: SideBarItem {

       width: root._widthDelegate

       onClicked: root.selected( vType );

       vSelected: root.vTypeSelected === vType
    }

}
