#ifndef REVIEWMAPPER_H
#define REVIEWMAPPER_H

#include <models_global.h>

class Review;
class ReviewModel;
class MODELS_EXPORT ReviewMapper
{
public:
    static Review* toEntity(const ReviewModel* reviewModel);
    static ReviewModel* toModel(const Review* review);
};

#endif // REVIEWMAPPER_H
