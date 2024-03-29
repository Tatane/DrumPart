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
    Measure(const Partition &);
    Measure(const Measure& o);
    void operator=(const Measure & o);

    void play();
    void addNote(unique_ptr<Note>);
    Note *getNote(short pitch, int place) const;
    vector<const Note *> getNotes()const;

private:
    set<unique_ptr<Note>, NoteCompare> notes; // Using a 'set' container, we can't have 2 identical notes (same attributs : same placement, same drumnote). Is it what we want ? We could use a 'multiset' instead.
    TimeSignature timeSignature;
    const Partition & partition;
};

#endif // MEASURE_H
