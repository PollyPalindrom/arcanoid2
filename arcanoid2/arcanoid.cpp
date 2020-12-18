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
#include "music_manager.h"
int main(int argc, char* argv[]) {
	RunApp<Arcanoid1>(ApplicationConfig(224, 256, "Application", false, 2));
  return 0;
}