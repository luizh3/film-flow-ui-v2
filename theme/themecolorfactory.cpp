#include "themecolorfactory.h"

ThemeColor ThemeColorFactory::getOrange()
{
    return {QStringLiteral("#fef2e6"),  // 50
            QStringLiteral("#fcd6b0"),  // 100
            QStringLiteral("#fac38a"),  // 200
            QStringLiteral("#f8a754"),  // 300
            QStringLiteral("#f79633"),  // 400
            QStringLiteral("#f57c00"),  // 500
            QStringLiteral("#df7100")}; // 600
}

ThemeColor ThemeColorFactory::getPurple()
{
    return {
        QStringLiteral("#f3e5f5"), // 50
        QStringLiteral("#e1bee7"), // 100
        QStringLiteral("#ce93d8"), // 200
        QStringLiteral("#ba68c8"), // 300
        QStringLiteral("#ab47bc"), // 400
        QStringLiteral("#9c27b0"), // 500
        QStringLiteral("#8e24aa")  // 600
    };
}

ThemeColor ThemeColorFactory::getBlue()
{
    return {
        QStringLiteral("#e3f2fd"), // 50
        QStringLiteral("#bbdefb"), // 100
        QStringLiteral("#90caf9"), // 200
        QStringLiteral("#64b5f6"), // 300
        QStringLiteral("#42a5f5"), // 400
        QStringLiteral("#2196f3"), // 500
        QStringLiteral("#1e88e5")  // 600
    };
}

ThemeColor ThemeColorFactory::getGreen()
{
    return {
        QStringLiteral("#e8f5e9"), // 50
        QStringLiteral("#c8e6c9"), // 100
        QStringLiteral("#a5d6a7"), // 200
        QStringLiteral("#81c784"), // 300
        QStringLiteral("#66bb6a"), // 400
        QStringLiteral("#4caf50"), // 500
        QStringLiteral("#43a047")  // 600
    };
}

ThemeColor ThemeColorFactory::getTeal()
{
    return {
        QStringLiteral("#e0f2f1"), // 50
        QStringLiteral("#b2dfdb"), // 100
        QStringLiteral("#80cbc4"), // 200
        QStringLiteral("#4db6ac"), // 300
        QStringLiteral("#26a69a"), // 400
        QStringLiteral("#009688"), // 500
        QStringLiteral("#00897b")  // 600
    };
}
