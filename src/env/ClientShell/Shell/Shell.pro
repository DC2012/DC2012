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
    ../../gamemap.cpp \
    ../../landtile.cpp \
    ../../seatile.cpp \
    ../../../net/client.cpp \
    ../../../net/Message.cpp \
    ../../../player/Point.cpp \
    Player.cpp \
    ../../../player/GameObject.cpp \
    ../../../player/Hitbox.cpp \
    ../../../player/GOS_PowerUp.cpp \
    ../../../player/GOS_Obstacle.cpp \
    ../../../player/GOM_Ship.cpp \
    ../../../player/GOM_Projectile.cpp \
    ../../../player/GameObjectStationary.cpp \
    ../../../player/GameObjectMoveable.cpp \
    ../../../player/Degree.cpp \
    ../../../graphics/tilegraphicsobject.cpp \
    ../../../graphics/shipgraphicsobject.cpp \
    ../../../graphics/graphicsobject.cpp \
    ../../menus/dlgconnection.cpp \
    ../../menus/mainwindow.cpp

HEADERS  += \
    main.h \
    keyinput.h \
    mouseEvent.h \
    shipcomponent.h \
    ../../gamemap.h \
    ../../tile.h \
    ../../../player/Point.h \
    ../../../player/GameObjectMoveable.h \
    ../../../player/GameObjectStationary.h \
    ../../../player/GOM_Ship.h \
    ../../../graphics/tilegraphicsobject.h \
    ../../../graphics/graphicsobject.h \
    ../../../graphics/shipgraphicsobject.h \
    ../../landtile.h \
    ../../seatile.h \
    ../../../net/client.h \
    ../../../net/Message.h \
    Player.h \
    ../../../player/GameObject.h \
    ../../../player/Hitbox.h \
    ../../../player/GOS_PowerUp.h \
    ../../../player/GOS_Obstacle.h \
    ../../../player/GOM_Projectile.h \
    ../../../player/GameObjectFactory.h \
    ../../../player/Degree.h \
    ../../menus/mainwindow.h \
    ../../menus/dlgconnection.h

FORMS    += \
    ../../menus/mainwindow.ui \
    ../../menus/dlgconnection.ui
