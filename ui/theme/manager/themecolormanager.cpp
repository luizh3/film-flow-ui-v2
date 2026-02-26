#include "themecolormanager.h"

ThemeColorManager::ThemeColorManager()
    : _themeColor{}
{}

ThemeColorManager *ThemeColorManager::instance()
{
    static ThemeColorManager themeColorManager;
    return &themeColorManager;
}

void ThemeColorManager::setTheme(const ThemeColorModel &theme)
{
    _themeColor = theme;
    emit themeChanged();
}

QString ThemeColorManager::primary50() const
{
    return _themeColor.primary50;
}

QString ThemeColorManager::primary100() const
{
    return _themeColor.primary100;
}

QString ThemeColorManager::primary200() const
{
    return _themeColor.primary200;
}

QString ThemeColorManager::primary300() const
{
    return _themeColor.primary300;
}

QString ThemeColorManager::primary400() const
{
    return _themeColor.primary400;
}

QString ThemeColorManager::primary500() const
{
    return _themeColor.primary500;
}

QString ThemeColorManager::primary600() const
{
    return _themeColor.primary600;
}

ColorRole ThemeColorManager::roleType() const
{
    return _roleType;
}

void ThemeColorManager::setRoleType(ColorRole newRoleType)
{
    _roleType = newRoleType;
}
