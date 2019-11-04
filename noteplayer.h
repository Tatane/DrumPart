#ifndef NOTEPLAYER_H
#define NOTEPLAYER_H

#include <map>

#include "soundmixer.h"

using namespace std;

class NotePlayer
{
public:
    void play(short pitch);

protected:
    NotePlayer();
    SoundMixer * soundMixer;
    map<short, int> mapNotePitchToSoundSampleIndex; // map Pitch to sound sample index.

private:
    virtual void loadSoundFiles() = 0;
};

#endif // NOTEPLAYER_H
