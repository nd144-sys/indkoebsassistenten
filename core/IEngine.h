#pragma once

#include "Product.h"
#include "Store.h"
#include "Offer.h"
#include <memory>
#include <string>
#include <vector>

/// Abstract core engine. Analogous to a Java interface.
/// C++ has no `interface` keyword; a class of pure virtual methods
/// (`= 0`) plus a virtual destructor is the equivalent contract.
class IEngine {
public:
    virtual ~IEngine() = default;

    virtual void initialize() = 0;
    virtual void shutdown() = 0;
    virtual std::string status() const = 0;

    // Database: Add entities to the engine
    virtual void addProduct(Product product) = 0;
    virtual void addStore(Store store) = 0;
    virtual void addOffer(Offer offer) = 0;

    // Database: Retrieve data (read-only references)
    virtual const std::vector<Product>& products() const = 0;
    virtual const std::vector<Store>& stores() const = 0;
    virtual const std::vector<Offer>& offers() const = 0;

    IEngine(const IEngine&) = delete;
    IEngine& operator=(const IEngine&) = delete;
    IEngine(IEngine&&) = delete;
    IEngine& operator=(IEngine&&) = delete;

protected:
    IEngine() = default;
};

/// Factory: callers own the engine through unique_ptr, never a raw pointer.
std::unique_ptr<IEngine> createEngine();
