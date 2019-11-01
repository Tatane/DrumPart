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

private:
    vector<Measure*> measures;
};

#endif // PARTITION_H
