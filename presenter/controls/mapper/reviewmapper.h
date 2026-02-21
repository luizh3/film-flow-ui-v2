#ifndef REVIEWMAPPER_H
#define REVIEWMAPPER_H

class Review;
class ReviewModel;
class ReviewMapper
{
public:
    static Review* toEntity(const ReviewModel* reviewModel);
    static ReviewModel* toModel(const Review* review);
};

#endif // REVIEWMAPPER_H
