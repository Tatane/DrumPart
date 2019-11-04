#ifndef NOTEPIANO_H
#define NOTEPIANO_H

#include "note.h"

class NotePiano : public Note
{
public:
    NotePiano(int, int);

    // Note interface
public:
    void initNotePlayer();
    unique_ptr<Note> createUnique() const;

    // Note interface
protected:
    NotePlayer *getNotePlayer();
};

#endif // NOTEPIANO_H
