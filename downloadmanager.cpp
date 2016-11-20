#include <QCoreApplication>
#include <QMessageBox>
#include <QString>
#include "downloadmanager.h"

// constructor
DownloadManager::DownloadManager()
{
    // signal finish(), calls downloadFinished()
    connect(&manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(downloadFinished(QNetworkReply*)));
}

void DownloadManager::execute(QString url)
{


        QUrl urls = QUrl::fromEncoded(url.toLocal8Bit());

        // makes a request
        doDownload(urls);

}

// Constructs a QList of QNetworkReply
void DownloadManager::doDownload(const QUrl &url)

{
    QMessageBox msg;
    msg.setText("Download started");
    msg.exec();

    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);

#ifndef QT_NO_SSL
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)), SLOT(sslErrors(QList<QSslError>)));
#endif

    // List of reply
    currentDownloads.append(reply);
}

QString DownloadManager::saveFileName(const QUrl &url)
{
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty())
        basename = "download";

    if (QFile::exists(basename)) {
        QMessageBox msg;
        msg.setText("File exist");
        msg.exec();
        int i = 0;
        basename += '.';
        while (QFile::exists(basename + QString::number(i)))
            ++i;

        basename += QString::number(i);
    }

    return basename;
}

void DownloadManager::downloadFinished(QNetworkReply *reply)
{
    QMessageBox msg;
    msg.setText("finish");
    msg.exec();

    QUrl url = reply->url();
    if (reply->error()) {
        fprintf(stderr, "Download of %s failed: %s\n",
                url.toEncoded().constData(),
                qPrintable(reply->errorString()));
    } else {
        QString filename = saveFileName(url);
        if (saveToDisk(filename, reply))
        {
             QMessageBox msg;
             msg.setText("Download of %s succeeded (saved to %s)\n"
                        + filename);
             msg.exec();
        }

    }

    currentDownloads.removeAll(reply);
    reply->deleteLater();

    if (currentDownloads.isEmpty()){
        QMessageBox msg;
        msg.setText("Finish");
        msg.exec();
        QCoreApplication::instance()->quit();
    }
}

bool DownloadManager::saveToDisk(const QString &filename, QIODevice *reply)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox msg;
        msg.setText("Peu pas ecrire");
        msg.exec();
        return false;
    }

    file.write(reply->readAll());
    file.close();

    return true;
}

void DownloadManager::sslErrors(const QList<QSslError> &sslErrors)
{
#ifndef QT_NO_SSL
    foreach (const QSslError &error, sslErrors)
    {
        QMessageBox msg;
        msg.setText("SSl error");
        msg.exec();
    }
#else
    Q_UNUSED(sslErrors);
#endif
}


