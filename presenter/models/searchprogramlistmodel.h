#ifndef SEARCHPROGRAMLISTMODEL_H
#define SEARCHPROGRAMLISTMODEL_H

#include <QAbstractListModel>
#include <QFutureWatcher>
#include <QObject>
#include <QQmlEngine>

#include <models_global.h>

#include "enum/presentertypeprogramenum.h"

class MODELS_EXPORT SearchProgramListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
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

    struct MODELS_EXPORT SearchProgramCard
    {
        SearchProgramCard();

        QString title;
        QString posterUrl;
        QString genres;
        QString overview;
        double average;
        bool isLoading;
        QString id;
        PresenterTypeProgramEnum tpProgram;
    };

    int rowCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    virtual void fetchMore(const QModelIndex &parent) override;

    virtual bool canFetchMore(const QModelIndex &parent) const override;

    QHash<int, QByteArray> roleNames() const override;

    void resetPrograms();

    void onFetchEnded(const int nrItensFetch,
                      std::function<void(SearchProgramListModel::SearchProgramCard *,
                                         const int index)> bindCardCallback);

    void setIsCanFetch(const bool isCanFetch);

signals:
    void fetchPrograms();

private:
    void updateCardsMovie(const int nrItensFetch,
                          std::function<void(SearchProgramListModel::SearchProgramCard *,
                                             const int index)> bindCardCallback);

    bool _isFetching;
    bool _isCanFetch;

    QList<SearchProgramCard *> _fechingSearchProgramCards;
    QList<SearchProgramCard *> _programCards;
};

#endif // SEARCHPROGRAMLISTMODEL_H
