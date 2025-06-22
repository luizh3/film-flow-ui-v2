#ifndef MOVIESLISTMODEL_H
#define MOVIESLISTMODEL_H

#include <QObject>
#include <QMap>
#include <QAbstractListModel>
#include <QQmlEngine>

#include <models_global.h>

#include <core/entities/typeprogramenum.h>

class SectionRequest;
class MovieInformation;
class SectionController;

class MODELS_EXPORT MoviesListModel : public QAbstractListModel {
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(TypeProgram::TypeProgramEnum tpProgram WRITE setTpProgram FINAL )
    Q_PROPERTY(QString key WRITE setKey FINAL )
public:
    ~MoviesListModel();
     MoviesListModel();

    enum Roles {
        Title = Qt::UserRole,
        PosterUrl,
        Average,
        IsLoading
    };

    int rowCount(const QModelIndex& parent) const override;

    QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const override;

    virtual void fetchMore(const QModelIndex &parent) override;

    virtual bool canFetchMore(const QModelIndex &parent) const override;

    QHash<int, QByteArray> roleNames() const override;

    struct CardMovie {

        CardMovie();

        QString title;
        QString posterUrl;
        double average;
        bool isLoading;
    };

    void ajustFechingCardsMovie( const int nrCards );
    void updateCardsMovie( const QList<CardMovie*>& cardsMovie, const QList<MovieInformation*>& moviesInformation ) const;
    void updateCardMovie( CardMovie* movieCard, const MovieInformation* movieInformation ) const;

    void setTpProgram(TypeProgramEnum newTpProgram);
    void setKey(const QString &newKey);

private:
    SectionRequest* _sectionRequest;
    SectionController* _sectionController;

    bool _isFetching;

    QList<CardMovie*> _fechingMoviesCard;
    QList<CardMovie*> _moviesCard;


};

#endif // MOVIESLISTMODEL_H
