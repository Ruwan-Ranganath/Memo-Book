 #-------------------------------------------------
#
# Project created by QtCreator 2015-12-18T00:36:37
#
#-------------------------------------------------


QT       += sql


QT += core gui declarative


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MemoBook
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    homewindow.cpp

HEADERS  += mainwindow.h \
    homewindow.h

FORMS    += mainwindow.ui \
    homewindow.ui
