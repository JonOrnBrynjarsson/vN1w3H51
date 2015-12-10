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
    UI/computertypeui.cpp \
    UI/helpui.cpp \
    UI/displayui.cpp \
    UI/removeui.cpp \
<<<<<<< HEAD
    UI/addnewscientist.cpp \
    UI/addnewcomputer.cpp \
    UI/addnewcomputertype.cpp \
    UI/addrelations.cpp
=======
	UI/computerui.cpp \
	Console_UI/infodisplay.cpp
>>>>>>> b1569bd55477bec3e5a60650fcd8ca384395eb6b

HEADERS  +=	DataLayer/workingclass.h \
			models/scientist.h \
			services/service.h \
			models/computer.h \
			models/computertype.h \
			UI/infodisplay.h \
    UI/mainwindow.h \
    UI/scientistui.h \
    UI/computertypeui.h \
    UI/helpui.h \
    UI/displayui.h \
    UI/removeui.h \
<<<<<<< HEAD
    UI/addnewscientist.h \
    UI/addnewcomputer.h \
    UI/addnewcomputertype.h \
    UI/addrelations.h
=======
	UI/computerui.h \
	Console_UI/infodisplay.h
>>>>>>> b1569bd55477bec3e5a60650fcd8ca384395eb6b


FORMS    += \
    UI/mainwindow.ui \
    UI/scientistui.ui \
    UI/computertypeui.ui \
    UI/helpui.ui \
    UI/displayui.ui \
    UI/removeui.ui \
<<<<<<< HEAD
    UI/addnewscientist.ui \
    UI/addnewcomputer.ui \
    UI/addnewcomputertype.ui \
    UI/addrelations.ui

DISTFILES +=
=======
    UI/computerui.ui
>>>>>>> b1569bd55477bec3e5a60650fcd8ca384395eb6b
