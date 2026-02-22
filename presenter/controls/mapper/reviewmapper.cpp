#include "reviewmapper.h"

#include <core/model/entities/review.h>

#include "reviewmodel.h"

#include "typeprogramenummapper.h"
#include "usermapper.h"

Review *ReviewMapper::toEntity(const ReviewModel *reviewModel)
{
    if (!reviewModel) {
        return nullptr;
    }

    return new Review(reviewModel->score(),
                      reviewModel->likesCount(),
                      TypeProgramEnumMapper::toEntity(reviewModel->tpProgram()),
                      reviewModel->isLikedByMe(),
                      reviewModel->reviewId(),
                      reviewModel->title(),
                      reviewModel->description(),
                      reviewModel->movieId(),
                      reviewModel->programTitle());
}

ReviewModel *ReviewMapper::toModel(const Review *review)
{
    if (!review) {
        return nullptr;
    }

    return new ReviewModel(review->score(),
                           review->likesCount(),
                           TypeProgramEnumMapper::toModel(review->tpProgram()),
                           review->isLikedByMe(),
                           review->reviewId(),
                           review->title(),
                           review->description(),
                           review->movieId(),
                           review->programTitle(),
                           review->createdDate().toString("dd/MM/yyyy"),
                           UserMapper::toModel(review->author()));
}
