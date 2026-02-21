#ifndef MOVIESLISTCONTROL_H
#define MOVIESLISTCONTROL_H

#include <QObject>

#include <controls_global.h>

#include <presenter/models/movieslistmodel.h>

class SectionRequest;
class SectionController;
class SearchMoviesResult;
class MovieInformation;
class CONTROLS_EXPORT MoviesListControl : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(PresenterTypeProgramEnum tpProgram WRITE setTpProgram FINAL)
    Q_PROPERTY(QString key WRITE setKey FINAL)
    Q_PROPERTY(MoviesListModel *model READ model CONSTANT)
public:
    MoviesListControl();
    ~MoviesListControl();

    void onFetchMovies();

    void setTpProgram(PresenterTypeProgramEnum newTpProgram);
    void setKey(const QString &newKey);

    MoviesListModel *model();

private:
    SectionRequest *_sectionRequest;
    SectionController *_sectionController;

    MoviesListModel _movieListModel;

    void onFetchEnded(SearchMoviesResult *searchMoviesResult);
    static void applyToCards(MoviesListModel::CardMovie *cardMovie,
                             const MovieInformation *movieInformation);
};

#endif // MOVIESLISTCONTROL_H
