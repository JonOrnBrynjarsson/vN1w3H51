#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T09:12:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vN1w3H51
TEMPLATE = app


SOURCES += main.cpp\
			DataLayer/workingclass.cpp \
			models/scientist.cpp \
			services/service.cpp \
			models/computer.cpp \
			models/computertype.cpp \
			UI/mainwindow.cpp

HEADERS  +=	DataLayer/workingclass.h \
			models/scientist.h \
			services/service.h \
			models/computer.h \
			models/computertype.h \
			UI/mainwindow.h


FORMS    += UI/mainwindow.ui
