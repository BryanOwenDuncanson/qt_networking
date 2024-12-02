/**
 * @class ServerDaemon
 * @brief The ServerDaemon class manages the server's lifecycle, including starting, stopping,
 * handling new connections, and processing client data.
 */

/**
 * @brief Constructs the ServerDaemon object.
 * @param port The port number the server will listen on.
 * @param parent The parent QObject (default is nullptr).
 */
ServerDaemon::ServerDaemon(quint16 port, QObject *parent)
        : QObject(parent),
          server(new QTcpServer(this)),
          logFile("server_log.txt"),
          serverPort(port) {

    if (!logFile.open(QIODevice::Append | QIODevice::Text)) {
        qWarning() << "Could not open log file for writing.";
    }

    connect(server, &QTcpServer::newConnection, this, &ServerDaemon::onNewConnection);
}

/**
 * @brief Destroys the ServerDaemon object, ensuring the server is stopped and the log file is closed.
 */
ServerDaemon::~ServerDaemon() {
    stop();
    logFile.close();
}

/**
 * @brief Starts the server on the specified port.
 * @return True if the server started successfully, otherwise false.
 */
bool ServerDaemon::start() {
    if (!server->listen(QHostAddress::Any, serverPort)) {
        emit logMessage("Error: Unable to start server on port " + QString::number(serverPort) +
                        " - " + server->errorString());
        return false;
    }

    emit logMessage("Server started on port " + QString::number(serverPort));
    return true;
}

/**
 * @brief Stops the server if it is currently listening for connections.
 */
void ServerDaemon::stop() {
    if (server->isListening()) {
        server->close();
        emit logMessage("Server stopped.");
    }
}

/**
 * @brief Slot to handle new incoming client connections.
 *
 * This function is triggered when a new client connects to the server.
 * It emits a log message with the client's information and sets up connections
 * to handle client-specific signals.
 */
void ServerDaemon::onNewConnection() {
    QTcpSocket *clientSocket = server->nextPendingConnection();
    QString clientInfo = clientSocket->peerAddress().toString() + ":" +
                         QString::number(clientSocket->peerPort());
    emit logMessage("New connection from " + clientInfo);

    connect(clientSocket, &QTcpSocket::disconnected, this, &ServerDaemon::onClientDisconnected);
    connect(clientSocket, &QTcpSocket::readyRead, this, &ServerDaemon::onReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, clientSocket, &QTcpSocket::deleteLater);
}

/**
 * @brief Slot to handle incoming data from a connected client.
 *
 * This function reads data sent by the client, emits a log message with the received data,
 * and optionally echoes the data back to the client.
 */
void ServerDaemon::onReadyRead() {
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());
    if (clientSocket) {
        QString data = clientSocket->readAll();
        emit logMessage("Data received from " + clientSocket->peerAddress().toString() + ": " + data);

        // Echo data back to the client (optional)
        clientSocket->write("Received: " + data.toUtf8());
    }
}

/**
 * @brief Slot to handle client disconnection events.
 *
 * This function is triggered when a client disconnects from the server.
 * It emits a log message with the client's information.
 */
void ServerDaemon::onClientDisconnected() {
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket *>(sender());
    if (clientSocket) {
        QString clientInfo = clientSocket->peerAddress().toString() + ":" +
                             QString::number(clientSocket->peerPort());
        emit logMessage("Client disconnected: " + clientInfo);
    }
}
