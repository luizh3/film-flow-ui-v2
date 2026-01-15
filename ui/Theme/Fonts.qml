pragma Singleton

import QtQuick

QtObject {
    id: root

    readonly property string _font: "Poppins"

    readonly property font title170: ({
                                          "family": root._font,
                                          "pixelSize": 48,
                                          "weight": Font.Bold
                                      })

    readonly property font title270: ({
                                          "family": root._font,
                                          "pixelSize": 44,
                                          "weight": Font.Bold
                                      })

    readonly property font title370: ({
                                          "family": root._font,
                                          "pixelSize": 32,
                                          "weight": Font.Bold
                                      })

    readonly property font body270: ({
                                         "family": root._font,
                                         "pixelSize": 24,
                                         "weight": Font.Bold
                                     })

    readonly property font caption150: ({
                                            "family": root._font,
                                            "pixelSize": 20,
                                            "weight": Font.Medium
                                        })

    readonly property font caption160: ({
                                            "family": root._font,
                                            "pixelSize": 20,
                                            "weight": Font.DemiBold
                                        })

    readonly property font caption170: ({
                                            "family": root._font,
                                            "pixelSize": 20,
                                            "weight": Font.Bold
                                        })

    readonly property font caption240: ({
                                            "family": root._font,
                                            "pixelSize": 16,
                                            "weight": Font.Normal
                                        })

    readonly property font caption250: ({
                                            "family": root._font,
                                            "pixelSize": 16,
                                            "weight": Font.Medium
                                        })

    readonly property font caption260: ({
                                            "family": root._font,
                                            "pixelSize": 16,
                                            "weight": Font.DemiBold
                                        })

    readonly property font caption270: ({
                                            "family": root._font,
                                            "pixelSize": 16,
                                            "weight": Font.Bold
                                        })

    readonly property font label170: ({
                                          "family": root._font,
                                          "pixelSize": 14,
                                          "weight": Font.Bold
                                      })

    readonly property font label140: ({
                                          "family": root._font,
                                          "pixelSize": 14,
                                          "weight": Font.Normal
                                      })
}
