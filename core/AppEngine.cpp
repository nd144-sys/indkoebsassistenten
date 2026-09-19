#include "AppEngine.h"

void AppEngine::initialize() {
    initialized_ = true;
}

void AppEngine::shutdown() {
    initialized_ = false;
}

std::string AppEngine::status() const {
    return initialized_ ? "ready" : "idle";
}

std::unique_ptr<IEngine> createEngine() {
    return std::make_unique<AppEngine>();
}
