#include "clienttcp.h"
#include <qdebug.h>


ClientTCP::ClientTCP(QObject *parent)
    : QObject{parent}
{
    dataIn.setDevice(&clientSocket);
    tictoc.setInterval(100);
    connect(&tictoc,&QTimer::timeout,
            this,&ClientTCP::connectToHost);
    connect(&clientSocket,&QTcpSocket::connected,
            this,&ClientTCP::arreterQTimer);
    connect(&clientSocket,&QTcpSocket::disconnected,
            this,&ClientTCP::activerQTimer);
    connect(&clientSocket,&QTcpSocket::readyRead,
            this,&ClientTCP::getDatas);


    tictoc.start();


}

void ClientTCP::connectToHost()
{
    clientSocket.connectToHost("10.98.32.144",8882);
     qDebug() << "le client est connecté";
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
    emit newDatas("recu");
}

void ClientTCP::arreterQTimer()
{
    tictoc.stop();

}

void ClientTCP::activerQTimer()
{
    tictoc.start();

}
