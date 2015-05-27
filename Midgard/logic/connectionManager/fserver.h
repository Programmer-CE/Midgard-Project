#ifndef FSERVER_H
#define FSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "list/DoubleList.h"
class FServer : public QObject
{
    Q_OBJECT
    QTcpServer *_server;
    UDoubleList<QTcpSocket *> _connectors;
    QTcpSocket *_connector;
    bool _isConnected;
    bool _listened;
    QString message;
    int serial;
public:
    explicit FServer(QObject *parent = 0);

    void openConnection(int pPort);
    void send(QString pMessage);
    ~FServer();
    QString receiver();
    QString getMessage() const;
    bool isListened();
    void setMessage(const QString &value);
    void closeServer();

signals:
    void messageReceive();

public slots:
    void newConnection();
    void ReadyToRead();
    void destroyConnection();

};

#endif // FSERVER_H
