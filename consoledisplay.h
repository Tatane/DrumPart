#ifndef CONSOLEDISPLAY_H
#define CONSOLEDISPLAY_H

#include "partition.h"
#include "measure.h"

class ConsoleDisplay
{
public:
    ConsoleDisplay();
    void displayMeasure(const Measure & measure) const;
};

#endif // CONSOLEDISPLAY_H
