#ifndef REVIEWPROGRAMMODALCONTROL_H
#define REVIEWPROGRAMMODALCONTROL_H

#include <QObject>
#include <QQmlEngine>

#include <core/model/entities/review.h>

#include "control.h"
#include "controls_global.h"

#include "reviewmodel.h"

class CONTROLS_EXPORT ReviewProgramModalControl : public Control
{
    Q_OBJECT
    QML_ELEMENT
public:
    Q_INVOKABLE void doConfirm(const ReviewModel* review) const;

private:
    void doCreate(const ReviewModel* review) const;
    void doUpdate(const ReviewModel* review) const;

private slots:
    void onError(const QString& message);
    void onSuccess(Review* review);
signals:
    void error(const QString& message);
    void success(ReviewModel* review);
};

#endif // REVIEWPROGRAMMODALCONTROL_H
