#include "noteplayer.h"

#include "soundmixer.h"



NotePlayer::NotePlayer()
    : soundMixer(SoundMixer::getInstance())
{

}
/*
void NotePlayer::loadSoundFiles(Instrument instru)
{
    if (instru == Instrument::Drum)
    {
        if (int index = soundMixer->loadWav("/home/monom/Music/CYCdh_ElecK01-Kick02.wav") >= 0)
        {
            mapDrumNoteSoundIndex[-3] = index;
        }

        if (int index = soundMixer->loadWav("/home/monom/Music/CYCdh_K4-Snr05.wav") >= 0)
        {
            mapDrumNoteSoundIndex[1] = index;
        }

        if (int index = soundMixer->loadWav("/home/monom/Music/CYCdh_Crash-03.wav") >= 0)
        {
            mapDrumNoteSoundIndex[6] = index;
        }
    }
}
*/
void NotePlayer::play(short pitch)
{
    if (mapDrumNoteSoundIndex.count(pitch))
    {
        soundMixer->play(mapDrumNoteSoundIndex.at(pitch));
    }
}

