#ifndef SECTIONCONTROLLER_H
#define SECTIONCONTROLLER_H

#include <core_global.h>

class SearchMovies;
class SectionRequest;
class CORE_EXPORT SectionController {
public:
    SearchMovies* find( const SectionRequest& request ) const;
};

#endif // SECTIONCONTROLLER_H
