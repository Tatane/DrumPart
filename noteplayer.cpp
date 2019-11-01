#include "noteplayer.h"

#include "soundmixer.h"

NotePlayer::NotePlayer()
    : soundMixer(SoundMixer::getInstance())
{
    loadSoundFiles();
}

void NotePlayer::loadSoundFiles()
{
    int index = soundMixer->loadWav("/home/monom/Music/piano2.wav");

    if (index >= 0)
    {
        mapDrumNoteSoundIndex[DrumNotes::Bass] = index;
    }
}

void NotePlayer::play(DrumNotes drumNote)
{
    if (mapDrumNoteSoundIndex.count(drumNote))
    {
        soundMixer->play(mapDrumNoteSoundIndex.at(drumNote));
    }
}
