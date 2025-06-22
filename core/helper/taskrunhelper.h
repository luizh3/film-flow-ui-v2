#ifndef TASKRUNHELPER_H
#define TASKRUNHELPER_H

#include <QObject>

#include <functional>
#include <QFutureWatcher>
#include <QtConcurrent>

class TaskRunHelper : public QObject {
    Q_OBJECT
public:
    template< typename Result>
    static QFutureWatcher<Result>* async( std::function<Result()> runCallback ) {

        QFutureWatcher<Result>* future = new QFutureWatcher<Result>();

        future->setFuture( QtConcurrent::run( runCallback ) );

        return future;
    };
};

#endif // TASKRUNHELPER_H
