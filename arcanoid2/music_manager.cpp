#include "music_manager.h"
#include <iostream>
#include "SDL_mixer.h"
#include <SDL.h>
#include <map>
#include <string>
#include <memory>
#include "error.h"
void MusicManager::PlayMusic(const std::string& name, int loops)
{
	auto mus = music->GetMusic(name);
	if (mus == nullptr) return;
	try {
		if (Mix_PlayMusic(mus, loops) != 0) {
			throw 3;
		}
	}
	catch (int i) {
		Exception ex(i);
		ex.Print();
		return;
	}
}

void MusicManager::PlaySound( const std::string& name, int loops, int channel)
{
	auto sd = music->GetSound(name);
	if (sd == nullptr) return;
	Mix_PlayChannel(channel, sd,loops);
}
bool MusicManager::IsPLaying()
{
	return Mix_PlayingMusic();
}
MusicManager::MusicManager() :music(std::make_unique<Music>()) {
	try {
		if (SDL_Init(SDL_INIT_AUDIO) != 0) {
			throw 4;
		}
	}
	catch (int i) {
		Exception ex(i);
		ex.Print();
		return;
	}
	try {
		if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)) {
			throw 4;
		}
	}
	catch (int i) {
		Exception ex(i);
		ex.Print();
		return;
	}
}
MusicManager::~MusicManager() {
	music.release();
	Mix_CloseAudio();
}