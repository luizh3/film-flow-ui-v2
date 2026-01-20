#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <core_global.h>

#include <QObject>

#include <network/endpoint/filmflowconfigendpoint.h>

class FilmFlowConfigEndpoint;
class CORE_EXPORT ApplicationController : public QObject
{
    Q_OBJECT
public:
    ApplicationController();
    ~ApplicationController();
    void configs();
signals:
    void success();
    void error(const QString& message);

private:
    std::unique_ptr<FilmFlowConfigEndpoint> _filmFlowConfigEndpoint;
};

#endif // APPLICATIONCONTROLLER_H
