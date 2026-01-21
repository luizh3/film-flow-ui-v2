#ifndef PROFILESCREENCONTROL_H
#define PROFILESCREENCONTROL_H

#include <QObject>
#include <QQmlEngine>

#include <controls_global.h>

#include <entities/user.h>

class User;
class CONTROLS_EXPORT ProfileScreenControl : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    ProfileScreenControl();

    Q_INVOKABLE void doStart();
signals:
    void userChanged(QVariant user);

private:
    std::unique_ptr<User> _user;
};

#endif // PROFILESCREENCONTROL_H
