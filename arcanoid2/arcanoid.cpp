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
#include "platform.h" 
#include "brick.h"
#include "rectangle.h"
#include "ball.h"
#include "arcanoid1.h"
int main() {
  RunApp<Arcanoid>(ApplicationConfig(256, 144, "Arcanoid", false));
  return 0;
}