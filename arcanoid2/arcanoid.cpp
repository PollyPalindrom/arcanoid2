#include"animation.h"
#include "application_listener.h"
#include "buttons.h"
#include "color.h"
#include "drawing.h"
#include "import_sprites.h"
#include "input.h"
#include "lifecycle.h"
#include "log.h"
#include "palette.h"
#include "sound.h"
#include "text.h"
#include"time.h"
#include "whycpp.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>
#include "Arcanoid1.h"
#include <SDL_mixer.h>
#include "SDL.h"
#include "SDL_audio.h"
#include "SDL_main.h"
int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_AUDIO) != 0) {
		std::cout << "Error" << std::endl;
	}
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)) {
		std::cout << "Error" << std::endl;
	}
	auto music = Mix_LoadMUS("D:\\kpiuap\\grazhdanskaya-oborona-tarasyuk-remiks--po-planu-vse-chiki-pu (online-audio-converter.com).WAV");
	if (music == nullptr) {
		std::cout << "Error" << std::endl;
	}
	Mix_PlayMusic(music, -1);
	while (Mix_PlayingMusic());
	Mix_FreeMusic(music);
	Mix_CloseAudio();
	//RunApp<Arcanoid1>(ApplicationConfig(224, 256, "Application", false, 2));
  return 0;
}