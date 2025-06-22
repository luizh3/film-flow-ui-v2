#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <core_global.h>

#include <QObject>

class CORE_EXPORT ApplicationController : public QObject
{
    Q_OBJECT
public:
    void configs();
signals:
    void success();
    void error( const QString& message );
};

#endif // APPLICATIONCONTROLLER_H
