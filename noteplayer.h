#ifndef NOTEPLAYER_H
#define NOTEPLAYER_H

#include <map>

#include "soundmixer.h"

using namespace std;

class NotePlayer
{
public:
    //static NotePlayer * getInstance();
    void play(short pitch);

protected:
    NotePlayer();


    SoundMixer * soundMixer;
    map<short, int> mapDrumNoteSoundIndex; // map Pitch to sound sample index.
    virtual void loadSoundFiles() = 0;

private:

};

#endif // NOTEPLAYER_H
