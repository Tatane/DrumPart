#ifndef NOTEDRUM_H
#define NOTEDRUM_H

#include "note.h"

class NoteDrum : public Note
{
public:
    NoteDrum(int pitch, short placement);

    NoteDrum(const Note & o)
        : Note(o)
    {
        // TODO Add drum specifics to the new created Note instance.
        o.getPitch();
    }

public:
    void initNotePlayer();

    // Note interface
public:
    unique_ptr<Note> createUnique() const;

    // Note interface
protected:
    NotePlayer *getNotePlayer();
};

#endif // NOTEDRUM_H
