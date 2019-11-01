#ifndef PARTITION_H
#define PARTITION_H

#include <vector>
#include <measure.h>

using namespace std;

class Partition
{
public:
    Partition();
    void addMeasure(Measure* m);
    void play();

    int getTempo() const {return tempo; }

private:
    vector<Measure*> measures;
    int tempo = 60;
};

#endif // PARTITION_H
