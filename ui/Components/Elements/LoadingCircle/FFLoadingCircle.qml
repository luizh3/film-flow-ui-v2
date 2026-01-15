import QtQuick

import Ui.Theme

FFLoadingCircleForm {
    id: root

    property int lineWidth: 8

    property int size: 75

    canvas.onPaint: function (mouse) {
        var ctx = canvas.getContext("2d")

        var x = root.width / 2
        var y = root.height / 2

        var radius = root.size / 2 - root.lineWidth
        var startAngle = (Math.PI / 180) * 270
        var fullAngle = startAngle + (Math.PI * 1.5)

        ctx.reset()

        ctx.lineCap = 'round'
        ctx.lineWidth = root.lineWidth

        ctx.beginPath()
        ctx.arc(x, y, radius, startAngle, fullAngle)
        ctx.strokeStyle = Colors.neutral100
        ctx.stroke()
    }

    canvas {
        RotationAnimator on rotation {
            running: true
            loops: Animation.Infinite
            from: 0
            to: 360
            duration: 1500
        }
    }
}
