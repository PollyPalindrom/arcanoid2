#include "application.h"
#include "application_listener.h"
#include "log.h"
#include "context.h"
#include "i_loop.h"
#include "setup_context.h"

Application::Application(ApplicationListener* listener, const ApplicationConfig& config)
    : context(std::make_unique<Context>()), listener(std::unique_ptr<ApplicationListener>(listener)), config(config) {
  LOG_DEBUG("Application Created");
  SetupContext(*context, config, listener);
}
void Application::Run() {
  context->Get<ILoop>()->Run();  // this call is async in case of emscripten
}
Application::~Application() {
  LOG_DEBUG("Application destroyed");
}
