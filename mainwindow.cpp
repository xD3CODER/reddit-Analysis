#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QTextCodec>
#include <QThread>
#include <QTime>



float loadedData;
float fileSize;
 QTime myTimer;
 quint32 timestamp;

 int nMilliseconds;
 float kos;
 float restant;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0, 120);
    ui->tableWidget->setColumnWidth(1, 120);
    ui->tableWidget->setColumnWidth(2, 120);
    ui->tableWidget->setColumnWidth(3, 400);
    ui->progressBar->setValue(0);
    loadFiles();
    initValues();
    utils = new Utils(this);
    connect(utils,SIGNAL(ramUsage(int)),this,SLOT(onRamUpdate(int)));
    utils->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadFiles(QString directory)
{
    int count=0;
    QMessageBox msgBox;
    QDir dir(directory+"/data");
    QFileInfoList files = dir.entryInfoList();
    ui->comboBox->clear();
    ui->comboBox->addItem("Sélectionnez un fichier");
    foreach (QFileInfo file, files){
        if (!file.isDir() && file.fileName().endsWith(".json")){

               count++;
               ui->comboBox->addItem(file.baseName());

        }
}

    if (count == 0)
    {
        ui->comboBox->addItem("Aucun fichier disponible");
        ui->comboBox->setEnabled(false);
    }

}

void MainWindow::on_pushButton_clicked()
{







}
void MainWindow::onLoadFinished(bool State)
{
    ui->label_3->setText("Fichier chargé avec succès !");
    mThread->terminate();
    initValues();

}
void MainWindow::onFileSize(float Size)
{

        myTimer.restart();

    fileSize = Size;
    ui->label_2->setText(FileName);
    ui->label->setText("Taille du fichier :" + QString::number(fileSize/1048576, 'f', 4) + " Mo");
    ui->progressBar->setMaximum(100);
}


void MainWindow::onRamUpdate(int usage)
{
    ui->progressBar_2->setValue(usage);
    ui->label_5->setText(QString::number(usage) + "%");
}


void MainWindow::onFileChanged(QJsonObject name, int count)
{


    QJsonDocument doc(name);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    loadedData +=  strJson.length()+3;

    ui->tableWidget->insertRow(count);
    ui->tableWidget->setItem(count, 0, new QTableWidgetItem(name["link_id"].toString()));
    ui->tableWidget->setItem(count, 1, new QTableWidgetItem(name["parent_id"].toString()));
    ui->tableWidget->setItem(count, 2, new QTableWidgetItem(name["id"].toString()));
    ui->tableWidget->setItem(count, 3, new QTableWidgetItem(name["body"].toString()));
    timestamp = name["created_utc"].toString().toUInt();
     QDateTime create;
    ui->tableWidget->setItem(count, 4, new QTableWidgetItem(create.fromTime_t(timestamp).toString("dd/MM/yyyy - hh:mm:ss AP")));
    ui->label_2->setText("Chargé dans la mémoire :" + QString::number(loadedData/1048576, 'f', 4) + " Mo");


        // do something..
        nMilliseconds = myTimer.elapsed();
        kos = (loadedData/1024)/(nMilliseconds*0.001);
        restant = fileSize - loadedData;
        ui->label_3->setText("Vitesse de chargement :" + QString::number(kos, 'f', 2) + " Ko/s");
        ui->label_6->setText("Fini dans : " + QDateTime::fromTime_t(quint32(restant/(kos*1024))).toString("mm:ss"));
        ui->progressBar->setValue((loadedData/fileSize)*100);

}


void MainWindow::on_pushButton_2_clicked()
{


    // Selected file not correct or inexistant
    if (!FileName.endsWith(".json"))
    {
        return;
    }
    ui->label_2->setText("Ouverture du fichier en cours...");
    ui->progressBar->setMaximum(0);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(0);
    // Load File
    mThread = new FileCheking(this);
    connect(mThread,SIGNAL(CheckingThisFile(QJsonObject, int)),this,SLOT(onFileChanged(QJsonObject, int)));
    connect(mThread,SIGNAL(loadFinished(bool)),this,SLOT(onLoadFinished(bool)));
    connect(mThread,SIGNAL(FileSize(float)),this,SLOT(onFileSize(float)));
    // Start thread
    mThread->start();

}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    // Change selected file name
    FileName = arg1+".json";
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{

}

void MainWindow::initValues()
{
    fileSize = loadedData = 0;
    ui->progressBar->setValue(0);
    ui->label_6->clear();
    ui->label_3->clear();
    ui->label->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    /*
    for (int i=0; i<100000; i++)
    {
         const int currentRow = ui->tableWidget->rowCount();
         ui->tableWidget->setRowCount(currentRow + 1);
    }

      mThread->terminate(); //Thread didn't exit in time, probably deadlocked, terminate it!


*/


}

void MainWindow::on_pushButton_4_clicked()
{
     loadFiles();
}
