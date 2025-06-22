#ifndef PASSWORDVALIDATOR_H
#define PASSWORDVALIDATOR_H

#include <QQmlEngine>

#include "rangevalidator.h"

class PasswordValidator : public RangeValidator {
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(TypeValidation vTypeValidation READ tpValidation WRITE setTpValidation NOTIFY tpValidationChanged FINAL)
    Q_PROPERTY(QString vRepeatPassword READ repeatPassword WRITE setRepeatPassword NOTIFY repeatPasswordChanged FINAL)
public:
    PasswordValidator();

    enum TypeValidation {
        DEFAULT,
        REPEAT
    };

    Q_ENUM( TypeValidation )

    virtual State validate(QString& value, int& position ) const override;

    TypeValidation tpValidation() const;
    void setTpValidation(TypeValidation newTpValidation);

    QString repeatPassword() const;
    void setRepeatPassword(const QString &newRepeatPassword);

signals:
    void tpValidationChanged();
    void repeatPasswordChanged();

private:
    TypeValidation _tpValidation;
    QString _repeatPassword;

    State validDefault( QString& value, int& position ) const;
    State validRepeat( const QString& value ) const;

};

#endif // PASSWORDVALIDATOR_H
