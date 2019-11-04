#ifndef PARTITION_H
#define PARTITION_H

#include <list>
#include <memory>

#include "measure.h"

using namespace std;

class Partition
{
public:
    Partition();
    Partition(const Partition&)
    {

    }

    void play();
    int getTempo() const {return tempo; }

    //void addMeasure(Measure* m);

    // insertMeasure() accepts only a rvalue reference of a Measure, so that the caller can't keep the ownership.

    Measure & insertMeasure(int position, unique_ptr<Measure> measure = nullptr);

    Note & getNote(const Measure &, int place) const;


private:
    using MeasuresContainer = list<unique_ptr<Measure>>;
    MeasuresContainer measures;
    int tempo = 100;
};

#endif // PARTITION_H
