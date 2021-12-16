#include "scanner.h"
#include "scannernet.h"
#include <QDebug>
#include <QVector>

Scanner::Scanner(QWidget *parent) :
    QWidget(parent)
{
    m_scan = new ScannerNet;
    setupUi(this);
}

void Scanner::on_startButton_clicked()
{
    resultWindow->setText("");
    m_port.clear();

    QStringList portlist = portEntry->text().split(',');
    for(int i = 0; i < portlist.size(); i++) m_port.append(portlist[i].toUInt());

    m_r = ScannerNet::Scan(hostnameEntry->text(), m_port);


    if(m_port[0] != 0)Scanner::Scanneropt();
}

void Scanner::Scanneropt()
{
    QString output;

    for(int i = 0; i < m_r.size(); i ++)
    {
        if(m_r[i] == true)
        {
            output = "Port "+ QString::number(m_port[i]) + ": Connected !";
            resultWindow->setTextColor("green");
        }

        else
        {
            output = "Port " + QString::number(m_port[i]) + ": not connected !";
            resultWindow->setTextColor("red");
        }

        resultWindow->append(output);

    }
}
