#ifndef NOTE_H
#define NOTE_H

#include "noteplayer.h"

class Note
{
public:
    Note();
    void play();

    DrumNotes   getDrumNote() const { return drumNote; }
    void        setDrumNote(const DrumNotes &value) {drumNote = value; }

    short   getPlacement() const {return placement;}
    void    setPlacement(short value);

    double convertPlacementToTime(double measureDuration);

private:
    const short NB_MAX_SUBDIVISION_PER_MEASURE = 16; // for now, 16th notes are the smallest possible.
    static NotePlayer notePlayer;
    DrumNotes drumNote = DrumNotes::Bass;
    double startTimeFromBeginningOfMeasure = 0;
    short placement = 0;
};

struct NoteCompare
{
    bool operator()(const Note* lh, const Note* rh)
    {
        return lh->getPlacement() < rh->getPlacement();
    }
};

#endif // NOTE_H
