#include "music_manager.h"
#include <iostream>
#include "SDL_mixer.h"
#include <SDL.h>
#include <map>
#include <string>
#include <memory>
void MusicManager::PlayMusic(const std::string& name, int loops)
{
	auto mus = music->GetMusic(name);
	if (mus == nullptr) return;
	if (Mix_PlayMusic(mus, loops) != 0) {
		cout << "Can't play music" << endl;
	}
}

void MusicManager::PlaySound( const std::string& name, int loops, int channel)
{
	auto sd = music->GetSound(name);
	if (sd == nullptr) return;
	if (Mix_PlayChannel(channel, sd,loops) != 0) {
		cout << "Can't play sound" << endl;
		cout << "111" << endl;// тут что-то не так
	}
}
bool MusicManager::IsPLaying()
{
	return Mix_PlayingMusic();
}
MusicManager::MusicManager() :music(std::make_unique<Music>()) {
	if (SDL_Init(SDL_INIT_AUDIO) != 0) {
		std::cout << "Error" << std::endl;
	}
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)) {
		std::cout << "Error" << std::endl;
	}
}
MusicManager::~MusicManager() {
	music.release();
	Mix_CloseAudio();
}