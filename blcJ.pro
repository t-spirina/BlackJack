TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    card.cpp \
    hand.cpp \
    genericplayer.cpp \
    player.cpp \
    deck.cpp \
    game.cpp \
    house.cpp

HEADERS += \
    card.h \
    hand.h \
    genericplayer.h \
    player.h \
    deck.h \
    game.h \
    house.h
