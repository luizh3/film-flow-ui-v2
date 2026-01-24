#ifndef COLORITEMMODEL_H
#define COLORITEMMODEL_H

#include <QObject>

#include <theme_global.h>

#include "colorrole.h"

class THEME_EXPORT ColorItemModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ColorRole roleType READ roleType WRITE setRoleType NOTIFY roleTypeChanged FINAL)
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged FINAL)
    Q_PROPERTY(bool isSelected READ isSelected WRITE setIsSelected NOTIFY isSelectedChanged FINAL)
public:
    ColorItemModel(const ColorRole roleType, const QString &color, const bool isSelected);

    ColorRole roleType() const;
    void setRoleType(ColorRole newRoleType);

    QString color() const;
    void setColor(const QString &newColor);

    bool isSelected() const;
    void setIsSelected(bool newIsSelected);

signals:
    void roleTypeChanged();
    void colorChanged();
    void isSelectedChanged();

private:
    ColorRole _roleType;
    QString _color;
    bool _isSelected;
};

#endif // COLORITEMMODEL_H
