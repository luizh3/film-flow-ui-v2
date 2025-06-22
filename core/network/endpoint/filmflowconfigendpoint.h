#ifndef FILMFLOWCONFIGENDPOINT_H
#define FILMFLOWCONFIGENDPOINT_H

#include "filmflowendpoint.h"

class Response;
class FilmFlowConfigEndpoint : public FilmFlowEndpoint {
public:
    Response* configs() const;
};

#endif // FILMFLOWCONFIGENDPOINT_H
