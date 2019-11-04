#include "notepiano.h"

#include "noteplayerpiano.h"

//NotePlayer* Note::notePlayer = NotePlayerPiano::getInstance();

NotePiano::NotePiano(int, int)
{

}

void NotePiano::initNotePlayer()
{

}

unique_ptr<Note> NotePiano::createUnique() const
{
    return unique_ptr<NotePiano>(new NotePiano(*this));
}

NotePlayer *NotePiano::getNotePlayer()
{
    return NotePlayerPiano::getInstance();
}
