#-------------------------------------------------
#
# Project created by QtCreator 2015-10-06T00:25:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 123
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    dialog1.cpp \
    dialog2.cpp \
    data.cpp \
    DDA.cpp \
    bresenham.cpp \
    circle.cpp \
    ellipse.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    dialog1.h \
    dialog2.h \
    data.h \
    DDA.h \
    bresenham.h \
    circle.h \
    ellipse.h

FORMS    += mainwindow.ui \
    dialog.ui \
    dialog1.ui \
    dialog2.ui \
    DDA.ui \
    bresenham.ui \
    circle.ui \
    ellipse.ui
