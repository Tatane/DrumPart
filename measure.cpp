#include "measure.h"

#include <chrono>
#include <iostream>

#include "partition.h"

Measure::Measure(const Partition & part)
    : partition(part)
{
}

Measure::Measure(const Measure &o)
    : timeSignature(o.timeSignature)
    , partition(o.partition)
{
    // Copy Notes
    for(auto & pNote : o.notes)
    {
        notes.insert(pNote->createUnique()); // Make a new unique_ptr Note from a copy of the raw Note stored in model unique_ptr
    }
}

void Measure::operator=(const Measure &o)
{
    // Copy Notes
    for(auto & pNote : o.notes)
    {
        notes.insert(pNote->createUnique()); // Make a new unique_ptr Note from a copy of the raw Note stored in model unique_ptr
    }
}

Measure::Measure(Measure &&o)
    : notes(std::move(o.notes))
    , timeSignature(std::move(o.timeSignature))
    , partition(o.partition)
{
}


void Measure::play()
{
    cout<<"Play Measure"<<endl;
    auto start = chrono::system_clock::now();
    chrono::duration<double> elapsed = chrono::system_clock::now() - start;

    double measureDuration = static_cast<double>(timeSignature.beatsPerMeasure) / partition.getTempo() * 60;

    auto it = notes.begin();

    while( elapsed.count() < measureDuration )
    {
        if (it != notes.end())
        {
            const auto & note = *it;
            if (elapsed.count() > note->convertPlacementToTime(measureDuration) )
            {
                note->play();
                ++it; // next Note.
            }
        }

        elapsed = chrono::system_clock::now() - start;
    }

    cout<<"End Measure"<<endl;
}

void Measure::addNote(unique_ptr<Note> note)
{
    notes.insert(std::move(note));
}
