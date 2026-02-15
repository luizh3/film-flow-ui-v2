#ifndef REVIEWSLISTMODEL_H
#define REVIEWSLISTMODEL_H

#include <QAbstractListModel>
#include <QMap>
#include <QObject>
#include <QQmlEngine>

#include <QFutureWatcher>

#include <models_global.h>

#include <core/model/enum/typeprogramenum.h>

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
    Q_PROPERTY(bool isFetching READ isFetching NOTIFY isFetchingChanged FINAL)
    Q_PROPERTY(bool isLoading READ isLoading WRITE setIsLoading NOTIFY isLoadingChanged FINAL)
public:
    ~ReviewsListModel();
    ReviewsListModel();

    enum class ReviewFetchModeType : short { ByUser, ByProgram };

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

    Q_INVOKABLE void resetReviews();

    virtual void fetchMore(const QModelIndex& parent) override;

    virtual bool canFetchMore(const QModelIndex& parent) const override;

    QHash<int, QByteArray> roleNames() const override;

    int movieId() const;
    void setMovieId(int newMovieId);

    ReviewFetchModeType fetchModeType() const;
    void setFetchModeType(ReviewFetchModeType newFetchModeType);

    void setIsFetching(const bool isFetching);
    bool isFetching() const;

    bool isLoading() const;
    void setIsLoading(bool newIsLoading);

signals:
    void totalReviewsFound(int totalReviews);
    void searchTypeChanged();
    void movieIdChanged();
    void isLoadingChanged();
    void fetchModeTypeChanged();
    void isFetchingChanged();

private:
    QFuture<ReviewsResult*> onFetchStarted();
    void onFetchEnded(ReviewsResult* reviewsResult);
    void updateCardsReview(const QList<CardReview*>& cardsReview, const QList<Review*>& reviews);
    static void updateCardReview(CardReview* cardReview, const Review* review);

    PaginationRequest* _paginationRequest;
    ReviewController* _reviewController;
    MultiController* _multiController;

    int _movieId;
    ReviewFetchModeType _fetchModeType;
    bool _isReviewsEnded;
    bool _isFetching;
    bool _isLoading;

    QList<CardReview*> _fetchingReviewsCard;
    QList<CardReview*> _reviewsCard;
};

#endif // REVIEWSLISTMODEL_H
