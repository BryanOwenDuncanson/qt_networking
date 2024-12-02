#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QTcpSocket>

class ClientApp : public QWidget {
Q_OBJECT

public:
    explicit ClientApp(QWidget *parent = nullptr);

private slots:
    void sendMessage();

private:
    QTextEdit *messageBox;   // For the 500-character message
    QLineEdit *serverIpBox;  // For server IP input
    QLineEdit *portBox;      // For port input
    QTcpSocket *socket;      // For network communication
};

#endif // CLIENT_H
