#include "reviewslistmodel.h"

#include "helper/cardsfetchhelper.h"

namespace {
constexpr int NR_REVIEWS_BY_PAGE = 5;
}

ReviewsListModel::~ReviewsListModel()
{
    qDeleteAll(_reviewsCard);
}

ReviewsListModel::ReviewsListModel()
    : _isReviewsEnded{false}
    , _isFetching{false}
    , _isLoading{true}
    , _fetchingReviewsCard{}
    , _reviewsCard{}
{}

int ReviewsListModel::rowCount(const QModelIndex &parent) const
{
    return _reviewsCard.count();
}

QVariant ReviewsListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    const int row = index.row();

    switch (role) {
    case Title:
        return _reviewsCard.at(row)->title;
    case Description:
        return _reviewsCard.at(row)->description;
    case Score:
        return _reviewsCard.at(row)->score;
    case Id:
        return _reviewsCard.at(row)->id;
    case MovieId:
        return _reviewsCard.at(row)->movieId;
    case IsLoading:
        return _reviewsCard.at(row)->isLoading;
    case ProgramType:
        return QVariant::fromValue(_reviewsCard.at(row)->programType);
    case ProgramTitle:
        return _reviewsCard.at(row)->programTitle;
    case IsLikedByMe:
        return _reviewsCard.at(row)->isLikedByMe;
    case LikesCount:
        return _reviewsCard.at(row)->likesCount;
    case Author:
        return QVariant::fromValue(_reviewsCard.at(row)->author);
    case CreatedDate:
        return _reviewsCard.at(row)->createdDate;
    default:
        return QVariant();
    }
}

void ReviewsListModel::resetReviews()
{
    beginResetModel();

    _isReviewsEnded = false;

    qDeleteAll(_reviewsCard);

    _reviewsCard.clear();

    endResetModel();
}

void ReviewsListModel::fetchMore(const QModelIndex &parent)
{
    if (parent.isValid() || _isFetching || _isReviewsEnded) {
        return;
    }

    setIsLoading(true);
    setIsFetching(true);

    CardFetchHelper::appendFetchingCards<CardReview>(
        _reviewsCard,
        _fetchingReviewsCard,
        NR_REVIEWS_BY_PAGE,

        [this](int first, int last) { beginInsertRows(QModelIndex(), first, last); },

        [this]() { endInsertRows(); },

        []() { return new CardReview(); });

    emit fetchReviews();
}

bool ReviewsListModel::canFetchMore(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return false;
    }

    return !_isFetching && !_isReviewsEnded;
}

QHash<int, QByteArray> ReviewsListModel::roleNames() const
{
    static QHash<int, QByteArray> mapping{{Title, "title"},
                                          {Description, "description"},
                                          {IsLoading, "isLoading"},
                                          {MovieId, "movieId"},
                                          {Id, "id"},
                                          {Score, "score"},
                                          {ProgramType, "programType"},
                                          {ProgramTitle, "programTitle"},
                                          {LikesCount, "likesCount"},
                                          {IsLikedByMe, "isLikedByMe"},
                                          {Author, "author"},
                                          {CreatedDate, "createdDate"}};

    return mapping;
}

void ReviewsListModel::onFetchEnded(
    const int nrItensFetch,
    std::function<void(ReviewsListModel::CardReview *, const int index)> bindCardCallback)
{
    updateCardsReview(nrItensFetch, bindCardCallback);

    setIsLoading(false);
    setIsFetching(false);

}

void ReviewsListModel::updateCardsReview(
    const int nrItensFetch,
    std::function<void(ReviewsListModel::CardReview *, const int index)> bindCardCallback)
{
    CardFetchHelper::updateCards<CardReview>(
        _reviewsCard,
        _fetchingReviewsCard,
        nrItensFetch,

        [this](int first, int last) { beginRemoveRows(QModelIndex(), first, last); },

        [this]() { endRemoveRows(); },

        [this](int first, int last) { emit dataChanged(index(first), index(last)); },

        bindCardCallback);
}

ReviewsListModel::CardReview::CardReview()
    : author{nullptr}
    , programType{PresenterTypeProgramEnum::UNKNOW}
    , programTitle{QStringLiteral("")}
    , title{QStringLiteral("")}
    , description{QStringLiteral("")}
    , id{QStringLiteral("")}
    , movieId{QStringLiteral("")}
    , createdDate{QStringLiteral("")}
    , score(0.00)
    , isLoading{true}
    , likesCount{0}
    , isLikedByMe{false}
{}

ReviewsListModel::CardReview::~CardReview()
{
    delete author;
}

void ReviewsListModel::setIsFetching(const bool isFetching)
{
    if (isFetching == _isFetching) {
        return;
    }

    emit isFetchingChanged();

    _isFetching = isFetching;
}

bool ReviewsListModel::isFetching() const
{
    return _isFetching;
}

bool ReviewsListModel::isLoading() const
{
    return _isLoading;
}

void ReviewsListModel::setIsLoading(bool newIsLoading)
{
    if (_isLoading == newIsLoading) {
        return;
    }
    _isLoading = newIsLoading;
    emit isLoadingChanged();
}

void ReviewsListModel::setIsReviewsEnded(const bool isReviewsEnded)
{
    _isReviewsEnded = isReviewsEnded;
}
