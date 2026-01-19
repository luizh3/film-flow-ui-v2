#ifndef TASKRUNHELPER_H
#define TASKRUNHELPER_H

#include <QObject>

#include <functional>
#include <QFutureWatcher>
#include <QtConcurrent>

class TaskRunHelper : public QObject {
    Q_OBJECT
public:
    static void async(std::function<void()> runCallback)
    {
        QFutureWatcher<void> future;

        future.setFuture(QtConcurrent::run(runCallback));
    };

    template<typename Result>
    static QFutureWatcher<Result>* async(std::function<Result()> runCallback)
    {
        QFutureWatcher<Result>* future = new QFutureWatcher<Result>();

        future->setFuture( QtConcurrent::run( runCallback ) );

        return future;
    };

    static void runSync(std::function<void()> callBack)
    {
        QEventLoop eventLoop;
        QFutureWatcher<void> future;

        QObject::connect(&future, &QFutureWatcher<void>::finished, &eventLoop, &QEventLoop::quit);

        future.setFuture(QtConcurrent::run(callBack));
        eventLoop.exec();
    }
};

#endif // TASKRUNHELPER_H
