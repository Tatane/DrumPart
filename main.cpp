#include <iostream>

#include "soundmixer.h"
#include "measure.h"
#include "partition.h"

#include "noteplayer.h"

using namespace std;

int main()
{
    Partition partition;
    Measure measure1;
    partition.addMeasure(&measure1);
    partition.play();

    cout << "Hello World!" << endl;
    char c; cin >> c;
    return 0;
}
