#ifndef SERVERDAEMON_H
#define SERVERDAEMON_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QTextStream>

class ServerDaemon : public QObject {
Q_OBJECT

public:
    explicit ServerDaemon(quint16 port, QObject *parent = nullptr);
    ~ServerDaemon();

    bool start(); // Starts the server
    void stop();  // Stops the server

signals:
    void logMessage(const QString &message); // Signal, do not implement manually

private slots:
    void onNewConnection();       // Called when a client connects
    void onClientDisconnected();  // Called when a client disconnects
    void onReadyRead();           // Called when data is available to read

private:
    QTcpServer *server;           // The TCP server
    QFile logFile;                // File for logging connections
    quint16 serverPort;           // Port the server listens on

    void logToFile(const QString &message);
};

#endif // SERVERDAEMON_H