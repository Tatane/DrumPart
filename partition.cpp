#include "partition.h"

Partition::Partition()
{
}

void Partition::addMeasure(Measure *m)
{
    measures.push_back(m);
}

void Partition::play()
{
    for(auto measure : measures)
    {
        measure->play();
    }
}
