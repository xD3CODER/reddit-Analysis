#include "utils.h"
#include<windows.h>
#include <QTime>
#include <QtCore>
#include <QTime>
#include <QtCore>
#include <list.h>
#include <QMessageBox>



void Utils::msg(QString data)
{
#if DEBUG == 1
qDebug(data.toStdString().c_str());
#endif
}


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



Downloader::Downloader(QObject *parent) :
   QThread(parent)
{
    manager = new QNetworkAccessManager;
 manager->deleteLater();
}

void Downloader::doDownload(QString filename){
    QEventLoop eventLoop;

    QString outputFilename = "/data/"+filename;
       debug->msg("Download of "+ filename +" started");
       QNetworkAccessManager mgr;
       QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));


       QNetworkRequest req( QUrl( QString("http://89.234.183.123/reddit/"+filename) ) );
       QNetworkReply *reply = mgr.get(req);
       eventLoop.exec();
          debug->msg("Download finished");
       if (reply->error() == QNetworkReply::NoError) {
           //success
           QByteArray data = reply->readAll();



           QFile outputFile(outputFilename);
           outputFile.open(QIODevice::WriteOnly);


           if(!outputFile.isOpen()){

           }




           outputFile.write(data);

           outputFile.close();
           Q_EMIT writingFile(outputFilename);

           delete reply;
       }
       else {

            debug->msg("Error :"+ reply->errorString());
           delete reply;

}
}



void Downloader::getRoot(){

       QEventLoop eventLoop;
       QNetworkAccessManager mgr;
       QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

       QNetworkRequest req( QUrl( QString("http://89.234.183.123/reddit/list.php") ) );
       QNetworkReply *reply = mgr.get(req);
       eventLoop.exec();
       debug->msg("Download of index finished");
       if (reply->error() == QNetworkReply::NoError) {
           //success
           QByteArray data = reply->readAll();
           QString DataAsString = QString::fromUtf8( data.toStdString().c_str());

           QString list = "test;test2;test3";
           QStringList remoteDataList = DataAsString.split(";");;
           for (int i = 0; i < remoteDataList.size(); ++i){

               debug->msg(remoteDataList.at(i));
           }



           delete reply;
       }
       else
       {

           debug->msg("Error :"+ reply->errorString());
           delete reply;

}
}

