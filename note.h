#ifndef NOTE_H
#define NOTE_H

#include "noteplayer.h"

class Note
{
public:
    Note();
    void play();

    DrumNotes drumNote = DrumNotes::Bass;
    double startTimeFromBeginningOfMeasure = 0;

private:
    static NotePlayer notePlayer;
};

struct NoteCompare
{
    bool operator()(const Note* lh, const Note* rh)
    {
        return lh->startTimeFromBeginningOfMeasure < rh->startTimeFromBeginningOfMeasure;
    }
};

#endif // NOTE_H
