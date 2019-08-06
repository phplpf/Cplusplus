#-------------------------------------------------
#
# Project created by QtCreator 2019-08-04T16:26:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Thread1
TEMPLATE = app


SOURCES += main.cpp\
        threaddialog.cpp \
    worker.cpp

HEADERS  += threaddialog.h \
    worker.h

FORMS    += threaddialog.ui
