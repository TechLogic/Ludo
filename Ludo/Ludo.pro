#-------------------------------------------------
#
# Project created by QtCreator 2014-03-21T09:50:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ludo
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
    player.cpp \
    figure.cpp \
    field.cpp \
    dice.cpp \
    map.cpp \
    game.cpp \
    computerplayer.cpp

HEADERS  += \
    player.h \
    figure.h \
    field.h \
    dice.h \
    map.h \
    game.h \
    computerplayer.h

RESOURCES += \
    picture.qrc

