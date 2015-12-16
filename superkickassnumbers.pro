#-------------------------------------------------
#
# Project created by QtCreator 2015-12-16T14:31:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = superkickassnumbers
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    endwindow.cpp \
    gamewindow.cpp \
    numbers.cpp \
    scorewidget.cpp

HEADERS  += mainwindow.h \
    endwindow.h \
    gamewindow.h \
    numbers.h \
    scorewidget.h \
    constants.h

FORMS    += mainwindow.ui

RESOURCES += \
    numbersresources.qrc

DISTFILES += \
    assets/score.png
