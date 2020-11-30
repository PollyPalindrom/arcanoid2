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
class Arcanoid : public ApplicationListener {
    Platform* platform=nullptr;
    Ball* ball = nullptr;
    std::vector<Ball*> balls;
    std::vector<Brick*> bricks;
    bool pause = true;
    RGBA* color = nullptr;
 public:
     void OnCreate(Context& ctx) override;
     void OnRender(Context& ctx) override;
     void HandlePause(Context& ctx);
     void Win();
     void Lose();
};