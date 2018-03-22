#-------------------------------------------------
#
# Project created by QtCreator 2016-06-12T12:00:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StreetPlanner_mkl
TEMPLATE = app


SOURCES += main.cpp\
           mainwindow.cpp \
           city.cpp \
           map.cpp \
           street.cpp \
           dialognewcity.cpp \
           mapionrw.cpp \
           dijkstra.cpp \
           dialognewstreet.cpp \
           mapiofileinput.cpp \
           bigtown.cpp \
           smalltown.cpp \
           stateroad.cpp \
           motorway.cpp

HEADERS += mainwindow.h \
           city.h \
           map.h \
           abstractmap.h \
           street.h \
           dialognewcity.h \
           mapio.h \
           mapionrw.h \
           dijkstra.h \
           dialognewstreet.h \
           mapiofileinput.h \
           bigtown.h \
           smalltown.h \
           stateroad.h \
           motorway.h

FORMS   += mainwindow.ui \
           dialognewcity.ui \
           dialognewstreet.ui
