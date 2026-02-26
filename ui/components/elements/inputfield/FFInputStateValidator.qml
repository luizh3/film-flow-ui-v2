import QtQuick

QtObject {

    property list<FFTextField> inputs: []

    property bool isValid: inputs.length > 0 && inputs.every(
                               input => input.enabled && input.vIsAcceptable)
}
