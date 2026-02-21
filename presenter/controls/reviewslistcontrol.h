#ifndef REVIEWSLISTCONTROL_H
#define REVIEWSLISTCONTROL_H

#include <QFuture>
#include <QObject>
#include <QQmlEngine>

#include <core/model/enum/typeprogramenum.h>

#include "reviewslistmodel.h"

class Review;
class PaginationRequest;
class ReviewController;
class MultiController;
class ReviewsResult;
class ReviewsListControl : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(int movieId READ movieId WRITE setMovieId NOTIFY movieIdChanged FINAL)
    Q_PROPERTY(ReviewFetchModeType fetchModeType READ fetchModeType WRITE setFetchModeType NOTIFY
                   fetchModeTypeChanged FINAL)
    Q_PROPERTY(ReviewsListModel* model READ model CONSTANT)
public:
    ~ReviewsListControl();
    ReviewsListControl();

    enum class ReviewFetchModeType : short { ByUser, ByProgram };

    Q_ENUM(ReviewFetchModeType);

    int movieId() const;
    void setMovieId(int newMovieId);

    ReviewFetchModeType fetchModeType() const;
    void setFetchModeType(const ReviewFetchModeType& newFetchModeType);

    Q_INVOKABLE void resetReviews();

    ReviewsListModel* model();

private slots:
    void onFetchReviews();

signals:
    void movieIdChanged();
    void fetchModeTypeChanged();

    void totalReviewsFound(int totalReviews);

private:
    PaginationRequest* _paginationRequest;
    ReviewController* _reviewController;
    MultiController* _multiController;

    int _movieId;
    ReviewFetchModeType _fetchModeType;
    ReviewsListModel _reviewsListModel;

    QFuture<ReviewsResult*> onFetchStarted();

    void onFetchEnded(ReviewsResult* reviewsResult);

    static void applyToCard(ReviewsListModel::CardReview* cardReview, const Review* review);
};

#endif // REVIEWSLISTCONTROL_H
