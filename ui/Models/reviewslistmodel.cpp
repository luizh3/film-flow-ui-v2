#include "reviewslistmodel.h"

#include <core/network/request/paginationrequest.h>

#include <core/controller/multicontroller.h>
#include <core/controller/reviewcontroller.h>

#include <core/entities/review.h>
#include <core/entities/reviewsresult.h>

#include <core/entities/pagination.h>
#include <core/helper/taskrunhelper.h>

#include "helper/cardsfetchhelper.h"

namespace {
constexpr int NR_REVIEWS_BY_PAGE = 5;
}

ReviewsListModel::~ReviewsListModel()
{
    delete _paginationRequest;
    delete _reviewController;
    delete _multiController;

    qDeleteAll(_reviewsCard);
}

ReviewsListModel::ReviewsListModel()
    : _paginationRequest{new PaginationRequest()}
    , _reviewController{new ReviewController()}
    , _multiController{new MultiController()}
    , _movieId{0}
    , _fetchModeType(ReviewsListModel::ReviewFetchModeType::ByUser)
    , _isReviewsEnded{false}
    , _isFetching{false}
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
    default:
        return QVariant();
    }
}

void ReviewsListModel::fetchMore(const QModelIndex &parent)
{
    if (parent.isValid() || _isFetching || _isReviewsEnded) {
        return;
    }

    _isFetching = true;

    _paginationRequest->setPage(_paginationRequest->page() + 1);

    CardFetchHelper::appendFetchingCards<CardReview>(
        _reviewsCard,
        _fetchingReviewsCard,
        NR_REVIEWS_BY_PAGE,

        [this](int first, int last) { beginInsertRows(QModelIndex(), first, last); },

        [this]() { endInsertRows(); },

        []() { return new CardReview(); });

    QFutureWatcher<ReviewsResult *> *future = TaskRunHelper::async<ReviewsResult *>(
        [&]() { return onFetchStarted(); });

    QObject::connect(future, &QFutureWatcher<ReviewsResult *>::finished, this, [this, future]() {
        onFetchEnded(future);
    });
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
                                          {IsLikedByMe, "isLikedByMe"}};

    return mapping;
}

void ReviewsListModel::onFetchEnded(QFutureWatcher<ReviewsResult *> *future)
{
    if (future->isFinished() && !future->isCanceled()) {
        std::unique_ptr<ReviewsResult> reviewsResult(future->result());

        const bool isFirstPage = _paginationRequest->page() == 1;

        if (isFirstPage) {
            emit totalReviewsFound(reviewsResult->pagination()->totalResult());
        }

        _isReviewsEnded = reviewsResult->pagination()->totalPage() == _paginationRequest->page();

        updateCardsReview(_fetchingReviewsCard, reviewsResult->reviews());

        _isFetching = false;
    }

    future->deleteLater();
}

void ReviewsListModel::updateCardsReview(const QList<CardReview *> &cardsReview,
                                         const QList<Review *> &reviews)
{
    CardFetchHelper::updateCards<CardReview, Review>(
        _reviewsCard,
        _fetchingReviewsCard,
        reviews,

        [this](int first, int last) { beginRemoveRows(QModelIndex(), first, last); },

        [this]() { endRemoveRows(); },

        [this](int first, int last) { emit dataChanged(index(first), index(last)); },

        &ReviewsListModel::updateCardReview);
}

void ReviewsListModel::updateCardReview(CardReview *cardReview, const Review *review)
{
    cardReview->description = review->description();
    cardReview->title = review->title();
    cardReview->score = review->score();
    cardReview->id = review->reviewId();
    cardReview->movieId = review->movieId();
    cardReview->isLoading = false;
    cardReview->programTitle = review->programTitle();
    cardReview->programType = review->tpProgram();
    cardReview->isLikedByMe = review->isLikedByMe();
    cardReview->likesCount = review->likesCount();
}

ReviewsListModel::CardReview::CardReview()
    : programType{TypeProgram::TypeProgramEnum::UNKNOW}
    , programTitle{QStringLiteral("")}
    , title{QStringLiteral("")}
    , description{QStringLiteral("")}
    , id{QStringLiteral("")}
    , movieId{QStringLiteral("")}
    , score(0.00)
    , isLoading{true}
    , likesCount{0}
    , isLikedByMe{false}
{}

ReviewsResult *ReviewsListModel::onFetchStarted()
{
    switch (_fetchModeType) {
    case ReviewsListModel::ReviewFetchModeType::ByUser:
        return _reviewController->findAll(_paginationRequest);
    case ReviewsListModel::ReviewFetchModeType::ByProgram:
        return _multiController->findAllReviewsByIdMovie(_movieId, _paginationRequest);
    }
}

int ReviewsListModel::movieId() const
{
    return _movieId;
}

void ReviewsListModel::setMovieId(int newMovieId)
{
    if (_movieId == newMovieId) {
        return;
    }
    _movieId = newMovieId;
    emit movieIdChanged();
}

ReviewsListModel::ReviewFetchModeType ReviewsListModel::fetchModeType() const
{
    return _fetchModeType;
}

void ReviewsListModel::setFetchModeType(ReviewFetchModeType newFetchModeType)
{
    if (_fetchModeType == newFetchModeType) {
        return;
    }

    _fetchModeType = newFetchModeType;
    emit fetchModeTypeChanged();
}
