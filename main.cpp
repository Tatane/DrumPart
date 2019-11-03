#include <iostream>

#include "soundmixer.h"
#include "measure.h"
#include "partition.h"

#include "noteplayer.h"

using namespace std;

int main()
{
    Partition partition;

    /*
    unique_ptr<Measure> measure1 = make_unique<Measure>(partition);
            //, measure2(partition);

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
*/

    //unique_ptr<Measure> meas1 = make_unique<Measure>(partition);
    //partition->insertMeasure(0, std::move(meas1));

    make_unique<Measure>(partition);

    unique_ptr<Measure> & newMeas1 = partition.insertMeasure(0);
    //unique_ptr<Measure> & newMeas2 = partition.insertMeasure(1);
    //unique_ptr<Measure> & newMeas3 = partition.insertMeasure(2);
    //unique_ptr<Measure> & newMeas4 = partition.insertMeasure(3);

    newMeas1->addNote(make_unique<Note>(DrumNotes::Bass, 0));
    newMeas1->addNote(make_unique<Note>(DrumNotes::Snare, 4));
    newMeas1->addNote(make_unique<Note>(DrumNotes::Bass, 8));
    newMeas1->addNote(make_unique<Note>(DrumNotes::Snare, 12));

    unique_ptr<Measure> meas2(new Measure(*newMeas1));
    partition.insertMeasure(1, std::move(meas2));

    partition.insertMeasure(2, unique_ptr<Measure>(new Measure(*newMeas1)));

    //newMeas2->addNote(make_unique<Note>(DrumNotes::Bass, 0));
    //newMeas3->addNote(make_unique<Note>(DrumNotes::Bass, 0));
    //newMeas4->addNote(make_unique<Note>(DrumNotes::Bass, 0));

    //partition->addMeasure(&measure2);
    //partition->addMeasure(&measure3);
    partition.play();


    /*

Ajouter une note a une mesure deja existante.
Modifier le Type d'une note existante.
Deplacer une note deja existante (modifier son Placement)
Deplacer une note vers une autre mesure
Supprimer une note

Ajouter une mesure (Inserer)
Supprimer une mesure
Dupliquer une mesure
Deplacer une mesure dans la partition.
Repeter une mesure n fois.

      */

    cout << "TERMINATED" << endl;
    //char c; cin >> c;
    return 0;
}
