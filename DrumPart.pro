TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    soundmixer.cpp \
    note.cpp \
    measure.cpp \
    partition.cpp \
    noteplayer.cpp

LIBS += -lSDL2 -lSDL2_mixer

HEADERS += \
    soundmixer.h \
    note.h \
    measure.h \
    partition.h \
    noteplayer.h


CONFIG += c++14
