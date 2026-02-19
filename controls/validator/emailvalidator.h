#ifndef EMAILVALIDATOR_H
#define EMAILVALIDATOR_H

#include <QQmlEngine>

#include "ffvalidator.h"

class EmailValidator : public FFValidator {
    Q_OBJECT
    QML_ELEMENT
public:
    virtual State validate( QString& value, int& position ) const override;
};

#endif // EMAILVALIDATOR_H
