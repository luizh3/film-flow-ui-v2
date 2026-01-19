#ifndef PROGRAMREVIEWCONTROL_H
#define PROGRAMREVIEWCONTROL_H

#include <QObject>
#include <QQmlEngine>

#include <core/controller/reviewlikecontroller.h>

#include "control.h"

class ProgramReviewControl : public Control
{
    Q_OBJECT
    QML_ELEMENT
public:
    ProgramReviewControl();

    Q_INVOKABLE void like(const QString &reviewId);
    Q_INVOKABLE void unlike(const QString &reviewId);

signals:
    void rollbackLike();
    void rollbackUnlike();

private:
    ReviewLikeController _reviewLikeController;
};

#endif // PROGRAMREVIEWCONTROL_H
