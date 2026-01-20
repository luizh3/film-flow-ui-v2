#ifndef REVIEWLIKECONTROLLER_H
#define REVIEWLIKECONTROLLER_H

#include <QObject>

#include <core_global.h>

class FilmFlowReviewEndpoint;
class CORE_EXPORT ReviewLikeController : public QObject
{
    Q_OBJECT
public:
    ReviewLikeController();
    ~ReviewLikeController();

    void like(const QString& reviewId);
    void unlike(const QString& reviewId);

    void cancel();

signals:
    void errorLiked(const QString& message);
    void successLiked();

    void errorUnliked(const QString& message);
    void successUnliked();

private:
    std::unique_ptr<FilmFlowReviewEndpoint> _filmFlowReviewEndpoint;
};

#endif // REVIEWLIKECONTROLLER_H
