#include "soundmixer.h"

using namespace std;

SoundMixer::SoundMixer()
{
    if (SDL_Init( SDL_INIT_AUDIO) < 0)
    {
        cout<<"Error SDL init"<<endl;
    }

    if(Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        cout<<"Error SDL open audio"<<endl;
    }
}

SoundMixer::~SoundMixer()
{
   for(auto & c : sounds)
   {
       c.reset();
   }

    Mix_Quit();
    SDL_Quit();
}


int SoundMixer::loadWav(const char *fileFullPathName)
{
    Mix_Chunk * chunk = Mix_LoadWAV( fileFullPathName );
    if (chunk == nullptr)
    {
        cout<<"Error SDL Load WAV"<<endl;
        return -1;
    }
    else
    {
        auto sound = std::make_unique<Sound>(chunk);
        sounds.push_back(std::move(sound));

        return sounds.size()-1; // return index of new Sound
    }
}

void SoundMixer::play(int index)
{
    if (index>=0 && static_cast<unsigned int>(index) < sounds.size())
    {
        auto & sound = sounds[index];
        sound->play();
    }
}

Sound::Sound(Mix_Chunk* c)
    : chunk(c)
{

}

Sound::~Sound()
{
    Mix_FreeChunk(chunk.get());
}

void Sound::play()
{
     Mix_PlayChannel( -1, chunk.get(), 0 );
}
