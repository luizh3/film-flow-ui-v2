#ifndef MOVIECONTROL_H
#define MOVIECONTROL_H

#include <QObject>

class MovieControl : public QObject
{
    Q_OBJECT
public:
    explicit MovieControl(QObject *parent = nullptr);

signals:
};

#endif // MOVIECONTROL_H
