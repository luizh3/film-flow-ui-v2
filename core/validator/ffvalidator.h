#ifndef FFVALIDATOR_H
#define FFVALIDATOR_H

#include <QValidator>

class FFValidator : public QValidator {
    Q_OBJECT
    Q_PROPERTY( QString vError READ error WRITE setError NOTIFY errorChanged FINAL )
public:
    FFValidator();

    QString error() const;
    void setError(const QString &newError);

signals:
    void errorChanged();

protected:
    mutable QString _error;
};

#endif // FFVALIDATOR_H
