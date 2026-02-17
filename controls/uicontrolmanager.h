#ifndef UICONTROLMANAGER_H
#define UICONTROLMANAGER_H

#include <QObject>
#include <QQmlEngine>

#include <controls_global.h>

#include <ui/models/usermodel.h>

class CONTROLS_EXPORT UiControlManager : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_ELEMENT
    Q_PROPERTY(UserModel *user READ user CONSTANT FINAL)
public:
    UiControlManager();

    UserModel *user();

private:
    std::unique_ptr<UserModel> _user;
};

#endif // UICONTROLMANAGER_H
