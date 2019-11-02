#ifndef MEASURE_H
#define MEASURE_H

#include <set>

#include "note.h"

class Partition;

using namespace std;

struct TimeSignature
{
    int beatsPerMeasure = 4;
    //int noteValueEquivalentToABeat = 4;
};

class Measure
{
public:
    Measure(shared_ptr<Partition>);
    Measure(const Measure& o);
    void operator=(const Measure & o);
    Measure(Measure && o);

    void play();
    void addNote(unique_ptr<Note> &&);

private:
    set<unique_ptr<Note>, NoteCompare> notes;
    TimeSignature timeSignature;
    shared_ptr<Partition> partition;
};

#endif // MEASURE_H
