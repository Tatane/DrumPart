#include "partition.h"

Partition::Partition()
{
    //measures.reserve(10);
}
/*
void Partition::addMeasure(Measure *m)
{
    measures.push_back(m);
}
*/
void Partition::play()
{
    for(auto & measure : measures)
    {
        measure->play();
    }
}

Measure & Partition::insertMeasure(int position, unique_ptr<Measure> measure /* = nullptr */)
{
    MeasuresContainer::const_iterator it = measures.cbegin();
    if (position >= static_cast<int>(measures.size()))
    {
        it = measures.cend();
    }
    else
    {
        for(int i=0; i<position; ++i)
        {
            ++it;
        }
    }

    if ( ! measure )
    {
        measure = std::make_unique<Measure>(*this);
    }

    MeasuresContainer::iterator newIt = measures.insert(it, std::move(measure));

    return *(newIt->get());
}
