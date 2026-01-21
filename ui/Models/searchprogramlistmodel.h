#ifndef SEARCHPROGRAMLISTMODEL_H
#define SEARCHPROGRAMLISTMODEL_H

#include <QAbstractListModel>
#include <QFutureWatcher>
#include <QObject>
#include <QQmlEngine>

#include <models_global.h>

#include <core/entities/typeprogramenum.h>

class MultiRequest;
class MovieInformation;
class MultiController;
class SearchMovies;

class MODELS_EXPORT SearchProgramListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString vDsQuery READ vDsQuery WRITE setVDsQuery NOTIFY vDsQueryChanged FINAL)
public:
    SearchProgramListModel();
    ~SearchProgramListModel();

    enum Roles {
        Title = Qt::UserRole,
        PosterUrl,
        Average,
        Genres,
        IsLoading,
        Id,
        TpProgram,
        Overview
    };

    int rowCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    virtual void fetchMore(const QModelIndex &parent) override;

    virtual bool canFetchMore(const QModelIndex &parent) const override;

    QHash<int, QByteArray> roleNames() const override;

    struct SearchProgramCard
    {
        SearchProgramCard();

        QString title;
        QString posterUrl;
        QString genres;
        QString overview;
        double average;
        bool isLoading;
        QString id;
        TypeProgramEnum tpProgram;
    };

    QString vDsQuery() const;
    void setVDsQuery(const QString &newVDsQuery);

signals:
    void vDsQueryChanged();
    void cancelRequest();

private:
    void onFetchEnded(QFutureWatcher<SearchMovies *> *future);

    void updateCardsMovie(const QList<SearchProgramCard *> &searchProgramCards,
                          const QList<MovieInformation *> &moviesInformation);

    static void updateCardMovie(SearchProgramCard *searchProgramCard,
                                const MovieInformation *movieInformation);

    MultiRequest *_multiRequest;
    MultiController *_multiController;

    bool _isFetching;
    QString _vDsQuery = "";

    QList<SearchProgramCard *> _fechingSearchProgramCards;
    QList<SearchProgramCard *> _programCards;
};

#endif // SEARCHPROGRAMLISTMODEL_H
