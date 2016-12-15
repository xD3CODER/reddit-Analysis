#-------------------------------------------------
#
# Project created by QtCreator 2016-11-03T09:16:20
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Boum
TEMPLATE = app

RC_FILE = myapp.rc
SOURCES += main.cpp\
        mainwindow.cpp \
    filecheking.cpp \
    utils.cpp \
    list.cpp

HEADERS  += mainwindow.h \
    filecheking.h \
    utils.h \
    list.h

FORMS    += mainwindow.ui
