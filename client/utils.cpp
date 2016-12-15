#include "utils.h"
#include <windows.h>
#include <QTime>
#include <QtCore>
#include <QTime>
#include <QtCore>
#include <list.h>
#include <QMessageBox>

// Fonction de delay au sein de l'application
void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs(millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}


void Utils::print_msg(QString data)
{
#if DEBUG
    qDebug(data.toStdString().c_str());
#endif
}


Utils::Utils(QObject *parent) :
    QThread(parent)
{
}


// On regarde la valeur de la ram et on l'envoi au GUI toutes les secondes
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




Downloader::Downloader(QObject *parent) :
    QThread(parent)
{
    manager = new QNetworkAccessManager;
    manager->deleteLater();
}

// On télécharge le fichier depuis le serveur
void Downloader::doDownload(QString filename){
    QEventLoop eventLoop;
    QString outputFilename = "data/"+filename;
    debug->print_msg("Download of "+ filename +" started");
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QNetworkRequest req( QUrl( QString("http://89.234.183.123/reddit/"+filename) ) );
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec();
    debug->print_msg("Download finished");
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

        debug->print_msg("Error :"+ reply->errorString());
        delete reply;
    }
}

// On récupere tous les noms de fichiers présents sur le serveur
void Downloader::getRoot(){

    QEventLoop eventLoop;
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QNetworkRequest req( QUrl( QString("http://89.234.183.123/reddit/list.php") ) );
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec();
    debug->print_msg("Download of remotes indexs finished");
    if (reply->error() == QNetworkReply::NoError) {
        //success
        QByteArray data = reply->readAll();
        QString DataAsString = QString::fromUtf8(data.toStdString().c_str()).simplified();
        QStringList remoteDataList = DataAsString.split(";");
        debug->print_msg("Remote files");
        debug->print_msg("-----------------------");
        for (int i = 0; i < remoteDataList.size(); ++i){
            debug->print_msg(remoteDataList.at(i));
        }
        Q_EMIT gotRoot(remoteDataList);
        delete reply;
        debug->print_msg("-----------------------");
    }
    else
    {

        debug->print_msg("Error :"+ reply->errorString());
        delete reply;

    }
}

