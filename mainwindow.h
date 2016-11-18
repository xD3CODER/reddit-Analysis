#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <utils.h>
#include <filecheking.h>
#include <QMainWindow>
#include <QThread>
#include <QDir>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    FileCheking *mThread;
    Utils *utils;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public Q_SLOTS:
    // File checking
    void onLoadFinished(bool);
    void onFileChanged(QJsonObject);
    void onFileSize(float);
    void onRamUpdate(int);



private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
     void loadFiles(QString directory = QDir::currentPath());
};

#endif // MAINWINDOW_H
