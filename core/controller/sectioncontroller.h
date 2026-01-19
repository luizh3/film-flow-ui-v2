#ifndef SECTIONCONTROLLER_H
#define SECTIONCONTROLLER_H

#include <core_global.h>

#include <network/endpoint/filmflowsectionendpoint.h>

class SearchMovies;
class SectionRequest;
class CORE_EXPORT SectionController {
public:
    SectionController();

    SearchMovies* find(const SectionRequest& request);

private:
    FilmFlowSectionEndpoint _filmFlowSectionEndpoint;
};

#endif // SECTIONCONTROLLER_H
