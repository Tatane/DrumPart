#ifndef NOTE_H
#define NOTE_H

#include "noteplayer.h"

class Note
{
public:
    Note();
    virtual ~Note();
    Note(short pitch, short placement);
    Note(const Note &) = default;

    virtual void initNotePlayer() = 0;
    virtual unique_ptr<Note> createUnique() const = 0;

    void play();

    short   getPlacement() const {return placement;}
    void    setPlacement(short value);

    double convertPlacementToTime(double measureDuration) const;

    short getPitch() const { return pitch; }
    void setPitch(short value) { pitch = value; }

protected:
    virtual NotePlayer * getNotePlayer() = 0;

private:
    const short NB_MAX_SUBDIVISION_PER_MEASURE = 16; // for now, 16th notes are the smallest possible.
    double startTimeFromBeginningOfMeasure = 0;
    short placement = 0;

    short pitch = 0; // 0 is the middle line of the partition. +2 is the line just above. +1 is the 'empty' space between these two lines. -4 is the lowest full line of the partition. Pitch can go higher than +4 and lower than -4 for notes out of the 5 regular lines of the partition.

    char visualRendering;

    // duration : quarter note, eight note, 16th note...
};

struct NoteCompare
{
    //bool operator()(const Note* lh, const Note* rh)
    bool operator()(const unique_ptr<Note> & lh, const unique_ptr<Note> & rh)
    {
        return lh->getPlacement() < rh->getPlacement();
    }
};

#endif // NOTE_H
