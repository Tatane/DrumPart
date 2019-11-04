#ifndef NOTEDRUM_H
#define NOTEDRUM_H

#include "note.h"

class NoteDrum : public Note
{
public:
    NoteDrum(short pitch, short placement);

    unique_ptr<Note> copyToUniquePtr() const override;

private:
    NotePlayer *getNotePlayer() const override;
};

#endif // NOTEDRUM_H
