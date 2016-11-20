#include "utils.h"
#include<windows.h>
#include <QTime>
#include <QtCore>
#include <QTime>
#include <QtCore>
#include <list.h>
#include <QMessageBox>

Utils::Utils(QObject *parent) :
    QThread(parent)
{
}

void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs(millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

void Utils::run(){

    while(Utils::isRunning())
    {
        Utils::sleep(1);
        MEMORYSTATUSEX statex;
        statex.dwLength = sizeof (statex);
        GlobalMemoryStatusEx (&statex);
        Q_EMIT ramUsage(statex.dwMemoryLoad);
    }
}


void Utils::SearchString(QString data)
{

    QString result;
    QMessageBox msgBox;
    Node *o = list->head;
    int counter = 0;
    while (o!= NULL) {
        if (o->data["body"].toString().toLower().contains(data.toLower()))
        {
            counter++;
            result.append(QString::number(counter)+")"+o->data["body"].toString() +"\n*******************");
        }

        o = o->next;
    }

     msgBox.setText("Le mot "+ data +" est utilisé " + QString::number(counter)+ " fois");
     msgBox.exec();
}

