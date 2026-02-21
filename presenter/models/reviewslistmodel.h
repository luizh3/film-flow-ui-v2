#ifndef REVIEWSLISTMODEL_H
#define REVIEWSLISTMODEL_H

#include <QAbstractListModel>
#include <QQmlEngine>
#include <QFutureWatcher>

#include <models_global.h>

#include "enum/presentertypeprogramenum.h"

#include "usermodel.h"

class MODELS_EXPORT ReviewsListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(bool isFetching READ isFetching NOTIFY isFetchingChanged FINAL)
    Q_PROPERTY(bool isLoading READ isLoading WRITE setIsLoading NOTIFY isLoadingChanged FINAL)
public:
    ~ReviewsListModel();
    ReviewsListModel();

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
        LikesCount,
        Author
    };

    struct MODELS_EXPORT CardReview
    {
        CardReview();
        ~CardReview();

        UserModel* author;
        PresenterTypeProgramEnum programType;
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

    void resetReviews();

    virtual void fetchMore(const QModelIndex& parent) override;

    virtual bool canFetchMore(const QModelIndex& parent) const override;

    QHash<int, QByteArray> roleNames() const override;

    void setIsFetching(const bool isFetching);
    bool isFetching() const;

    bool isLoading() const;
    void setIsLoading(bool newIsLoading);

    void setIsReviewsEnded(const bool isReviewsEnded);

    void onFetchEnded(
        const int nrItensFetch,
        std::function<void(ReviewsListModel::CardReview*, const int index)> bindCardCallback);
signals:
    void isLoadingChanged();
    void isFetchingChanged();

    void fetchReviews();

private:
    void updateCardsReview(
        const int nrItensFetch,
        std::function<void(ReviewsListModel::CardReview*, const int index)> bindCardCallback);

    bool _isReviewsEnded;
    bool _isFetching;
    bool _isLoading;

    QList<CardReview*> _fetchingReviewsCard;
    QList<CardReview*> _reviewsCard;
};

#endif // REVIEWSLISTMODEL_H
