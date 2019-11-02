#include <iostream>

#include "soundmixer.h"
#include "measure.h"
#include "partition.h"

#include "noteplayer.h"

using namespace std;

int main()
{
    shared_ptr<Partition> partition = make_shared<Partition>();
    Measure measure1(partition), measure2(partition);

    // REMARK :
    // The Measure::addNote function has a signature that forces us to pass a rvalue-reference parameter.
    // So we can either move an already existing object (though it will have been nullified on function return), ...
    unique_ptr<Note> note1 = make_unique<Note>(DrumNotes::Bass, 0);
    measure1.addNote(std::move(note1));

    // ... either pass a temporary object :
    measure1.addNote(make_unique<Note>(DrumNotes::Snare, 4));
    measure1.addNote(make_unique<Note>(DrumNotes::Bass, 6));
    measure1.addNote(make_unique<Note>(DrumNotes::Bass, 11));
    measure1.addNote(make_unique<Note>(DrumNotes::Snare, 12));
    measure1.addNote(make_unique<Note>(DrumNotes::Bass, 15));

    measure2 = measure1;

    Measure measure3 = measure1;

    partition->addMeasure(&measure1);
    partition->addMeasure(&measure2);
    partition->addMeasure(&measure3);
    partition->play();

    cout << "TERMINATED" << endl;
    //char c; cin >> c;
    return 0;
}
