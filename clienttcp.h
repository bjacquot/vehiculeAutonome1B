#ifndef CLIENTTCP_H
#define CLIENTTCP_H
#include <QTcpSocket>
#include<QDataStream>
#include <QObject>
#include<QString>
#include<QTimer>
#include<QThread>
class ClientTCP : public QObject
{
    Q_OBJECT
public:
    explicit ClientTCP(QObject *parent = nullptr);
private:
    QTcpSocket clientSocket;
    QDataStream dataIn ;
    QTimer tictoc;
    //QTcpSocket * pclientSocket=nullptr;
    void connectToHost();


public slots:
    void sendDatas(QString message);
    void getDatas();
    void arreterQTimer();
    void activerQTimer();

signals:
    void newDatas(QString);

};

#endif // CLIENTTCP_H
