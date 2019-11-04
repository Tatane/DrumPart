#include "noteplayerdrum.h"

NotePlayer* NotePlayerDrum::instance = nullptr;

NotePlayerDrum::NotePlayerDrum()
{
    loadSoundFiles();
}

void NotePlayerDrum::loadSoundFiles()
{
    int index = -1;
    if ((index = soundMixer->loadWav("/home/monom/Music/CYCdh_ElecK01-Kick02.wav")) >= 0)
    {
        mapDrumNoteSoundIndex[DrumNote::Bass] = index;
    }

    if ((index = soundMixer->loadWav("/home/monom/Music/CYCdh_K4-Snr05.wav")) >= 0)
    {
        mapDrumNoteSoundIndex[DrumNote::Snare] = index;
    }

    if ((index = soundMixer->loadWav("/home/monom/Music/CYCdh_Crash-03.wav")) >= 0)
    {
        mapDrumNoteSoundIndex[DrumNote::Crash] = index;
    }

}

NotePlayer * NotePlayerDrum::getInstance()
{
    if (instance == nullptr)
    {
        instance = new NotePlayerDrum;
    }

    return instance;
}
