#ifndef UTILS_H
#define UTILS_H

#include <QString>

namespace NetworkUtils {

/**
 * Validate whether a string is a valid IPv4 address.
 * @param ipAddress The string to validate.
 * @return true if the string is a valid IPv4 address, false otherwise.
 */
    bool isValidIPAddress(const QString &ipAddress);

/**
 * Validate whether a string is a valid port number.
 * @param port The string to validate.
 * @return true if the string is a valid port number (1-65535), false otherwise.
 */
    bool isValidPort(const QString &port);

} // namespace NetworkUtils

#endif // UTILS_H
