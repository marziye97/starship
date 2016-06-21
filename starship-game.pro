#-------------------------------------------------
#
# Project created by QtCreator 2016-06-08T19:50:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = starship-game
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    player.cpp \
    enemy.cpp \
    spaceship.cpp \
    bullet.cpp \
    bullet1.cpp \
    bullet2.cpp

HEADERS  += \
    game.h \
    player.h \
    enemy.h \
    spaceship.h \
    bullet.h \
    bullet1.h \
    bullet2.h

FORMS    +=

RESOURCES += \
    resource.qrc
