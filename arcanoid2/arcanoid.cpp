#include "whycpp.h"
#include "Arcanoid1.h"
#include <SDL_mixer.h>
#include "SDL.h"
#include "SDL_audio.h"
#include "SDL_main.h"
int main(int argc, char* argv[]) {
	RunApp<Arcanoid1>(ApplicationConfig(224, 256, "Application", false, 2));
  return 0;
}