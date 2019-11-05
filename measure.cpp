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
    // Duplicate Notes
    for(auto & pNote : o.notes)
    {
        notes.insert(pNote->copyToUniquePtr()); // Make a new unique_ptr Note from a copy of the raw Note stored in model unique_ptr
    }
}

void Measure::operator=(const Measure &o)
{
    // Duplicate Notes
    for(auto & pNote : o.notes)
    {
        notes.insert(pNote->copyToUniquePtr()); // Make a new unique_ptr Note from a copy of the raw Note stored in model unique_ptr
    }
}

void Measure::play()
{
    cout<<"Play Measure"<<endl;

    auto start = chrono::system_clock::now();
    chrono::duration<double> elapsed = chrono::system_clock::now() - start;

    auto it = notes.begin();
    double measureDuration = static_cast<double>(timeSignature.beatsPerMeasure) / partition.getTempo() * 60;
    while( elapsed.count() < measureDuration )
    {
        if (it != notes.end())
        {
            const unique_ptr<Note> & note = *it;
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

Note * Measure::getNote(short pitch, int place) const
{
    Note * ret = nullptr;
    for(auto & note : notes)
    {
        if (note->getPitch() == pitch && note->getPlacement() == place)
        {
            ret = note.get();
        }
    }

    return ret;
}

vector<const Note *> Measure::getNotes() const
{
    vector<const Note *> ret;
    for(const unique_ptr<Note> & note : notes)
    {
        ret.push_back(note.get());
    }

    return ret;
}
