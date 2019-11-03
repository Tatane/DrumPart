#ifndef PARTITION_H
#define PARTITION_H

#include <list>
#include <measure.h>
#include <memory>

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

    unique_ptr<Measure> & insertMeasure(int position, unique_ptr<Measure> measure = nullptr);


private:
    using MeasuresContainer = list<unique_ptr<Measure>>;
    MeasuresContainer measures;
    int tempo = 100;
};

#endif // PARTITION_H
