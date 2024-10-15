#include "clienttcp.h"
#include <qdebug.h>


ClientTCP::ClientTCP(QString _addressIp, int _port)

{
    addressIp=_addressIp;
    port=_port;
    dataIn.setDevice(&clientSocket);
    tictoc.setInterval(100);
    connect(&tictoc,&QTimer::timeout,
            this,&ClientTCP::connectToHost);
    connect(&clientSocket,&QTcpSocket::connected,
            this,&ClientTCP::connexion);
    connect(&clientSocket,&QTcpSocket::disconnected,
            this,&ClientTCP::deconnexion);
    connect(&clientSocket,&QTcpSocket::readyRead,
            this,&ClientTCP::getDatas);
    tictoc.start();

}

void ClientTCP::connectToHost()
{
  clientSocket.connectToHost("10.98.32.154",8882);
    qDebug()<<" je suis connecté";
}


void ClientTCP::sendDatas(QString message)
{

    /*qDebug()<<"je suis dans sendDatas:";
    message = "salut";
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_0);
    out << message;
    pclientSocket->write(block);*/
    qDebug()<<"message envoyé :"<<message;
}

void ClientTCP::getDatas()
{
    dataIn.startTransaction();
    if (!dataIn.commitTransaction()) return;
    QString message;
    dataIn >> message;
    emit newDatas(message);
}

void ClientTCP::connexion()
{
    tictoc.stop();

}

void ClientTCP::deconnexion()
{
    tictoc.start();

}
