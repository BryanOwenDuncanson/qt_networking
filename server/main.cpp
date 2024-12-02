#include <QCoreApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include "server_daemon.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Set application metadata
    QCoreApplication::setApplicationName("Server Daemon");
    QCoreApplication::setApplicationVersion("1.0");

    // Set up the command-line parser
    QCommandLineParser parser;
    parser.setApplicationDescription("A server daemon that listens on a specific port.");
    parser.addHelpOption();
    parser.addVersionOption();

    // Add an option for the port number
    QCommandLineOption portOption(
            QStringList() << "p" << "port",
            "Port to listen on (default: 8080).",
            "port",
            "8080" // Default value
    );
    parser.addOption(portOption);

    // Process the command-line arguments
    parser.process(app);

    // Get the port number from the arguments
    bool ok;
    quint16 port = parser.value(portOption).toUShort(&ok);
    if (!ok || port == 0) {
        qCritical() << "Invalid port number specified.";
        return 1;
    }

    // Start the server
    ServerDaemon server(port);
    if (!server.start()) {
        qCritical() << "Failed to start the server.";
        return 1;
    }

    return app.exec();
}
