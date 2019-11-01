#ifndef NOTEPLAYER_H
#define NOTEPLAYER_H

#include <map>

#include "soundmixer.h"

using namespace std;

enum class DrumNotes
{
  Bass,
  Snare
};

class NotePlayer
{
public:
    NotePlayer();
    void play(DrumNotes drumNote);

private:
    SoundMixer * soundMixer;
    map<DrumNotes, int> mapDrumNoteSoundIndex;
    void loadSoundFiles();
};

#endif // NOTEPLAYER_H
