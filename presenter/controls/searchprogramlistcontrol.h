#ifndef SEARCHPROGRAMLISTCONTROL_H
#define SEARCHPROGRAMLISTCONTROL_H

#include <QAbstractListModel>
#include <QFutureWatcher>
#include <QObject>
#include <QQmlEngine>

#include <controls_global.h>

#include <presenter/models/searchprogramlistmodel.h>

class MultiRequest;
class MovieInformation;
class MultiController;
class SearchMoviesResult;
class CONTROLS_EXPORT SearchProgramListControl : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString vDsQuery READ vDsQuery WRITE setVDsQuery NOTIFY vDsQueryChanged FINAL)
    Q_PROPERTY(SearchProgramListModel *model READ model CONSTANT)
public:
    SearchProgramListControl();
    ~SearchProgramListControl();

    void onFetchPrograms();

    QString vDsQuery() const;
    void setVDsQuery(const QString &newVDsQuery);

    SearchProgramListModel *model();

signals:
    void totalProgramsFound(int totalReviews);

    void vDsQueryChanged();

private:
    MultiRequest *_multiRequest;
    MultiController *_multiController;
    QString _vDsQuery;

    SearchProgramListModel _searchProgramListModel;

    void onFetchEnded(SearchMoviesResult *searchMoviesResult);

    static void applyToCard(SearchProgramListModel::SearchProgramCard *searchProgramCard,
                            const MovieInformation *movieInformation);
};

#endif // SEARCHPROGRAMLISTCONTROL_H
