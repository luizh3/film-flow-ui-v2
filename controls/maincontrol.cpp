#include "maincontrol.h"

void MainControl::toastSuccess(const QString& message)
{
    emit notifierToastSuccess(message);
}

void MainControl::toastError(const QString& message)
{
    emit notifierToastError(message);
}

void MainControl::toastWarning(const QString& message)
{
    emit notifierToastWarning(message);
}
