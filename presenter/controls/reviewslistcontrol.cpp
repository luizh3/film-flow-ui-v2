#include "reviewslistcontrol.h"

#include <core/network/request/paginationrequest.h>

#include <core/controller/multicontroller.h>
#include <core/controller/reviewcontroller.h>

#include <core/model/entities/review.h>
#include <core/model/result/reviewsresult.h>

#include <core/helper/taskrunhelper.h>
#include <core/model/result/paginationresult.h>

#include "mapper/typeprogramenummapper.h"
#include "mapper/usermapper.h"

ReviewsListControl::ReviewsListControl()
    : _paginationRequest{new PaginationRequest()}
    , _reviewController{new ReviewController()}
    , _multiController{new MultiController()}
{
    QObject::connect(&_reviewsListModel,
                     &ReviewsListModel::fetchReviews,
                     this,
                     &ReviewsListControl::onFetchReviews);
}

ReviewsListControl::~ReviewsListControl()
{
    QObject::disconnect(&_reviewsListModel,
                        &ReviewsListModel::fetchReviews,
                        this,
                        &ReviewsListControl::onFetchReviews);

    _reviewController->cancel();
    _multiController->cancel();

    _reviewController->deleteLater();
    _multiController->deleteLater();

    delete _paginationRequest;
}

int ReviewsListControl::movieId() const
{
    return _movieId;
}

void ReviewsListControl::setMovieId(int newMovieId)
{
    if (_movieId == newMovieId) {
        return;
    }

    _movieId = newMovieId;
    emit movieIdChanged();
}

ReviewsListControl::ReviewFetchModeType ReviewsListControl::fetchModeType() const
{
    return _fetchModeType;
}

void ReviewsListControl::setFetchModeType(
    const ReviewsListControl::ReviewFetchModeType &newFetchModeType)
{
    if (_fetchModeType == newFetchModeType) {
        return;
    }

    _fetchModeType = newFetchModeType;

    emit fetchModeTypeChanged();
}

void ReviewsListControl::onFetchReviews()
{
    _paginationRequest->setPage(_paginationRequest->page() + 1);

    onFetchStarted().then([&](ReviewsResult *reviewsResult) { onFetchEnded(reviewsResult); });
}

void ReviewsListControl::resetReviews()
{
    _paginationRequest->setPage(0);

    _reviewsListModel.resetReviews();
}

ReviewsListModel *ReviewsListControl::model()
{
    return &_reviewsListModel;
}

QFuture<ReviewsResult *> ReviewsListControl::onFetchStarted()
{
    switch (_fetchModeType) {
    case ReviewsListControl::ReviewFetchModeType::ByUser:
        return _reviewController->findAll(_paginationRequest);
    case ReviewsListControl::ReviewFetchModeType::ByProgram:
        return _multiController->findAllReviewsByIdMovie(_movieId, _paginationRequest);
    default:
        return QFuture<ReviewsResult *>(nullptr);
    }
}

void ReviewsListControl::onFetchEnded(ReviewsResult *reviewsResult)
{
    if (!reviewsResult) {
        return;
    }

    const bool isFirstPage = _paginationRequest->page() == 1;

    if (isFirstPage) {
        emit totalReviewsFound(reviewsResult->pagination()->totalResult());
    }

    const bool isReviewsEnded = reviewsResult->pagination()->totalPage()
                                == _paginationRequest->page();

    _reviewsListModel.setIsReviewsEnded(isReviewsEnded);

    const QList<Review *> &reviews = reviewsResult->reviews();

    _reviewsListModel.onFetchEnded(reviews.count(),
                                   [reviews](ReviewsListModel::CardReview *cardReview,
                                             const int index) {
                                       ReviewsListControl::applyToCard(cardReview, reviews[index]);
                                   });

    delete reviewsResult;
}

void ReviewsListControl::applyToCard(ReviewsListModel::CardReview *cardReview, const Review *review)
{
    cardReview->description = review->description();
    cardReview->title = review->title();
    cardReview->score = review->score();
    cardReview->id = review->reviewId();
    cardReview->movieId = review->movieId();
    cardReview->isLoading = false;
    cardReview->programTitle = review->programTitle();
    cardReview->programType = TypeProgramEnumMapper::toModel(review->tpProgram());
    cardReview->isLikedByMe = review->isLikedByMe();
    cardReview->likesCount = review->likesCount();
    cardReview->author = UserMapper::toModel(review->author());
}
