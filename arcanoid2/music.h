#pragma once
#include <map>
#include <string>
#include <SDL_mixer.h>
using namespace std;
class Music
{
public:
	map<string, Mix_Music*> musics;
	map<string, Mix_Chunk*> sounds;
	map<string, string> musics_names;
	map<string, string> sounds_names;
	void RegistMusic(const string& name, const string &path);
	void RegistSound(const string &name, const string &path);
	Mix_Music* GetMusic(const string &name);
	Mix_Chunk* GetSound(const string &name);
	~Music();
};

