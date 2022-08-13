#-------------------------------------------------
#
# Project created by QtCreator 2021-07-02T22:55:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GM
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    klein.cpp \
    playwindow.cpp \
    map.cpp \
    button.cpp \
    data.cpp \
    npc.cpp \
    dialog.cpp \
    game.cpp

HEADERS  += widget.h \
    klein.h \
    playwindow.h \
    map.h \
    button.h \
    data.h \
    npc.h \
    GameEnum.h \
    dialog.h \
    game.h

FORMS    += widget.ui

RESOURCES += \
    GMsource.qrc \
    Klein.qrc \
    NpcSource.qrc \
    Game.qrc

OTHER_FILES +=
