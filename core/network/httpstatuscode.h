#ifndef HTTPSTATUSCODE_H
#define HTTPSTATUSCODE_H

#include <QtGlobal>

enum class HttpStatusCode : quint16 {
    OK = 200,
    NOT_FOUND = 404,
    INTERNAL_SERVER_ERROR = 500,
    TIMEOUT = 599
};

#endif // HTTPSTATUSCODE_H
