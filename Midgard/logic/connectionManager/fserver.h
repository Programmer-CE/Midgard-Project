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
    UDoubleList<int> _newConnections;
    QTcpSocket *_connector;
    bool _isConnected;
    bool _listened;
    QString message;
    int serial;
    QString _toSend;
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

    QString toSend() const;
    void setToSend(const QString toSend);

signals:
    void messageReceive();
    void connectionAppear();

public slots:
    void newConnection();
    void ReadyToRead();
    void destroyConnection();
    void send();

};

#endif // FSERVER_H
