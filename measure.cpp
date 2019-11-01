#include "measure.h"

#include <chrono>
#include <iostream>

Measure::Measure()
{
    // TEMP :
    Note * note1 = new Note;
    note1->setStartTimeFromBeginningOfMeasure(2);
    note1->setDrumNote(DrumNotes::Snare);
    notes.insert(note1);

    Note * note2 = new Note;
    note2->setStartTimeFromBeginningOfMeasure(1);
    notes.insert(note2);
    Note * note3 = new Note;
    note3->setStartTimeFromBeginningOfMeasure(1.5);
    notes.insert(note3);
}

void Measure::play()
{
    cout<<"Play Measure"<<endl;
    auto start = chrono::system_clock::now();

    for(set<Note*>::const_iterator it = notes.begin(); it != notes.end(); )
    {
        chrono::duration<double> elapsed = chrono::system_clock::now() - start;

        Note * note = *it;
        if (elapsed.count() > note->getStartTimeFromBeginningOfMeasure() )
        {
            note->play();
            ++it; // next Note.
        }
    }
    cout<<"End Measure"<<endl;
}


