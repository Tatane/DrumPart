#include <iostream>

#include "soundmixer.h"
#include "measure.h"
#include "partition.h"

#include "noteplayer.h"

using namespace std;

int main()
{
    shared_ptr<Partition> partition = make_shared<Partition>();
    Measure measure1(partition), measure2(partition);
    partition->addMeasure(&measure1);
    partition->addMeasure(&measure2);
    partition->play();

    cout << "Hello World!" << endl;
    char c; cin >> c;
    return 0;
}
