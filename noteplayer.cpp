#include "noteplayer.h"

#include "soundmixer.h"

NotePlayer::NotePlayer()
    : soundMixer(SoundMixer::getInstance())
{
}

void NotePlayer::play(short pitch)
{
    if (mapNotePitchToSoundSampleIndex.count(pitch))
    {
        soundMixer->play(mapNotePitchToSoundSampleIndex.at(pitch));
    }
}

