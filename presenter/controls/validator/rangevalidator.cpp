#include "rangevalidator.h"

RangeValidator::RangeValidator() :
    _min{0},
    _max{0}
{}

RangeValidator::RangeValidator(const int min, const int max) :
    _min{min},
    _max{max}
{}

QValidator::State RangeValidator::validate( QString& value, int &position ) const {

    if( value.length() < _min ) {
        _error = QString("Enter at least %0 characters").arg( _min );
        return QValidator::State::Intermediate;
    }

    if( value.length() > _max ) {
        return QValidator::State::Invalid;
    }

    return QValidator::State::Acceptable;
}

int RangeValidator::min() const
{
    return _min;
}

void RangeValidator::setMin(int newMin)
{
    if (_min == newMin) {
        return;
    }
    _min = newMin;
    emit minChanged();
}

int RangeValidator::max() const
{
    return _max;
}

void RangeValidator::setMax(int newMax)
{
    if (_max == newMax) {
        return;
    }
    _max = newMax;
    emit maxChanged();
}
