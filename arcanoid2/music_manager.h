#pragma once
#include <memory>
#include <string>
#include "SDL_mixer.h"
#include "music.h"
class MusicManager {
	std::unique_ptr<Music> music;
public:
	MusicManager();
	~MusicManager();
	Music* GetAssets()const {
		return music.get();
	}
	void PlayMusic(const std::string& name, int loops=-1);
	void PlaySound(const std::string& name, int loops=0, int channels=-1);
	bool IsPLaying();
};