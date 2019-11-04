#include "notedrum.h"

#include "noteplayerdrum.h"

//unique_ptr<NotePlayer> Note::notePlayer = make_unique<NotePlayerDrum>();
//unique_ptr<NotePlayer> Note::notePlayer = nullptr;
//NotePlayer* Note::notePlayer = NotePlayerDrum::getInstance();

NoteDrum::NoteDrum(int pitch, short placement)
    : Note(pitch, placement)
{
    //initNotePlayer();
    //notePlayer = make_unique<NotePlayerDrum>();

    //notePlayer = NotePlayerDrum::getInstance();
}

void NoteDrum::initNotePlayer()
{
    //notePlayer = make_unique<NotePlayerDrum>();
}

unique_ptr<Note> NoteDrum::createUnique() const
{
    return unique_ptr<NoteDrum>(new NoteDrum(*this));
}

NotePlayer *NoteDrum::getNotePlayer()
{
    return NotePlayerDrum::getInstance();
}
