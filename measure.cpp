#include "measure.h"

#include <chrono>
#include <iostream>

#include <partition.h>

Measure::Measure(shared_ptr<Partition> part)
    : partition(part)
{
}


void Measure::play()
{
    cout<<"Play Measure"<<endl;
    auto start = chrono::system_clock::now();
    chrono::duration<double> elapsed = chrono::system_clock::now() - start;

    double measureDuration = static_cast<double>(timeSignature.beatsPerMeasure) / partition->getTempo() * 60;

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


