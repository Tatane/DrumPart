#include "noteplayer.h"

#include "soundmixer.h"

NotePlayer::NotePlayer()
    : soundMixer(SoundMixer::getInstance())
{
    loadSoundFiles();
}

void NotePlayer::loadSoundFiles()
{
    //int index = soundMixer->loadWav("/home/monom/Music/piano2.wav");
    int index = soundMixer->loadWav("/home/monom/Music/CYCdh_ElecK01-Kick02.wav");

    if (index >= 0)
    {
        mapDrumNoteSoundIndex[DrumNotes::Bass] = index;
    }

    if (int index = soundMixer->loadWav("/home/monom/Music/CYCdh_K4-Snr05.wav") >= 0)
    {
        mapDrumNoteSoundIndex[DrumNotes::Snare] = index;
    }
}

void NotePlayer::play(DrumNotes drumNote)
{
    if (mapDrumNoteSoundIndex.count(drumNote))
    {
        soundMixer->play(mapDrumNoteSoundIndex.at(drumNote));
    }
}
