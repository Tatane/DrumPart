#include "notedrum.h"

#include "noteplayerdrum.h"

NoteDrum::NoteDrum(short pitch, short placement)
    : Note(pitch, placement)
{
}

unique_ptr<Note> NoteDrum::copyToUniquePtr() const
{
    return unique_ptr<NoteDrum>(new NoteDrum(*this));
}

NotePlayer *NoteDrum::getNotePlayer() const
{
    return NotePlayerDrum::getInstance();
}
