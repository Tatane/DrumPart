#ifndef NOTE_H
#define NOTE_H

#include "noteplayer.h"

class Note
{
public:
    Note();
    void play();

    double      getStartTimeFromBeginningOfMeasure() const { return startTimeFromBeginningOfMeasure; }
    void        setStartTimeFromBeginningOfMeasure(double d) { startTimeFromBeginningOfMeasure = d; }
    DrumNotes   getDrumNote() const { return drumNote; }
    void        setDrumNote(const DrumNotes &value) {drumNote = value; }

private:
    static NotePlayer notePlayer;
    DrumNotes drumNote = DrumNotes::Bass;
    double startTimeFromBeginningOfMeasure = 0;
};

struct NoteCompare
{
    bool operator()(const Note* lh, const Note* rh)
    {
        return lh->getStartTimeFromBeginningOfMeasure() < rh->getStartTimeFromBeginningOfMeasure();
    }
};

#endif // NOTE_H
