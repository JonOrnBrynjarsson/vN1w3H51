#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T09:12:36
#
#-------------------------------------------------

QT       += core gui
QT += sql
QT += widgets

RC_FILE = myapp.rc


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vN1w3H51
TEMPLATE = app


SOURCES += main.cpp\
			DataLayer/workingclass.cpp \
			models/scientist.cpp \
			services/service.cpp \
			models/computer.cpp \
			models/computertype.cpp \
			UI/infodisplay.cpp \
    UI/mainwindow.cpp \
    UI/scientistui.cpp \
    UI/computeriu.cpp \
    UI/computertypeui.cpp \
    UI/helpui.cpp \
    UI/displayui.cpp \
    UI/removeui.cpp

HEADERS  +=	DataLayer/workingclass.h \
			models/scientist.h \
			services/service.h \
			models/computer.h \
			models/computertype.h \
			UI/infodisplay.h \
    UI/mainwindow.h \
    UI/scientistui.h \
    UI/computeriu.h \
    UI/computertypeui.h \
    UI/helpui.h \
    UI/displayui.h \
    UI/removeui.h


FORMS    += \
    UI/mainwindow.ui \
    UI/scientistui.ui \
    UI/computeriu.ui \
    UI/computertypeui.ui \
    UI/helpui.ui \
    UI/displayui.ui \
    UI/removeui.ui
