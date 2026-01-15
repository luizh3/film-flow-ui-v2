#ifndef CONTROL_H
#define CONTROL_H

#include <QObject>

#include "chainbasehandlercalls.h"

class Control : public QObject, public ChainBaseHandlerCalls
{
    Q_OBJECT
public:
    Control();
    ~Control();

signals:
    void notifierLanguageChanged();
};

#endif // CONTROL_H
