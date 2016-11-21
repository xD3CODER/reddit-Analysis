#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <filecheking.h>
#include <utils.h>
#include <list.h>
#include <QMainWindow>
#include <QThread>
#include <QDir>
#include <QNetworkReply>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    FileCheking *mThread;
    Utils *utils;
    Downloader *download;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public Q_SLOTS:
    // File checking
    void onLoadFinished(bool);
    void onFileChanged(QJsonObject, int, float);
    void onFileSize(float);
    void onRamUpdate(int);
    void onFileDownloaded(QString);



private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_comboBox_activated(const QString &arg1);



    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
     void loadFiles(QString directory = QDir::currentPath());
     void initValues();
     QMovie *movie;
};

#endif // MAINWINDOW_H
