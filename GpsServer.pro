#-------------------------------------------------
#
# Project created by QtCreator 2018-04-18T13:10:49
#
#-------------------------------------------------

QT += core gui network widgets

TARGET = GpsServer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
	main.cpp \
	GPSWindow.cpp \
	GPSServer.cpp \
	GPSThread.cpp

HEADERS += \
	GPSWindow.h \
	GPSServer.h \
	ServerConst.h \
    GPSThread.h

FORMS += \
	GPSWindow.ui

RESOURCES += \
    GPSServer.qrc

DISTFILES +=
