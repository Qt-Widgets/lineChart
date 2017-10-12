#-------------------------------------------------
#
# Project created by QtCreator 2017-09-15T19:06:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = COUNT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    xybrokenlinewidget.cpp \
    xycalculatethread.cpp \
    xyloaddatawidget.cpp

HEADERS  += mainwindow.h \
    xybrokenlinewidget.h \
    xycalculatethread.h \
    xyloaddatawidget.h

FORMS    += mainwindow.ui \
    xyloaddatawidget.ui

RC_FILE = ico.rc
