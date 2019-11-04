#include "noteplayerpiano.h"

NotePlayer* NotePlayerPiano::instance = nullptr;

NotePlayerPiano::NotePlayerPiano()
{
    loadSoundFiles();
}

NotePlayer *NotePlayerPiano::getInstance()
{
    if (instance == nullptr)
    {
        instance = new NotePlayerPiano;
    }

    return instance;
}

void NotePlayerPiano::loadSoundFiles()
{
    int index = -1;
    if ((index = soundMixer->loadWav("/home/monom/Music/piano2.wav")) >= 0)
    {
        mapNotePitchToSoundSampleIndex[0] = index;
    }
}
