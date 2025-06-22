#ifndef REGEXHELPER_H
#define REGEXHELPER_H

#include <QRegularExpression>

namespace RegexHelper {

    /**
     * @brief Provides the regular expression for password validation.
     *
     * The pattern requires at least 8 characters, including at least one lowercase letter,
     * one uppercase letter, and one special character (!@#$%^&*).
     *
     * @return A constant reference to the password validation regex.
     */

    inline const QRegularExpression& PASSWORD() {
        static const QRegularExpression regex(R"(^(?=.*[a-z])(?=.*[A-Z])(?=.*[!@#$%^&*])[A-Za-z\d!@#$%^&*]{8,}$)");
        return regex;
    }

    /**
     * @brief Provides the regular expression for email validation.
     *
     * The pattern matches standard email formats, ensuring the presence of an '@' symbol
     * and a valid domain.
     *
     * @return A constant reference to the email validation regex.
     */

    inline const QRegularExpression& EMAIL() {
        static const QRegularExpression regex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
        return regex;
    }

    /**
     * @brief Validates if the given string is a valid email.
     *
     * The input is matched against the standard email regex pattern.
     *
     * @param value The string to validate as an email.
     * @return `true` if the input matches the email pattern; otherwise, `false`.
     */

    inline bool isEmailValid(const QString& value) {
        return EMAIL().match(value).hasMatch();
    }

    /**
     * @brief Validates if the given string is a valid password.
     *
     * The input must be at least 8 characters long and include at least one uppercase letter,
     * one lowercase letter, and one special character.
     *
     * @param value The string to validate as a password.
     * @return `true` if the input matches the password pattern; otherwise, `false`.
     */

    inline bool isPasswordValid(const QString& value) {
        return PASSWORD().match(value).hasMatch();
    }

}

#endif // REGEXHELPER_H
