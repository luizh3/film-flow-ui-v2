#ifndef THEMECOLORMANAGER_H
#define THEMECOLORMANAGER_H

#include <QObject>

#include <theme_global.h>

#include <models/colorrole.h>
#include <models/themecolormodel.h>

class THEME_EXPORT ThemeColorManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString primary50 READ primary50 NOTIFY themeChanged)
    Q_PROPERTY(QString primary100 READ primary100 NOTIFY themeChanged)
    Q_PROPERTY(QString primary200 READ primary200 NOTIFY themeChanged)
    Q_PROPERTY(QString primary300 READ primary300 NOTIFY themeChanged)
    Q_PROPERTY(QString primary400 READ primary400 NOTIFY themeChanged)
    Q_PROPERTY(QString primary500 READ primary500 NOTIFY themeChanged)
    Q_PROPERTY(QString primary600 READ primary600 NOTIFY themeChanged)
public:
    ThemeColorManager();

    static ThemeColorManager *instance();

    void setTheme(const ThemeColorModel &theme);

    ColorRole roleType() const;
    void setRoleType(ColorRole newRoleType);

    QString primary50() const;
    QString primary100() const;
    QString primary200() const;
    QString primary300() const;
    QString primary400() const;
    QString primary500() const;
    QString primary600() const;

signals:
    void themeChanged();

private:
    ColorRole _roleType;
    ThemeColorModel _themeColor;
};

#endif // THEMECOLORMANAGER_H
