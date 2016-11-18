#ifndef UTILS_H
#define UTILS_H
#include <QThread>
#include <QObject>





class Utils : public QThread
{
    Q_OBJECT
public:
    explicit Utils(QObject *parent=0);
    void run();
    bool Stop;


Q_SIGNALS:
    void ramUsage(int);

};
#endif // UTILS_H
