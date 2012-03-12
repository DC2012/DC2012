#-------------------------------------------------
#
# Project created by QtCreator 2012-03-09T14:38:41
#
#-------------------------------------------------

QT       += core gui

TARGET = Shell
TEMPLATE = app


SOURCES += main.cpp \
    mouseEvent.cpp \
    shipcomponent.cpp \
    keyinput.cpp \
    client.cpp

HEADERS  += \
    main.h \
    keyinput.h \
    mouseEvent.h \
    shipcomponent.h \
    client.h \
    ../../gamemap.h \
    ../../tile.h \
    ../../../player/Point.h \
    ../../../player/GameObjectMoveable.h \
    ../../../player/GameObjectStationary.h \
    ../../../player/GOM_Ship.h

FORMS    +=
