#ifndef FileCheking_H
#define FileCheking_H

#include <QObject>
#include <QThread>
#include <QString>
#include <qjsondocument.h>
#include<qjsonobject.h>
#include<qjsonarray.h>
#include <qfile.h>
//#define DEBUG

extern QString FileName;

class FileCheking : public QThread
{
    Q_OBJECT
public:
    explicit FileCheking(QObject *parent=0);
    void run();
    bool Stop;


Q_SIGNALS:
    void loadFinished(bool);
    void CheckingThisFile(QJsonObject);
    void FileSize(float);

};

#endif // MYTREAD_H
