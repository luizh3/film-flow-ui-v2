#ifndef MOVIECONTROL_H
#define MOVIECONTROL_H

#include <QObject>
#include <QQmlEngine>

#include <controls_global.h>

#include <core/controller/multicontroller.h>
#include <core/entities/movieinformation.h>

#include <core/entities/review.h>

class CONTROLS_EXPORT MovieControl : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(MovieInformation *movie READ movie WRITE setMovie NOTIFY movieChanged FINAL)
    Q_PROPERTY(bool isLoading READ isLoading WRITE setIsLoading NOTIFY isLoadingChanged FINAL)
public:
    MovieControl();
    ~MovieControl();
    Q_INVOKABLE void doStart(const int id, TypeProgramEnum tpProgram);
    Q_INVOKABLE void doCancel();
    Q_INVOKABLE void doUpdateReview(Review *review);

    MovieInformation *movie() const;
    void setMovie(MovieInformation *newMovie);

    bool isLoading() const;
    void setIsLoading(bool newIsLoading);

signals:
    void movieChanged();
    void isLoadingChanged();
    void finished();

private:
    bool _isLoading;
    bool _isCanceled;
    MovieInformation *_movie;
    MultiController _multiController;
};

#endif // MOVIECONTROL_H
