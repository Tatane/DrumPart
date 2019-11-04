TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    soundmixer.cpp \
    note.cpp \
    measure.cpp \
    partition.cpp \
    noteplayer.cpp \
    noteplayerdrum.cpp \
    notedrum.cpp \
    notepiano.cpp \
    noteplayerpiano.cpp

LIBS += -lSDL2 -lSDL2_mixer

HEADERS += \
    soundmixer.h \
    note.h \
    measure.h \
    partition.h \
    noteplayer.h \
    noteplayerdrum.h \
    notedrum.h \
    notepiano.h \
    noteplayerpiano.h


CONFIG += c++14
