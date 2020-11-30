#include "time.h"
#include "context.h"
#include "fps_holder.h"
#include "time_holder.h"

double GetTime(const Context& ctx) {
  return ctx.Get<TimeHolder>()->GetTime();
}

double GetDelta(const Context& ctx) {
  return ctx.Get<TimeHolder>()->GetDelta();
}

i32 GetFPS(const Context& ctx) {
  return ctx.Get<FpsHolder>()->GetFPS();
}
