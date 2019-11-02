#include "note.h"

#include <algorithm>

NotePlayer Note::notePlayer;

Note::Note(DrumNotes drumNote, short placement)
    : drumNote(drumNote)
    , placement(placement)
{

}

void Note::play()
{
    notePlayer.play(drumNote);
}

void Note::setPlacement(short value)
{
    placement = std::min(short(NB_MAX_SUBDIVISION_PER_MEASURE-1), std::max(short(0), value));
}

double Note::convertPlacementToTime(double measureDuration) const
{
    return measureDuration * placement / NB_MAX_SUBDIVISION_PER_MEASURE;
}
