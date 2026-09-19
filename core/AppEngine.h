#pragma once

#include "IEngine.h"

/// Concrete engine. Analogous to `class AppEngine implements IEngine`.
class AppEngine final : public IEngine {
public:
    AppEngine() = default;
    ~AppEngine() override = default;

    void initialize() override;
    void shutdown() override;
    std::string status() const override;

private:
    bool initialized_{false};
};
