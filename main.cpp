#include <iostream>

#include "consoledisplay.h"
#include "measure.h"
#include "notedrum.h"
#include "notepiano.h"
#include "noteplayer.h"
#include "partition.h"
#include "soundmixer.h"

using namespace std;

int main()
{
    Partition partition;

    // Partition::insertMeasure returns a ref to a new created Measure, or to the existing Measure the caller passed as second argument.
    Measure & newMeas1 = partition.insertMeasure(0);

    // REMARK :
    // The Measure::addNote function has a signature that forces us to pass a rvalue-reference parameter.
    // So we can either move an already existing object (though it will have been nullified on function return), ...
    // unique_ptr<Note> note1 = make_unique<Note>(DrumNotes::Bass, 0);
    // measure.addNote(std::move(note1));
    newMeas1.addNote(make_unique<NoteDrum>(-6,  0));
    newMeas1.addNote(make_unique<NoteDrum>(-5,  1));
    newMeas1.addNote(make_unique<NoteDrum>(-4,  2));
    newMeas1.addNote(make_unique<NoteDrum>(-3,  3));
    newMeas1.addNote(make_unique<NoteDrum>(-2,  4));
    newMeas1.addNote(make_unique<NoteDrum>(-1,  5));
    newMeas1.addNote(make_unique<NoteDrum>( 0,  6));
    newMeas1.addNote(make_unique<NoteDrum>( 1,  7));
    newMeas1.addNote(make_unique<NoteDrum>( 2,  8));
    newMeas1.addNote(make_unique<NoteDrum>( 3,  9));
    newMeas1.addNote(make_unique<NoteDrum>( 4,  10));
    newMeas1.addNote(make_unique<NoteDrum>( 5,  11));
    newMeas1.addNote(make_unique<NoteDrum>( 6,  12));

    //newMeas1.addNote(make_unique<NotePiano>(0, 0));


    // REAMRK : as do Measure::addNote, Partition::insertMeasure takes a unique_ptr as parameter, thus the caller has to std::move an existing unique_ptr, or pass a temporary one.
    // Below, we create new Measures by copying an existing one.
    unique_ptr<Measure> meas2(new Measure(newMeas1));
    partition.insertMeasure(1, std::move(meas2));
    //partition.insertMeasure(2, unique_ptr<Measure>(new Measure(newMeas1)));

    //partition.play();
    ConsoleDisplay consoleDisplay;
    //consoleDisplay.displayPartition(partition);
    consoleDisplay.displayMeasure(newMeas1);

/*  TODO :

Ajouter une note a une mesure deja existante.
Modifier le Type d'une note existante.
Deplacer une note deja existante (modifier son Placement)
Deplacer une note vers une autre mesure
Supprimer une note

+Ajouter une mesure (Inserer)
Supprimer une mesure
Dupliquer une mesure
Deplacer une mesure dans la partition.
Repeter une mesure n fois.

*/

    cout << "TERMINATED" << endl;
    //char c; cin >> c;
    return 0;
}
