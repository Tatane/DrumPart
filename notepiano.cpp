#include "notepiano.h"

#include "noteplayerpiano.h"

NotePiano::NotePiano(short pitch, short placement)
    : Note(pitch, placement)
{
}

unique_ptr<Note> NotePiano::copyToUniquePtr() const
{
    return unique_ptr<NotePiano>(new NotePiano(*this));
}

NotePlayer *NotePiano::getNotePlayer() const
{
    return NotePlayerPiano::getInstance();
}
