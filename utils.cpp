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



Downloader::Downloader(QObject *parent) :
   QThread(parent)
{
    manager = new QNetworkAccessManager;
 manager->deleteLater();
}

void Downloader::doDownload(QString filename){
    QEventLoop eventLoop;

    QString outputFilename = "/data/"+filename;
        qDebug("Download started");
       QNetworkAccessManager mgr;
       QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
      qDebug("started");

       QNetworkRequest req( QUrl( QString("http://89.234.183.123/reddit/"+filename) ) );
       QNetworkReply *reply = mgr.get(req);
       eventLoop.exec();
        qDebug("finish");
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

           qDebug() << "Failure" <<reply->errorString();
           delete reply;

}
}

void Downloader::run()
{
    QEventLoop eventLoop;

        qDebug("Download started");
       QNetworkAccessManager mgr;
       QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
      qDebug("started");

       QNetworkRequest req( QUrl( QString("https://www.gravatar.com/avatar/c11487528b08658cc7ed023c1cb21511/?s=256&r=g&d=https%3A%2F%2Fopenclassrooms.com%2Fbundles%2Fcommon%2Fimages%2Favatar_defaut.png") ) );
       QNetworkReply *reply = mgr.get(req);
       eventLoop.exec();
        qDebug("finish");
       if (reply->error() == QNetworkReply::NoError) {
           //success
           QByteArray data = reply->readAll();


           QString outputFilename = "RC_2008-03.json";
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

           qDebug() << "Failure" <<reply->errorString();
           delete reply;

}
}

void Downloader::getRoot(){

    QEventLoop eventLoop;


       QNetworkAccessManager mgr;
       QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
      qDebug("started");

       QNetworkRequest req( QUrl( QString("http://89.234.183.123/reddit/list.php") ) );
       QNetworkReply *reply = mgr.get(req);
       eventLoop.exec();
        qDebug("finish");
       if (reply->error() == QNetworkReply::NoError) {
           //success
           QByteArray data = reply->readAll();
           QString DataAsString = QTextCodec::codecForMib(1015)->toUnicode(data);

           QStringList query = DataAsString.split(";");;

           QMessageBox ms;
           ms.setText(data);
           ms.exec();

           for (int i = 0; i < query.size(); ++i)
                qDebug ("a\n");




           delete reply;
       }
       else
       {

           qDebug() << "Failure" <<reply->errorString();
           delete reply;

}
}

