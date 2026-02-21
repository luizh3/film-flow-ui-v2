#ifndef MOVIESLIDERCONTROL_H
#define MOVIESLIDERCONTROL_H

#include <QObject>
#include <QQmlEngine>

#include <controls_global.h>

#include "moviemodel.h"

class SectionController;
class CONTROLS_EXPORT MovieSliderControl : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    MovieSliderControl();
    ~MovieSliderControl();

    Q_INVOKABLE void doStart();

    Q_INVOKABLE void next();
    Q_INVOKABLE void previous();

signals:
    void movieChanged( const QVariant& movie );
private:
    SectionController* _sectionController;
    QList<MovieModel*> _movies;

    int _currentIndex;

    void fetchMovies();
};

#endif // MOVIESLIDERCONTROL_H
