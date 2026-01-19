#ifndef FILMFLOWSECTIONENDPOINT_H
#define FILMFLOWSECTIONENDPOINT_H

#include "filmflowendpoint.h"

class Response;
class SectionRequest;
class FilmFlowSectionEndpoint : public FilmFlowEndpoint {
public:
    FilmFlowSectionEndpoint(const Session* session);

    Response* find( const SectionRequest& request );
};

#endif // FILMFLOWSECTIONENDPOINT_H
