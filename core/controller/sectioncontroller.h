#ifndef SECTIONCONTROLLER_H
#define SECTIONCONTROLLER_H

#include <QObject>

#include <core_global.h>

class SearchMovies;
class SectionRequest;
class FilmFlowSectionEndpoint;
class CORE_EXPORT SectionController : public QObject
{
    Q_OBJECT
public:
    SectionController();
    ~SectionController();

    SearchMovies* find(const SectionRequest& request);

    void cancel();

private:
    std::unique_ptr<FilmFlowSectionEndpoint> _filmFlowSectionEndpoint;
};

#endif // SECTIONCONTROLLER_H
