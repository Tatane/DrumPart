TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    soundmixer.cpp

LIBS += -lSDL2 -lSDL2_mixer

HEADERS += \
    soundmixer.h


CONFIG += c++14
