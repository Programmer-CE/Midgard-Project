#include "fserver.h"
#include "qthread.h"


QString FServer::getMessage() const
{
    return message;
}

bool FServer::isListened()
{
    return _listened;
}

void FServer::setMessage(const QString &value)
{
    message = value;
}

void FServer::closeServer()
{
    _server->close();
}

QString FServer::toSend() const
{
    return _toSend;
}

void FServer::setToSend(const QString toSend)
{
    _toSend = toSend;
}

FServer::FServer(QObject *parent) :
    QObject(parent)
{
    _isConnected = false;
    serial = 0;
    _server = new QTcpServer();
    _connector = 0;
    connect(_server,SIGNAL(newConnection()),this,SLOT(newConnection()));
    _listened = false;
}

void FServer::openConnection(int pPort)
{
    if (!_listened){
        if (!_server->listen(QHostAddress::Any, pPort)){
        }
        else _listened = true;
    }
}

FServer::~FServer()
{
    while(!_connectors.isEmpty()){
        disconnect(_connectors.get(0),SIGNAL(disconnected()),this,SLOT(destroyConnection()));
        _connectors.get(0)->close();
        delete _connectors.get(0);
        _connectors.remove(0);
    }
    _server->close();
    delete _server;
}

void FServer::send(QString pMessage)
{
    for (int x = 0; x < _connectors.getLenght();x++){
        _connectors.get(x)->write(pMessage.toStdString().c_str());
        _connectors.get(x)->flush();
        _connectors.get(x)->waitForBytesWritten(300);
    }
}

QString FServer::receiver(){
    int lenghtToRead =0;
    QString messageA;
    message = "";
    for (int x = 0; x < _connectors.getLenght();x++){
        lenghtToRead = _connectors.get(x)->bytesAvailable();
        messageA = _connectors.get(x)->read(lenghtToRead);
        message = message.append(messageA);
        _connectors.get(x)->flush();
        _connectors.get(x)->waitForBytesWritten(60);
        send(messageA.toStdString().c_str());
    }
    return message;
}


void FServer::newConnection()
{
    QTcpSocket * newconnector = _server->nextPendingConnection();
    _newConnections.add(_connectors.getLenght());
    _connectors.add(newconnector);
    connect(newconnector,SIGNAL(disconnected()),this,SLOT(destroyConnection()));
    connect(newconnector,SIGNAL(readyRead()),this,SLOT(ReadyToRead()));
    emit connectionAppear();
}

void FServer::ReadyToRead()
{
    receiver();
    emit messageReceive();
}

void FServer::destroyConnection()
{
    qDebug() << "destroy";
    int x = 0;
    while (x < _connectors.getLenght()){
        if (_connectors.get(x)->state() == QTcpSocket::UnconnectedState){
            //_connectors.get(0)->close();
            delete _connectors.get(x);
            _connectors.remove(x);
            break;
        }
        x++;
    }
}

void FServer::send()
{
    send(_toSend);
}
