import QtQuick
import QtQuick.Window
import QtQuick.Controls

import Ui.Theme

FFToastForm {

    id: root
    parent: Overlay.overlay

    anchors {
        right: parent.right
        top: parent.top
        topMargin: Spacings.xl4
        rightMargin: Spacings.sm
    }

    enum Types {
        WARNING,
        ERROR,
        SUCCESS
    }

    function onEnded() {
        root.destroy()
    }

    closeButton.onClicked: root.onEnded()

    SequentialAnimation {
        running: true
        OpacityAnimator {
            target: root
            from: 0
            to: 1
            duration: 250
        }
        NumberAnimation {
            duration: 5000
        }
        OpacityAnimator {
            target: root
            from: 1
            to: 0
            duration: 250
        }

        onStopped: root.onEnded()
    }

    states: [
        State {
            name: FFToast.Types.WARNING
            PropertyChanges {
                root {
                    color: Colors.primary400
                }
            }
            PropertyChanges {
                root {
                    icon {
                        source: Icons.outlined.warning
                    }
                }
            }
        },
        State {
            name: FFToast.Types.ERROR
            PropertyChanges {
                root {
                    color: Colors.red400
                }
            }
            PropertyChanges {
                root {
                    icon {
                        source: Icons.outlined.error
                    }
                }
            }
        },
        State {
            name: FFToast.Types.SUCCESS
            PropertyChanges {
                root {
                    color: Colors.green400
                }
            }
            PropertyChanges {
                root {
                    icon {
                        source: Icons.outlined.check
                    }
                }
            }
        }
    ]
}
