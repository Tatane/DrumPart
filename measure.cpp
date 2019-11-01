#include "measure.h"

#include <chrono>
#include <iostream>

Measure::Measure()
{
    // TEMP :
    Note * note1 = new Note;
    note1->startTimeFromBeginningOfMeasure = 5;
    notes.insert(note1);

    Note * note2 = new Note;
    note2->startTimeFromBeginningOfMeasure = 2;
    notes.insert(note2);
}

void Measure::play()
{
    cout<<"Play Measure"<<endl;
    auto start = chrono::system_clock::now();

    for(set<Note*>::const_iterator it = notes.begin(); it != notes.end(); )
    {
        chrono::duration<double> elapsed = chrono::system_clock::now() - start;

        Note * note = *it;
        if (elapsed.count() > note->startTimeFromBeginningOfMeasure )
        {
            note->play();
            ++it; // next Note.
        }
    }
    cout<<"End Measure"<<endl;
}


