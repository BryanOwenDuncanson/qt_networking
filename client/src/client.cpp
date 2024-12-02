// client.cpp
#include "client.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QIntValidator>

ClientApp::ClientApp(QWidget *parent) : QWidget(parent), socket(new QTcpSocket(this)) {
    // Create the layout for the popup window
    auto *layout = new QVBoxLayout(this);

    // Create and configure the message box
    messageBox = new QTextEdit(this);
    messageBox->setPlaceholderText("Enter a message");


    // Create the input box for server IP
    serverIpBox = new QLineEdit(this);
    serverIpBox->setPlaceholderText("Enter server IP (e.g., 127.0.0.1)");

    // Create the input box for port with a validator to allow only numbers
    portBox = new QLineEdit(this);
    portBox->setPlaceholderText("Port range: 1-65535");
    portBox->setValidator(new QIntValidator(1, 65535, this)); //

    // Create the send button
    auto *sendButton = new QPushButton("Send to Server", this);

    // Add widgets to the layout
    layout->addWidget(messageBox);
    layout->addWidget(serverIpBox);
    layout->addWidget(portBox);
    layout->addWidget(sendButton);

    // Connect the send button to the sendMessage() slot
    connect(sendButton, &QPushButton::clicked, this, &ClientApp::sendMessage);
}

void ClientApp::sendMessage() {
    // Get user inputs
    QString message = messageBox->toPlainText();
    QString serverIp = serverIpBox->text();
    QString portText = portBox->text();

    // Validate inputs
    if (message.isEmpty() || serverIp.isEmpty() || portText.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }

    bool portOk;
    quint16 port = portText.toUShort(&portOk);
    if (!portOk) {
        QMessageBox::critical(this, "Port Error", "Invalid port number.");
        return;
    }

    // Connect to the server
    socket->connectToHost(serverIp, port);
    if (socket->waitForConnected(3000)) {
        // Send the message
        socket->write(message.toUtf8());
        socket->flush();
        socket->waitForBytesWritten(3000);

        QMessageBox::information(this, "Success", "Message sent successfully!");
    } else {
        QMessageBox::critical(this, "Connection Error", "Could not connect to the server.");
    }

    // Clear the fields after sending the message
    messageBox->clear();
    serverIpBox->clear();
    portBox->clear();

    // Disconnect from host
    socket->disconnectFromHost();
}
