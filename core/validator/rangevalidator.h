#ifndef RANGEVALIDATOR_H
#define RANGEVALIDATOR_H

#include <QQmlEngine>

#include "ffvalidator.h"

class RangeValidator : public FFValidator {
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY( int vMin READ min WRITE setMin NOTIFY minChanged FINAL )
    Q_PROPERTY( int vMax READ max WRITE setMax NOTIFY maxChanged FINAL )
public:
    RangeValidator();
    explicit RangeValidator( const int min, const int max);

    virtual State validate( QString& value, int& position ) const override;

    int min() const;
    void setMin(int newMin);

    int max() const;
    void setMax(int newMax);

signals:
    void minChanged();
    void maxChanged();

private:
    int _min;
    int _max;
};

#endif // RANGEVALIDATOR_H
