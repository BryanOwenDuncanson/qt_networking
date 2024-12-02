#include "utils.h"
#include <QRegularExpression>

namespace NetworkUtils {

/**
 * Validate whether a string is a valid IPv4 address.
 * An IPv4 address consists of four octets separated by dots (e.g., 192.168.1.1).
 */
    bool isValidIPAddress(const QString &ipAddress) {
        // IPv4 regular expression
        QRegularExpression ipRegex(
                R"(^((25[0-5]|2[0-4][0-9]|[0-1]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[0-1]?[0-9][0-9]?)$)"
        );

        // Test against the regex
        return ipRegex.match(ipAddress).hasMatch();
    }

/**
 * Validate whether a string is a valid port number (1-65535).
 * Ports must be numeric and within the valid range for TCP/UDP ports.
 */
    bool isValidPort(const QString &port) {
        // Ensure the port is numeric
        bool isNumeric;
        int portNumber = port.toInt(&isNumeric);

        // Check if it's within the valid port range (1-65535)
        return isNumeric && portNumber >= 1 && portNumber <= 65535;
    }

} // namespace NetworkUtils
