#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <core_global.h>

#include <QObject>

#include <network/endpoint/filmflowconfigendpoint.h>

class CORE_EXPORT ApplicationController : public QObject
{
    Q_OBJECT
public:
    ApplicationController();
    void configs();
signals:
    void success();
    void error(const QString& message);

private:
    FilmFlowConfigEndpoint _filmFlowConfigEndpoint;
};

#endif // APPLICATIONCONTROLLER_H
