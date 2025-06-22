#ifndef MOVIESLIDERCONTROL_H
#define MOVIESLIDERCONTROL_H

#include <QObject>
#include <QQmlEngine>

#include <controls_global.h>

class MovieInformation;

class CONTROLS_EXPORT MovieSliderControl : public QObject {
    Q_OBJECT
    QML_ELEMENT
public:
    MovieSliderControl();
    Q_INVOKABLE void doStart();

    Q_INVOKABLE void next();
    Q_INVOKABLE void previous();

signals:
    void movieChanged( const QVariant& movie );
private:
    QList<MovieInformation*> _movies;

    int _currentIndex;

    void fetchMovies();
};


#endif // MOVIESLIDERCONTROL_H
