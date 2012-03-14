#-------------------------------------------------
#
# Project created by QtCreator 2012-03-14T11:32:42
#
#-------------------------------------------------

QT       += core gui

TARGET = Ships
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dlgconnection.cpp \
    ../../../net/client.cpp \
    ../../../net/TCPConnection.cpp \
    ../../../net/tcpClient.cpp \
    ../../../net/Semaphore.cpp \
    ../../../net/Message.cpp \
    ../../../net/CommWrapper.cpp \
    ../../../net/BlockingQueue.cpp

HEADERS  += mainwindow.h \
    dlgconnection.h \
    ../../../net/TCPConnection.h \
    ../../../net/tcpClient.h \
    ../../../net/Semaphore.h \
    ../../../net/Message.h \
    ../../../net/CommWrapper.h \
    ../../../net/client.h \
    ../../../net/BlockingQueue.h

FORMS    += mainwindow.ui \
    dlgconnection.ui
