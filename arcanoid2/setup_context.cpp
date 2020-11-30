#include "setup_context.h"
#include "application_config.h"
#include "application_listener.h"
#include "context.h"
#include "audio_holder.h"
#include "fonts_holder.h"
#include "fps_holder.h"
#include "keyboard_holder.h"
#include "lifecycle_holder.h"
#include "mouse_holder.h"
#include "sprites_holder.h"
#include "time_holder.h"
#include "video_memory_holder.h"
#include "i_render_handler.h"
#include "loop_impl.h"
#include "sdl_audio_context.h"
#include "sdl_inputs_handler.h"
#include "sdl_render_context.h"

void SetupContext(Context& ctx, const ApplicationConfig& config, ApplicationListener* listener) {
  ctx.Put<AudioHolder>();
  ctx.Put<FpsHolder>(config);
  ctx.Put<TimeHolder>();
  ctx.Put<SpritesHolder>();
  ctx.Put<FontsHolder>();
  ctx.Put<KeyboardHolder>();
  ctx.Put<MouseHolder>();
  ctx.Put<LifecycleHolder>();
  auto vram = ctx.Put<VideoMemoryHolder>(config.width, config.height);

  ctx.PutAs<SDLInputsHandler, IInputsHandler>(ctx, listener);
  ctx.PutAs<SDLRenderContext, IRenderHandler>(config, vram);
  ctx.Put<SDLAudioContext>();
  ctx.PutAs<LoopImpl, ILoop>(ctx, listener, config.ms_per_frame);
}
