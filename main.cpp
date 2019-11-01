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

        // TEMP :
        unique_ptr<Note> note1 = make_unique<Note>();
        note1->setDrumNote(DrumNotes::Snare);
        note1->setPlacement(4);
        measure1.addNote(std::move(note1));

        unique_ptr<Note> note2 = make_unique<Note>();
        note2->setPlacement(0);
        measure1.addNote(std::move(note2));
        unique_ptr<Note> note3 = make_unique<Note>();
        note3->setPlacement(2);
        measure1.addNote(std::move(note3));

    partition->addMeasure(&measure1);
    partition->addMeasure(&measure2);
    partition->play();

    cout << "Hello World!" << endl;
    char c; cin >> c;
    return 0;
}
