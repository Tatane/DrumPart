#ifndef NOTEPIANO_H
#define NOTEPIANO_H

#include "note.h"

class NotePiano : public Note
{
public:
    NotePiano(short pitch, short placement);
    unique_ptr<Note> copyToUniquePtr() const override;

private:
    NotePlayer *getNotePlayer() const;
};

#endif // NOTEPIANO_H
