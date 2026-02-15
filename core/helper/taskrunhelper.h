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

    static void runQueued(QObject* context, std::function<void()> callBack)
    {
        QMetaObject::invokeMethod(context, callBack, Qt::QueuedConnection);
    }

    template<typename ResultType, typename Response>
    static QFuture<ResultType*> promiseAsync(QFuture<Response*> future)
    {
        QPromise<ResultType*> promise;
        auto resultFuture = promise.future();

        future.then([promise = std::move(promise)](Response* response) mutable {
            if (!response) {
                promise.addResult(nullptr);
            } else {
                auto result = ResultType::fromJson(response->data());
                delete response;
                promise.addResult(result);
            }
            promise.finish();
        });

        return resultFuture;
    }
};

#endif // TASKRUNHELPER_H
