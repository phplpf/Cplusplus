#-------------------------------------------------
#
# Project created by QtCreator 2019-08-04T17:08:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Thread2
TEMPLATE = app


SOURCES += main.cpp\
        threaddialog.cpp \
    workerthread.cpp

HEADERS  += threaddialog.h \
    workerthread.h

FORMS    += threaddialog.ui
