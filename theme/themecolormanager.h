#ifndef THEMECOLORMANAGER_H
#define THEMECOLORMANAGER_H

#include <QObject>

#include "themecolor.h"

class ThemeColorManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor primary50 READ primary50 NOTIFY themeChanged)
    Q_PROPERTY(QColor primary100 READ primary100 NOTIFY themeChanged)
    Q_PROPERTY(QColor primary200 READ primary200 NOTIFY themeChanged)
    Q_PROPERTY(QColor primary300 READ primary300 NOTIFY themeChanged)
    Q_PROPERTY(QColor primary400 READ primary400 NOTIFY themeChanged)
    Q_PROPERTY(QColor primary500 READ primary500 NOTIFY themeChanged)
    Q_PROPERTY(QColor primary600 READ primary600 NOTIFY themeChanged)
public:
    ThemeColorManager();

    static ThemeColorManager *instance();

    void setTheme(const ThemeColor &theme);

    QColor primary50() const;
    QColor primary100() const;
    QColor primary200() const;
    QColor primary300() const;
    QColor primary400() const;
    QColor primary500() const;
    QColor primary600() const;

signals:
    void themeChanged();

private:
    ThemeColor _themeColor;
};

#endif // THEMECOLORMANAGER_H
