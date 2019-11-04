#ifndef NOTE_H
#define NOTE_H

#include "noteplayer.h"

class Note
{
public:
    Note() = default;
    Note(short pitch, short placement);
    Note(const Note &) = default;
    virtual ~Note();

    virtual unique_ptr<Note> copyToUniquePtr() const = 0;

    void play();

    short   getPlacement() const {return placement;}
    void    setPlacement(short value);

    short   getPitch() const { return pitch; }
    void    setPitch(short value) { pitch = value; }

    double  convertPlacementToTime(double measureDuration) const;

private:
    virtual NotePlayer * getNotePlayer() const = 0;

    const short NB_MAX_SUBDIVISION_PER_MEASURE = 16; // for now, 16th notes are the smallest possible.
    double startTimeFromBeginningOfMeasure = 0;
    short pitch = 0; // 0 is the middle line of the partition. +2 is the line just above. +1 is the 'empty' space between these two lines. -4 is the lowest full line of the partition. Pitch can go higher than +4 and lower than -4 for notes out of the 5 regular lines of the partition.
    short placement = 0;
    // duration : quarter note, eight note, 16th note...
    // char visualRendering;
};

struct NoteCompare
{
    bool operator()(const unique_ptr<Note> & lh, const unique_ptr<Note> & rh)
    {
        return lh->getPlacement() < rh->getPlacement();
    }
};

#endif // NOTE_H
