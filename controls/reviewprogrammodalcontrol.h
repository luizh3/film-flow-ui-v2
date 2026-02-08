#ifndef REVIEWPROGRAMMODALCONTROL_H
#define REVIEWPROGRAMMODALCONTROL_H

#include <QObject>
#include <QQmlEngine>

#include "control.h"
#include "controls_global.h"

#include <entities/review.h>

class CONTROLS_EXPORT ReviewProgramModalControl : public Control
{
    Q_OBJECT
    QML_ELEMENT
public:
    Q_INVOKABLE void doConfirm(const Review* review) const;

private:
    void doCreate(const Review* review) const;
    void doUpdate(const Review* review) const;

private slots:
    void onError(const QString& message);
    void onSuccess(Review* review);
signals:
    void error(const QString& message);
    void success(Review* review);
};

#endif // REVIEWPROGRAMMODALCONTROL_H
