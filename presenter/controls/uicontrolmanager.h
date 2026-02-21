#ifndef UICONTROLMANAGER_H
#define UICONTROLMANAGER_H

#include <QObject>
#include <QQmlEngine>

#include <controls_global.h>

#include <presenter/models/usermodel.h>

#include "manager/languagemanager.h"

class CONTROLS_EXPORT UiControlManager : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_ELEMENT
    Q_PROPERTY(UserModel *user READ user CONSTANT FINAL)
public:
    static UiControlManager &instance();

    UiControlManager();

    UserModel *user();

    LanguageManager &languageManager();

private:
    std::unique_ptr<UserModel> _user;
    LanguageManager _languageManager;
};

#endif // UICONTROLMANAGER_H
