#ifndef MEASURE_H
#define MEASURE_H

#include <set>

#include "note.h"

using namespace std;

/*struct TimeSignature
{
    int beatsPerMeasure = 4;
    int noteValueEquivalentToABeat = 4;
};*/

class Measure
{
public:
    Measure();
    void play();

private:
    set<Note*, NoteCompare> notes;
    //TimeSignature timeSignature;
};

#endif // MEASURE_H
