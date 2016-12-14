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
    FileCheking *WORKER_files;
    Utils *WORKER_ram;
    Downloader *WORKER_downloader;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public Q_SLOTS:
    // File checking
    void onLoadFinished(bool);
    void onFileChanged(float);
    void onFileSize(float);
    void onRamUpdate(int);
    void onFileWrote(QString);
    void onRemotePath(QStringList);



private slots:

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
     void getLocalPath(QString directory = QDir::currentPath());
     void initValues();
     void loadFile();
     QMovie *movie;
};

#endif // MAINWINDOW_H
