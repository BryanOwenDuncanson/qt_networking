#ifndef APIHANDLER_H
#define APIHANDLER_H

#include <qstring.h>

class ApiHandler {
public:
    // Constructor to initialize API endpoint
    ApiHandler(const std::string& apiUrl, const std::string& outputDir);

    // Makes an API request and saves the response to a file
    bool fetchAndSave(const std::string& fileName);

private:
    std::string apiUrl;       // The API endpoint URL
    std::string outputDir;    // Directory to save the responses

    // Helper method for making the API call
    std::string makeApiRequest();

    // Writes the response to a file
    bool writeToFile(const std::string& content, const std::string& filePath);
};

#endif // APIHANDLER_H
