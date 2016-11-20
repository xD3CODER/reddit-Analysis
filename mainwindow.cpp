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
#include <QSortFilterProxyModel>
#include <list.h>
#include <QMovie>
float fileSize;
QTime myTimer;
quint32 timestamp;
LinkedList* list;
void delay(int);
 int nMilliseconds;
 float mos;
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

 movie = new QMovie("images/loading.gif");
    ui->label_7->setMovie(movie);
    movie->start();
    movie->setPaused(true);



    list = new LinkedList(); // I declare a pointer to a list
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
void MainWindow::onLoadFinished(bool)
{
    movie->setPaused(true);
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


void MainWindow::onFileChanged(QJsonObject , int , float loadedData)
{



   /*
    ui->tableWidget->insertRow(count);
    ui->tableWidget->setItem(count, 0, new QTableWidgetItem(name["link_id"].toString()));
    ui->tableWidget->setItem(count, 1, new QTableWidgetItem(name["parent_id"].toString()));
    ui->tableWidget->setItem(count, 2, new QTableWidgetItem(name["id"].toString()));
    ui->tableWidget->setItem(count, 3, new QTableWidgetItem(name["name"].toString()));
    ui->tableWidget->setItem(count, 4, new QTableWidgetItem(name["body"].toString()));
    */

//    ui->label_2->setText("Chargé dans la mémoire :" + QString::number(loadedData/1048576, 'f', 4) + " Mo");


        // do something..
        nMilliseconds = myTimer.elapsed();
        mos = (loadedData/1048576)/(nMilliseconds*0.001);
        kos = (loadedData/1024)/(nMilliseconds*0.001);
        restant = fileSize - loadedData;
        ui->label_3->setText("Vitesse de chargement :" + QString::number(mos, 'f', 2) + " Mo/s");
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
    movie->setPaused(false);
    ui->label_2->setText("Ouverture du fichier en cours...");
    ui->progressBar->setMaximum(0);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(0);
    // Load File
    mThread = new FileCheking(this);
    connect(mThread,SIGNAL(CheckingThisFile(QJsonObject, int, float)),this,SLOT(onFileChanged(QJsonObject, int, float)));
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

void MainWindow::on_pushButton_5_clicked()
{




    /* SEARCH IN QTABLE

    QString findName = "t3_7ajqp";
    QAbstractItemModel *modl = ui->tableWidget->model();
    QSortFilterProxyModel proxy;
    proxy.setSourceModel(modl);
    proxy.setFilterKeyColumn(1);
    proxy.setFilterFixedString(findName);
    // now the proxy only contains rows that match the name
    // let's take the first one and map it to the original model
    for (int i=0; ui->tableWidget->rowCount(); i++)
    {
        QModelIndex matchingIndex = proxy.mapToSource(proxy.index(i,i));
        if(matchingIndex.isValid()){

            ui->tableWidget->scrollTo(matchingIndex,QAbstractItemView::EnsureVisible);
            QString data = ui->tableWidget->model()->data(ui->tableWidget->model()->index(matchingIndex.row(),3)).toString();
          //  QMessageBox::information(this,"Name Search:", data);
            ui->label_2->setText(data);
         //   ui->tableWidget->setRowCount(0);

         //   ui->tableWidget->setRowHidden(!matchingIndex.row(), true);
        } else {
            //QMessageBox::information(this,"Name Search:", "Match not found!");
        }
    }
      ui->label_3->setText("finish");
    proxy.clear();

    */



}

void MainWindow::on_pushButton_6_clicked()
{
     QString result;
     QMessageBox msgBox;
     Node *temp = list->head;
     int counter = 0;
     while (temp!= NULL) {
         ui->tableWidget->insertRow(counter);
         ui->tableWidget->setItem(counter, 0, new QTableWidgetItem(temp->data["link_id"].toString()));
         ui->tableWidget->setItem(counter, 1, new QTableWidgetItem(temp->data["parent_id"].toString()));
         ui->tableWidget->setItem(counter, 2, new QTableWidgetItem(temp->data["id"].toString()));
         ui->tableWidget->setItem(counter, 3, new QTableWidgetItem(temp->data["name"].toString()));
         ui->tableWidget->setItem(counter, 4, new QTableWidgetItem(temp->data["body"].toString()));
         timestamp = temp->data["created_utc"].toString().toUInt();
         QDateTime create;
         ui->tableWidget->setItem(counter, 5, new QTableWidgetItem(create.fromTime_t(timestamp).toString("dd/MM/yyyy - hh:mm:ss AP")));
         ui->tableWidget->setItem(counter, 6, new QTableWidgetItem(temp->data["author"].toString()));
         counter++;
         temp = temp->next;
     }
     msgBox.setText("Finished");
     msgBox.exec();
}

void MainWindow::on_pushButton_7_clicked()
{
    Utils Checking;
    if (ui->radioButton->isChecked())
    {
         Checking.SearchString(" "+ui->textEdit->toPlainText()+" ");
    }
    else
    {
         Checking.SearchString(ui->textEdit->toPlainText());
    }


}
