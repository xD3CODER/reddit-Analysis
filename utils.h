#ifndef UTILS_H
#define UTILS_H
#include <QThread>
#include <QObject>
#include <QDateTime>
#include <QFile>
#include <QDebug>


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


#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QStringList>

class QDownloader : public QObject
{
    Q_OBJECT
public:
    explicit QDownloader(QObject *parent = 0);
    virtual ~QDownloader();
    void writeFile(QString);
    void getRoot();

private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile *file;
Q_SIGNALS:

private slots:

};


#endif // UTILS_H
