#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <cstdint>
#include <QString>

class Integration {
public:
    Integration( const QString& token );

    enum class IntegrationType : uint8_t {
        FILM_FLOW
    };

    QString token() const;
    void setToken(const QString &newToken);

private:
    QString _token;

};

#endif // INTEGRATION_H
