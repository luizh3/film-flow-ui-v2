#ifndef MOVIESLISTMODEL_H
#define MOVIESLISTMODEL_H

#include <QAbstractListModel>
#include <QFutureWatcher>
#include <QMap>
#include <QObject>
#include <QQmlEngine>

#include <models_global.h>

#include "enum/presentertypeprogramenum.h"

class MODELS_EXPORT MoviesListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    ~MoviesListModel();
     MoviesListModel();

     enum Roles { Title = Qt::UserRole, PosterUrl, Average, IsLoading, Id, TpProgram };

     int rowCount(const QModelIndex& parent) const override;

     QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

     virtual void fetchMore(const QModelIndex& parent) override;

     virtual bool canFetchMore(const QModelIndex& parent) const override;

     QHash<int, QByteArray> roleNames() const override;

     struct MODELS_EXPORT CardMovie
     {
         CardMovie();

         QString title;
         QString posterUrl;
         double average;
         bool isLoading;
         QString id;
         PresenterTypeProgramEnum tpProgram;
     };

     void onFetchEnded(
         const int nrItensFetch,
         std::function<void(MoviesListModel::CardMovie*, const int index)> bindCardCallback);

 signals:
     void fetchMovies();

 private:
     bool _isFetching;

     QList<CardMovie*> _fechingMoviesCard;
     QList<CardMovie*> _moviesCard;

     void updateCardsMovie(
         const int nrItensFetch,
         std::function<void(MoviesListModel::CardMovie*, const int index)> bindCardCallback);
};

#endif // MOVIESLISTMODEL_H
