#include <iostream>

#include "soundmixer.h"

using namespace std;

int main()
{
    SoundMixer soundMixer;
    int index = soundMixer.loadWav("/home/monom/Music/piano2.wav");

    if (index>=0)
    {
        soundMixer.play(index);
    }

    cout << "Hello World!" << endl;
    char c; cin >> c;
    return 0;
}
