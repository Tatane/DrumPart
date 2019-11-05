#ifndef PARTITION_H
#define PARTITION_H

#include <list>
#include <memory>

#include "measure.h"

using namespace std;


class Partition
{
public:
    using MeasuresContainer = list<unique_ptr<Measure>>;

    Partition();

    void play();
    int getTempo() const {return tempo; }

    Measure & insertMeasure(int position, unique_ptr<Measure> measure = nullptr);
    const MeasuresContainer & getMeasures() const;

private:
    MeasuresContainer measures;

    int tempo = 100;
};

#endif // PARTITION_H
