#include "music.h"
#include "SDL_mixer.h"
#include <iostream>
void Music::RegistMusic( const string& name, const string& path)
{
    musics_names[name] = path;
}

void Music::RegistSound(const string& name, const string &path)
{
    sounds_names[name] = path;
}

Mix_Music* Music::GetMusic(const string &name)
{
    if (musics_names.count(name) == 0) {
        cout << "There is no music" << endl;
        return nullptr;
    }
    auto path = musics_names.at(name);
    if (musics.count(path) == 0) {
        auto music = Mix_LoadMUS(path.c_str());
        if (music == nullptr) {
            cout << "Can't read music" << endl;
            return nullptr;
        }
        musics[path] = music;
        return music;
    }
    else {
        return musics.at(path);
    }
}

Mix_Chunk* Music::GetSound(const string& name)
{
    if (sounds_names.count(name) == 0) {
        cout << "There is no sound" << endl;
        return nullptr;
    }
    auto path = sounds_names.at(name);
    if (sounds.count(path) == 0) {
        auto sound = Mix_LoadWAV(path.c_str());
        if (sound == nullptr) {
            cout << "Can't read sound" << endl;
            return nullptr;
        }
        sounds[path] = sound;
        return sound;
    }
    else {
        return sounds.at(path);
    }
}
Music::~Music() {
    for (const auto sd : sounds) {
        Mix_FreeChunk(sd.second);
    }
    for (const auto& mus : musics) {
        Mix_FreeMusic(mus.second);
    }
}
