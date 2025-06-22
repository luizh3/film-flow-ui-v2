import QtQuick

QtObject {

    property list<FFTextField> inputs : [];

    function isValid() {
        return inputs.every( ( current ) => {
            return current.enabled && current.vIsValid;
        } )
    }

}
