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
#include <QMovie>
#include <QNetworkAccessManager>
#include "utils.h"
#include "list.h"

float fileSize;
QTime myTimer;

LinkedList* list;
LinkedUsersList* userslist;
void delay(int);
Utils *debug = new Utils();
int nMilliseconds;
float mos;
float kos;
float restant;
int indexOfRemote;
QStringList remoteDataList;
QStringList localDataList;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    getLocalPath();
    initValues();
    WORKER_ram = new Utils(this);
    connect(WORKER_ram,SIGNAL(ramUsage(int)),this,SLOT(onRamUpdate(int)));
    WORKER_ram->start();

    movie = new QMovie("images/loading.gif");
    ui->label_7->setMovie(movie);
    movie->start();
    movie->setPaused(true);

    list = new LinkedList();
    userslist = new LinkedUsersList();
    WORKER_downloader = new Downloader;
    connect(WORKER_downloader,SIGNAL(gotRoot(QStringList)),this,SLOT(onRemotePath(QStringList)));
    WORKER_downloader->getRoot();

}



MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::getLocalPath(QString directory)
{
    int count=0;
    QMessageBox msgBox;
    QDir dir(directory+"/data");
    QFileInfoList files = dir.entryInfoList();
    ui->comboBox->clear();
    ui->comboBox->addItem("   Select file");
    foreach (QFileInfo file, files){
        if (!file.isDir() && file.fileName().endsWith(".json")){
            count++;
            ui->comboBox->addItem(file.baseName());
            localDataList.append(file.baseName()+".json");
        }
    }

    if (count == 0)
    {
        ui->comboBox->addItem("No file avaible");
        ui->comboBox->setEnabled(false);
    }

}

void MainWindow::onRemotePath(QStringList data)
{
    int count=0;
    QMessageBox msgBox;

    for (int i = 0; i < data.size(); ++i){
        if(!localDataList.contains(data.at(i)))
        {
            if (count==0)
            {
                indexOfRemote = ui->comboBox->count();
            }
            count++;
            ui->comboBox->addItem(data.at(i).left(data.at(i).size()-5));
            ui->comboBox->setItemData( ui->comboBox->count()-1, QColor( Qt::yellow ), Qt::BackgroundRole );
        }
    }


    if (count == 0)
    {
        ui->comboBox->addItem("No file avaible");
        ui->comboBox->setEnabled(false);
    }

    WORKER_downloader->terminate();
}


void MainWindow::onLoadFinished(bool)
{
    movie->setPaused(true);
    ui->label_3->setText("File successful loaded");
    WORKER_files->terminate();
    initValues();
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_10->setEnabled(true);

}
void MainWindow::onFileSize(float Size)
{
    myTimer.restart();
    fileSize = Size;
    ui->label_2->setText(FileName);
    ui->label->setText("Size of file :" + QString::number(fileSize/1048576, 'f', 4) + " Mo");
    ui->progressBar->setMaximum(100);
}


void MainWindow::onRamUpdate(int usage)
{
    ui->progressBar_2->setValue(usage);
    ui->label_5->setText(QString::number(usage) + "%");
}


void MainWindow::onFileChanged(float loadedData)
{
    ui->pushButton_3->setEnabled(true);
    nMilliseconds = myTimer.elapsed();
    mos = (loadedData/1048576)/(nMilliseconds*0.001);
    kos = (loadedData/1024)/(nMilliseconds*0.001);
    restant = fileSize - loadedData;
    ui->label_3->setText("Loading speed :" + QString::number(mos, 'f', 2) + " Mo/s");
    ui->label_6->setText("End in : " + QDateTime::fromTime_t(quint32(restant/(kos*1024))).toString("mm:ss"));
    ui->progressBar->setValue((loadedData/fileSize)*100);
}


void MainWindow::loadFile(){
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    if (!FileName.endsWith(".json"))
    {
        return;
    }
    movie->setPaused(false);
    ui->label_2->setText("Opening file...");
    ui->progressBar->setMaximum(0);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(0);
    // Load File
    WORKER_files = new FileCheking(this);
    connect(WORKER_files,SIGNAL(CheckingThisFile(float)),this,SLOT(onFileChanged(float)));
    connect(WORKER_files,SIGNAL(FileSize(float)),this,SLOT(onFileSize(float)));
    connect(WORKER_files,SIGNAL(loadFinished(bool)),this,SLOT(onLoadFinished(bool)));
    // Start thread
    WORKER_files->start();

}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    ui->progressBar->setMaximum(0);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(0);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
     FileName = arg1+".json";
    if(ui->comboBox->currentIndex() < indexOfRemote)
    {
        ui->label_2->setText("Opening file...");
        loadFile();
    }
    else
    {
        ui->label_2->setText("Downloading file...");
        connect(WORKER_downloader,SIGNAL(writingFile(QString)),this,SLOT(onFileWrote(QString)));
        WORKER_downloader->doDownload(arg1+".json");
        debug->print_msg(arg1);
    }

}


void MainWindow::initValues()
{
    fileSize = loadedData = 0;
    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setMinimum(0);
    ui->label_6->clear();
    ui->label_3->clear();
    ui->label->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
      WORKER_files->terminate();
      movie->setPaused(true);
}

void MainWindow::on_pushButton_4_clicked()
{
    getLocalPath();
    WORKER_downloader->getRoot();
}

void MainWindow::on_pushButton_5_clicked()
{
    QFile file(FileName.left(FileName.length() - 5)+"-comments-per-hour.report.csv");
    QTextStream stream(&file);
     if(ui->checkBox->isChecked()){
    file.open(QFile::WriteOnly|QFile::Truncate);
     }
    ui->plainTextEdit->insertPlainText("\n\n");
    ui->plainTextEdit->insertPlainText("### Number of comments by hours ###\n");
    Node *Data = list->head;
    QVector< QVector< int > > stats = list->getCommentDateStats(Data);
    for (int i = 0; i<24; i++)
    { if(ui->checkBox->isChecked()){
        stream << "Hour "+QString::number(i) << ";" << QString::number((((int)stats[0][i]))) << "\n";
        }
        ui->plainTextEdit->insertPlainText("Posted at "+QString::number(i)+"h : " +QString::number((((int)stats[0][i])))+"\n");
        ui->plainTextEdit->moveCursor (QTextCursor::End);
        debug->print_msg("Posted at "+QString::number(i)+"h : " +QString::number((((int)stats[0][i]))));
    }
     if(ui->checkBox->isChecked()){
     file.close();
     ui->plainTextEdit->insertPlainText("###### Report generated ######\n");
     }
     ui->plainTextEdit->insertPlainText("###### Done ######\n");
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->plainTextEdit->insertPlainText("\n\n");
    ui->plainTextEdit->insertPlainText("### Number of new topics ###\n");

    Node *Data = list->head;
    long int count = list->countNewThreads(Data);
    //debug->print_msg(QString::number(count));
    ui->plainTextEdit->insertPlainText(QString::number(count)+" new topics in this file\n");
     ui->plainTextEdit->insertPlainText("###### Done ######\n");
     ui->plainTextEdit->moveCursor (QTextCursor::End);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->plainTextEdit->insertPlainText("\n\n");
    ui->plainTextEdit->insertPlainText("### Number of comments by days ###\n");
     Node *Data = list->head;
    QVector< QVector< int > > stats = list->getCommentDateStats(Data);

    QFile file(FileName.left(FileName.length() - 5)+"-comments-per-day.report.csv");
    QTextStream stream(&file);
     if(ui->checkBox->isChecked()){
    file.open(QFile::WriteOnly|QFile::Truncate);
     }

    for (int i = 1; i<32; i++)
    {
         if(ui->checkBox->isChecked()){
        stream << "Day "+QString::number(i) << ";" << QString::number((((int)stats[1][i]))) << "\n";
         }
         ui->plainTextEdit->insertPlainText("Posted on "+QString::number(i)+" day of this month : " +QString::number((((int)stats[1][i])))+"\n");
        ui->plainTextEdit->moveCursor (QTextCursor::End);
       // debug->print_msg("Posted on "+QString::number(i)+" day of the month : " +QString::number((((int)stats[1][i]))));
    }

     if(ui->checkBox->isChecked()){
    file.close();
    ui->plainTextEdit->insertPlainText("###### Report generated ######\n");
     }
     ui->plainTextEdit->insertPlainText("###### Done ######\n");
}

void MainWindow::onFileWrote(QString file){

      ui->label_2->setText(file+ " Downloaded");
      QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "File downloaded", "Do you want to open it ?",QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
        loadFile();
        WORKER_downloader->terminate();
      } else {
        getLocalPath();
        WORKER_downloader->getRoot();
      }
}



void MainWindow::on_pushButton_10_clicked()
{
    QFile file(FileName.left(FileName.length() - 5)+"-comments-per-user.report.csv");
    QTextStream stream(&file);
     if(ui->checkBox->isChecked()){
    file.open(QFile::WriteOnly|QFile::Truncate);
     }
        ui->plainTextEdit->insertPlainText("\n\n");
        ui->plainTextEdit->insertPlainText("### Messages by users ###\n");
        Node *Liste = list->head;
        Users *t =  userslist->getUsersPosts(Liste);

        while(t != NULL && t->user_ID != "[deleted]")
        {
             if(ui->checkBox->isChecked()){
             stream << t->user_ID << ";" << QString::number(t->messagecount) << "\n";
             }
            ui->plainTextEdit->insertPlainText(t->user_ID +" posted "+QString::number(t->messagecount) +" messages\n");
            ui->plainTextEdit->moveCursor (QTextCursor::End);
           //debug->print_msg( t->user_ID +" à posté "+QString::number(t->messagecount) +" messages");
            t=t->next;
        }
         if(ui->checkBox->isChecked()){
        file.close();
        ui->plainTextEdit->insertPlainText("###### Report generated ######\n");
         }
        ui->plainTextEdit->insertPlainText("###### Done ######\n");
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->plainTextEdit->clear();
}
