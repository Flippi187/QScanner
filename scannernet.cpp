#include <QCoreApplication>
#include <QAbstractSocket>
#include <QTcpSocket>

#include "scannernet.h"


ScannerNet::ScannerNet(QObject *parent) : QObject(parent)
{

}

QVector<bool> ScannerNet::Scan(QString hostname, QVector<int> ports)
{
    QVector<bool> r;

    QTcpSocket* socket = new QTcpSocket();

    for ( int i = 0; i < ports.size(); i++)
    {
        socket->connectToHost(hostname, ports[i]);

        if (!socket->waitForConnected(1000)) {  //1000ms
            //qDebug("Port %d: Can not connect", port);
            r.append(false);
        } else {
            //qDebug("Port %d: Connected !", port);
            r.append(true);
            socket->disconnectFromHost();
        }
  }


  return r;
}
