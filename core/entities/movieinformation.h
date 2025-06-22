#ifndef MOVIEINFORMATION_H
#define MOVIEINFORMATION_H

#include <QObject>
#include <QQmlEngine>

#include <core_global.h>

class QJsonObject;
class CORE_EXPORT MovieInformation : public QObject {
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY( QString title READ title CONSTANT )
    Q_PROPERTY( QString backdropUrl READ backdropUrl CONSTANT );
    Q_PROPERTY( double average READ average CONSTANT )
public:
    MovieInformation();

    explicit MovieInformation(
        double average,
        const QString &title,
        const QString &id,
        const QString &backdropUrl,
        const QString &posterUrl,
        const QString &overview,
        const QString &release,
        const QList<int> &genresId
    );

    double average() const;
    void setAverage(double newAverage);

    QString title() const;
    void setTitle(const QString &newTitle);

    QString id() const;
    void setId(const QString &newId);

    QString backdropUrl() const;
    void setBackdropUrl(const QString &newBackdropUrl);

    QString posterUrl() const;
    void setPosterUrl(const QString &newPosterUrl);

    QString overview() const;
    void setOverview(const QString &newOverview);

    QString release() const;
    void setRelease(const QString &newRelease);

    QList<int> genresId() const;
    void setGenresId(const QList<int> &newGenresId);

    static MovieInformation* fromJson( const QJsonObject& jsonObject );

private:
    double _average;
    QString _title;
    QString _id;
    QString _backdropUrl;
    QString _posterUrl;
    QString _overview;
    QString _release;
    QList<int> _genresId;
};

#endif // MOVIEINFORMATION_H
