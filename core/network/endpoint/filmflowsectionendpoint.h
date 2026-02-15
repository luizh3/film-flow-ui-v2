#ifndef FILMFLOWSECTIONENDPOINT_H
#define FILMFLOWSECTIONENDPOINT_H

#include "filmflowendpoint.h"

#include <QFuture>

class Response;
class SectionRequest;
class FilmFlowSectionEndpoint : public FilmFlowEndpoint {
public:
    FilmFlowSectionEndpoint(const Session* session);

    QFuture<Response*> find(const SectionRequest& request);
};

#endif // FILMFLOWSECTIONENDPOINT_H
