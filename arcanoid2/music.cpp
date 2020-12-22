#include "music.h"
#include "SDL_mixer.h"
#include <iostream>
#include "error.h"
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
    try {
        if (musics_names.count(name) == 0) {
            throw 5;
        }
    }
    catch (int i) {
        Exception ex(i);
        ex.Print();
        return nullptr;;
    }
    auto path = musics_names.at(name);
    if (musics.count(path) == 0) {
        auto music = Mix_LoadMUS(path.c_str());
        try {
            if (music == nullptr) {
                throw 6;
            }
        }
        catch (int i) {
            Exception ex(i);
            ex.Print();
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
    try {
        if (sounds_names.count(name) == 0) {
            throw 7;
        }
    }
    catch (int i) {
        Exception ex(i);
        ex.Print();
        return nullptr;;
    }
    auto path = sounds_names.at(name);
    if (sounds.count(path) == 0) {
        auto sound = Mix_LoadWAV(path.c_str());
        try {
            if (sound == nullptr) {
                throw 8;
            }
        }
        catch (int i) {
            Exception ex(i);
            ex.Print();
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
