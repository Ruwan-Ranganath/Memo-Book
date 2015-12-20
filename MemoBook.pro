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
    adminwindow.cpp \
    newmemo.cpp \
    managememo.cpp \
    imageviewer.cpp

HEADERS  += mainwindow.h \
    adminwindow.h \
    newmemo.h \
    managememo.h \
    imageviewer.h

FORMS    += mainwindow.ui \
    adminwindow.ui \
    newmemo.ui \
    managememo.ui \
    imageviewer.ui

OTHER_FILES += *.txt \ *.sqlite
