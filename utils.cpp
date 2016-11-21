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



QDownloader::QDownloader(QObject *parent) :
    QObject(parent)
{
    manager = new QNetworkAccessManager;

}

QDownloader::~QDownloader()
{
    manager->deleteLater();
}

void QDownloader::getRoot(){

    QEventLoop eventLoop;


       QNetworkAccessManager mgr;
       QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
      qDebug("started");

       QNetworkRequest req( QUrl( QString("http://89.234.183.123/reddit/") ) );
       QNetworkReply *reply = mgr.get(req);
       eventLoop.exec();
        qDebug("finish");
       if (reply->error() == QNetworkReply::NoError) {
           //success
           QByteArray data = reply->readAll();
           QRegularExpression regex("<a href=\"(.*)\">(.*)</a></td><td align=\"right\">");
           QRegularExpressionMatch match = regex.match(data);

           QString textYouWant = match.captured(3);


            qDebug() << "Done" << textYouWant;
           delete reply;
       }
       else
       {

           qDebug() << "Failure" <<reply->errorString();
           delete reply;

}
}

void QDownloader::writeFile(QString filename){

    QEventLoop eventLoop;


       QNetworkAccessManager mgr;
       QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
      qDebug("started");

       QNetworkRequest req( QUrl( QString("http://89.234.183.123/reddit/RC_2008-01.json") ) );
       QNetworkReply *reply = mgr.get(req);
       eventLoop.exec();
        qDebug("finish");
       if (reply->error() == QNetworkReply::NoError) {
           //success
           QByteArray data = reply->readAll();


           QString outputFilename = "Results.txt";
           QFile outputFile(outputFilename);
           outputFile.open(QIODevice::WriteOnly);


           if(!outputFile.isOpen()){

           }




           outputFile.write(data);

           outputFile.close();


           delete reply;
       }
       else {

           qDebug() << "Failure" <<reply->errorString();
           delete reply;

}

}
