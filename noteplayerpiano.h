#ifndef NOTEPLAYERPIANO_H
#define NOTEPLAYERPIANO_H

#include "noteplayer.h"

class NotePlayerPiano : public NotePlayer
{
public:
    static NotePlayer* getInstance();

private:
    NotePlayerPiano();
    static NotePlayer * instance;
    void loadSoundFiles();
};

#endif // NOTEPLAYERPIANO_H
