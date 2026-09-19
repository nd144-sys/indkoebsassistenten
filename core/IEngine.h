#pragma once

#include <memory>
#include <string>

/// Abstract core engine. Analogous to a Java interface.
/// C++ has no `interface` keyword; a class of pure virtual methods
/// (`= 0`) plus a virtual destructor is the equivalent contract.
class IEngine {
public:
    virtual ~IEngine() = default;

    virtual void initialize() = 0;
    virtual void shutdown() = 0;
    virtual std::string status() const = 0;

    IEngine(const IEngine&) = delete;
    IEngine& operator=(const IEngine&) = delete;
    IEngine(IEngine&&) = delete;
    IEngine& operator=(IEngine&&) = delete;

protected:
    IEngine() = default;
};

/// Factory: callers own the engine through unique_ptr, never a raw pointer.
std::unique_ptr<IEngine> createEngine();
