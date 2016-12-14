#ifndef FileCheking_H
#define FileCheking_H

#include <QObject>
#include <QThread>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include<QJsonArray>
#include <QFile>

//#define DEBUG

extern QString FileName;
extern int NumberOfLine;

extern float loadedData;
class FileCheking : public QThread
{
    Q_OBJECT
public:
    explicit FileCheking(QObject *parent=0);
    void run();
    bool Stop;

Q_SIGNALS:
    void loadFinished(bool);
    void CheckingThisFile(float);
    void FileSize(float);

};

#endif // MYTREAD_H
