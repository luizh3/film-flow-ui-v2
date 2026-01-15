#ifndef REVIEWSLISTMODEL_H
#define REVIEWSLISTMODEL_H

#include <QAbstractListModel>
#include <QMap>
#include <QObject>
#include <QQmlEngine>

#include <QFutureWatcher>

#include <models_global.h>

#include <core/entities/typeprogramenum.h>

class Review;
class PaginationRequest;
class ReviewController;
class MultiController;
class ReviewsResult;
class MODELS_EXPORT ReviewsListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(int movieId READ movieId WRITE setMovieId NOTIFY movieIdChanged FINAL)
    Q_PROPERTY(ReviewFetchModeType fetchModeType READ fetchModeType WRITE setFetchModeType NOTIFY
                   fetchModeTypeChanged FINAL)
public:
    ~ReviewsListModel();
    ReviewsListModel();

    enum class ReviewFetchModeType { ByUser, ByProgram };

    Q_ENUM(ReviewFetchModeType)

    enum Roles {
        Title = Qt::UserRole,
        Description,
        Score,
        IsLoading,
        Id,
        MovieId,
        ProgramTitle,
        ProgramType,
        IsLikedByMe,
        LikesCount
    };

    struct CardReview
    {
        CardReview();

        TypeProgramEnum programType;
        QString programTitle;
        QString title;
        QString description;
        QString id;
        QString movieId;
        double score;
        bool isLoading;
        int likesCount;
        bool isLikedByMe;
    };

    int rowCount(const QModelIndex& parent) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    virtual void fetchMore(const QModelIndex& parent) override;

    virtual bool canFetchMore(const QModelIndex& parent) const override;

    QHash<int, QByteArray> roleNames() const override;

    int movieId() const;
    void setMovieId(int newMovieId);

    ReviewFetchModeType fetchModeType() const;
    void setFetchModeType(ReviewFetchModeType newFetchModeType);

signals:
    void totalReviewsFound(int totalReviews);

    void searchTypeChanged();

    void movieIdChanged();

    void isLoadingChanged();

    void fetchModeTypeChanged();

private:
    ReviewsResult* onFetchStarted();
    void onFetchEnded(QFutureWatcher<ReviewsResult*>* future);
    void updateCardsReview(const QList<CardReview*>& cardsReview, const QList<Review*>& reviews);
    static void updateCardReview(CardReview* cardReview, const Review* review);

    PaginationRequest* _paginationRequest;
    ReviewController* _reviewController;
    MultiController* _multiController;

    ReviewFetchModeType _fetchModeType;
    int _movieId;
    bool _isReviewsEnded;
    bool _isFetching;

    QList<CardReview*> _fetchingReviewsCard;
    QList<CardReview*> _reviewsCard;
};

#endif // REVIEWSLISTMODEL_H
