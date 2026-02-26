#ifndef THEMECOLORFACTORY_H
#define THEMECOLORFACTORY_H

#include <models/colorrole.h>
#include <models/themecolormodel.h>

#include <theme_global.h>

class THEME_EXPORT ThemeColorFactory
{
public:
    static ThemeColorModel byRole(const ColorRole colorRole);

    static ThemeColorModel getOrange();
    static ThemeColorModel getPurple();
    static ThemeColorModel getBlue();
    static ThemeColorModel getGreen();
    static ThemeColorModel getTeal();
};

#endif // THEMECOLORFACTORY_H
