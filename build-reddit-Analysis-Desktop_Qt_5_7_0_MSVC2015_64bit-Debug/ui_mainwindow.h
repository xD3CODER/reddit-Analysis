/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QProgressBar *progressBar;
    QLabel *label;
    QProgressBar *progressBar_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_2;
    QPushButton *pushButton_8;
    QLabel *label_7;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_10;
    QPlainTextEdit *plainTextEdit;
    QCheckBox *checkBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1126, 563);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setStyleSheet(QLatin1String(" #progressBar_2::chunk {\n"
"     background-color: #3399ff;\n"
" }\n"
"QPushButton{\n"
" min-height:30px;\n"
"    max-height:30px;\n"
"    padding: 1px 1px 1px 1px;\n"
"	background : #e5f4ff;\n"
"border: 1px solid #0099ff; \n"
"}\n"
"\n"
"QComboBox{\n"
" min-height:30px;\n"
"    max-height:30px;\n"
"    padding: 1px 1px 1px 1px;\n"
"	background : #e6f5ff;\n"
"border: 1px solid #0099ff; \n"
"}\n"
"\n"
"\n"
"QMainWindow {background: 'white';}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 510, 1111, 51));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_6, 1, 3, 1, 1);

        progressBar = new QProgressBar(gridLayoutWidget_2);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy1);
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        gridLayout_2->addWidget(progressBar, 0, 0, 1, 7);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label, 1, 1, 1, 1);

        progressBar_2 = new QProgressBar(gridLayoutWidget_2);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(progressBar_2->sizePolicy().hasHeightForWidth());
        progressBar_2->setSizePolicy(sizePolicy2);
        progressBar_2->setMaximumSize(QSize(10, 16777215));
        progressBar_2->setValue(12);
        progressBar_2->setTextVisible(false);
        progressBar_2->setOrientation(Qt::Vertical);

        gridLayout_2->addWidget(progressBar_2, 1, 5, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_3, 1, 2, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_4, 1, 4, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMaximumSize(QSize(35, 16777215));

        gridLayout_2->addWidget(label_5, 1, 6, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(100, 0));
        label_2->setMaximumSize(QSize(204, 16777215));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(1030, 90, 81, 34));
        QFont font;
        font.setPointSize(8);
        font.setUnderline(false);
        pushButton_8->setFont(font);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(15, 60, 1101, 61));
        label_7->setMinimumSize(QSize(0, 0));
        label_7->setAlignment(Qt::AlignCenter);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 0, 1091, 69));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QFont font1;
        font1.setPointSize(9);
        comboBox->setFont(font1);
        comboBox->setEditable(false);
        comboBox->setCurrentText(QStringLiteral("   Select file"));

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setFont(font1);

        gridLayout->addWidget(pushButton_6, 0, 4, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setFont(font1);

        gridLayout->addWidget(pushButton_7, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setFont(font1);

        gridLayout->addWidget(pushButton_4, 0, 1, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setFont(font1);

        gridLayout->addWidget(pushButton_5, 0, 3, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setFont(font1);

        gridLayout->addWidget(pushButton_3, 0, 6, 1, 1);

        pushButton_10 = new QPushButton(gridLayoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setFont(font1);

        gridLayout->addWidget(pushButton_10, 0, 5, 1, 1);

        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 130, 1111, 371));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(20, 90, 191, 20));
        QFont font2;
        font2.setPointSize(10);
        checkBox->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);
        gridLayoutWidget_2->raise();
        label_7->raise();
        gridLayoutWidget->raise();
        plainTextEdit->raise();
        checkBox->raise();
        pushButton_8->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "reddit Analysis", 0));
        label_6->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_3->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Ram usage :</p></body></html>", 0));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">TextLabel</p></body></html>", 0));
        label_2->setText(QApplication::translate("MainWindow", "Idle", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "Clean output", 0));
        label_7->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "   Select file", 0)
        );
        pushButton_6->setText(QApplication::translate("MainWindow", "Get topics by month", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "Get Posts by days", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Reload Files", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Get post by hours", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Abort", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "Get messages by users", 0));
        checkBox->setText(QApplication::translate("MainWindow", "Generate reports ?", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
