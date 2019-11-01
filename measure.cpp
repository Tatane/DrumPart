#include "measure.h"

#include <chrono>
#include <iostream>

#include <partition.h>

Measure::Measure(shared_ptr<Partition> part)
    : partition(part)
{
    // TEMP :
    Note * note1 = new Note;
    note1->setDrumNote(DrumNotes::Snare);
    note1->setPlacement(4);
    notes.insert(note1);

    Note * note2 = new Note;
    note2->setPlacement(0);
    notes.insert(note2);
    Note * note3 = new Note;
    note3->setPlacement(2);
    notes.insert(note3);

}


void Measure::play()
{
    cout<<"Play Measure"<<endl;
    auto start = chrono::system_clock::now();
    chrono::duration<double> elapsed = chrono::system_clock::now() - start;

    double measureDuration = static_cast<double>(timeSignature.beatsPerMeasure) / partition->getTempo() * 60;

    set<Note*>::const_iterator it = notes.begin();

    while( elapsed.count() < measureDuration )
    {
        if (it != notes.end())
        {
            Note * note = *it;
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


