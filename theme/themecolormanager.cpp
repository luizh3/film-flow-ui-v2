#include "themecolormanager.h"

ThemeColorManager::ThemeColorManager()
    : _themeColor{}
{}

ThemeColorManager *ThemeColorManager::instance()
{
    static ThemeColorManager themeColorManager;
    return &themeColorManager;
}

void ThemeColorManager::setTheme(const ThemeColor &theme)
{
    _themeColor = theme;
    emit themeChanged();
}

QColor ThemeColorManager::primary50() const
{
    return _themeColor.primary50;
}

QColor ThemeColorManager::primary100() const
{
    return _themeColor.primary100;
}

QColor ThemeColorManager::primary200() const
{
    return _themeColor.primary200;
}

QColor ThemeColorManager::primary300() const
{
    return _themeColor.primary300;
}

QColor ThemeColorManager::primary400() const
{
    return _themeColor.primary400;
}

QColor ThemeColorManager::primary500() const
{
    return _themeColor.primary500;
}

QColor ThemeColorManager::primary600() const
{
    return _themeColor.primary600;
}
