#include "coloritemmodel.h"

ColorItemModel::ColorItemModel(const ColorRole roleType, const QString &color, const bool isSelected)
    : _roleType{roleType}
    , _color{color}
    , _isSelected{isSelected}
{}

ColorRole ColorItemModel::roleType() const
{
    return _roleType;
}

void ColorItemModel::setRoleType(ColorRole newRoleType)
{
    if (_roleType == newRoleType) {
        return;
    }

    _roleType = newRoleType;
    emit roleTypeChanged();
}

QString ColorItemModel::color() const
{
    return _color;
}

void ColorItemModel::setColor(const QString &newColor)
{
    if (_color == newColor) {
        return;
    }

    _color = newColor;
    emit colorChanged();
}

bool ColorItemModel::isSelected() const
{
    return _isSelected;
}

void ColorItemModel::setIsSelected(bool newIsSelected)
{
    if (_isSelected == newIsSelected) {
        return;
    }

    _isSelected = newIsSelected;
    emit isSelectedChanged();
}
