#ifndef UTILS_H
#define UTILS_H
#include <QThread>
#include <QObject>
#include <QDateTime>
#include <QFile>
#include <QDebug>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QStringList>

class Utils : public QThread
{
    Q_OBJECT
public:
    explicit Utils(QObject *parent=0);
    void run();
    bool Stop;
    void doDownload();
void SearchString(QString data);

Q_SIGNALS:
    void ramUsage(int);

};


class Downloader : public QThread
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = 0);
    bool Stop;
    void doDownload(QString);
    void run();
    void SearchString(QString data);
    void writeFile(QString);
    void getRoot();
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile *file;
Q_SIGNALS:
void writingFile(QString);

};


#endif // UTILS_H
