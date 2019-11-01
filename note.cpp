#include "note.h"

NotePlayer Note::notePlayer;

Note::Note()
{
}

void Note::play()
{
    notePlayer.play(drumNote);
}
