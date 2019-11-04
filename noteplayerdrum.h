#ifndef NOTEPLAYERDRUM_H
#define NOTEPLAYERDRUM_H

#include "noteplayer.h"

class NotePlayerDrum : public NotePlayer
{
public:
    static NotePlayer *getInstance();

private:
    NotePlayerDrum();
    static NotePlayer * instance;
    void loadSoundFiles();
};

namespace DrumNote {
enum
{
    Bass = -3,
    Snare = 1,
    Crash = 6,
    // TODO To be completed
};
}

#endif // NOTEPLAYERDRUM_H
