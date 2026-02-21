#ifndef MOVIECONTROL_H
#define MOVIECONTROL_H

#include <QObject>
#include <QQmlEngine>

#include <controls_global.h>

#include <core/controller/multicontroller.h>

#include "moviemodel.h"

class CONTROLS_EXPORT MovieControl : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(MovieModel *movie READ movie WRITE setMovie NOTIFY movieChanged FINAL)
    Q_PROPERTY(bool isLoading READ isLoading WRITE setIsLoading NOTIFY isLoadingChanged FINAL)
public:
    MovieControl();
    ~MovieControl();
    Q_INVOKABLE void doStart(const int id, PresenterTypeProgramEnum tpProgram);
    Q_INVOKABLE void doRefresh(const int id, PresenterTypeProgramEnum tpProgram);
    Q_INVOKABLE void doCancel();

    MovieModel *movie() const;
    void setMovie(MovieModel *newMovie);

    bool isLoading() const;
    void setIsLoading(bool newIsLoading);

signals:
    void movieChanged();
    void isLoadingChanged();
    void finished();

private:
    MovieModel *_movie;

    bool _isLoading;
    bool _isCanceled;

    MultiController _multiController;

    void onFetchEnded(MovieInformation *movieInformation);
};

#endif // MOVIECONTROL_H
