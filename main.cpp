#include <iostream>

#include "soundmixer.h"
#include "measure.h"
#include "partition.h"

#include "noteplayer.h"

using namespace std;

int main()
{
    Partition partition;

    // Partition::insertMeasure returns a ref to a new created Measure if the caller didn't pass an existing Measure.
    unique_ptr<Measure> & newMeas1 = partition.insertMeasure(0);

    // REMARK :
    // The Measure::addNote function has a signature that forces us to pass a rvalue-reference parameter.
    // So we can either move an already existing object (though it will have been nullified on function return), ...
    // unique_ptr<Note> note1 = make_unique<Note>(DrumNotes::Bass, 0);
    // measure.addNote(std::move(note1));
    newMeas1->addNote(make_unique<Note>(DrumNotes::Bass, 0));
    newMeas1->addNote(make_unique<Note>(DrumNotes::Snare, 4));
    newMeas1->addNote(make_unique<Note>(DrumNotes::Bass, 8));
    newMeas1->addNote(make_unique<Note>(DrumNotes::Snare, 12));

    // REAMRK : as do Measure::addNote, Partition::insertMeasure takes a unique_ptr as parameter, thus the caller has to std::move an existing unique_ptr, or pass a temporary one.
    // Below, we create new Measures by copying an existing one.
    unique_ptr<Measure> meas2(new Measure(*newMeas1));
    partition.insertMeasure(1, std::move(meas2));
    partition.insertMeasure(2, unique_ptr<Measure>(new Measure(*newMeas1)));


    partition.play();


    /*  TODO :

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
