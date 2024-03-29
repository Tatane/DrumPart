#ifndef SOUNDMIXER_H
#define SOUNDMIXER_H

#include <memory>
#include <vector>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

class Sound;

class SoundMixer
{
public:
    static SoundMixer * getInstance();
    ~SoundMixer();

    int loadWav(const char* fileFullPathName);
    void play(int index);

private:
    SoundMixer();
    static SoundMixer * instance;
    std::vector<std::unique_ptr<Sound>> sounds;
};

class Sound
{
public:
    Sound(Mix_Chunk *c);
    ~Sound();
    void play();

private:
    std::unique_ptr<Mix_Chunk> chunk;
};

#endif // SOUNDMIXER_H
