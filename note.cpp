#include "note.h"

#include <algorithm>

Note::~Note()
{
}

Note::Note(short pitch, short placement)
    : pitch(pitch)
    , placement(placement)
{
}

void Note::play()
{
    getNotePlayer()->play(pitch);
}

void Note::setPlacement(short value)
{
    placement = std::min(short(NB_MAX_SUBDIVISION_PER_MEASURE-1), std::max(short(0), value));
}

double Note::convertPlacementToTime(double measureDuration) const
{
    return measureDuration * placement / NB_MAX_SUBDIVISION_PER_MEASURE;
}




