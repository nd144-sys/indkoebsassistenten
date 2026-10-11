
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

// Add methods
void AppEngine::addProduct(Product product) {
    products_.push_back(std::move(product));
}

void AppEngine::addStore(Store store) {
    stores_.push_back(std::move(store));
}

void AppEngine::addOffer(Offer offer) {
    offers_.push_back(std::move(offer));
}

// Get methods
const std::vector<Product>& AppEngine::products() const {
    return products_;
}

const std::vector<Store>& AppEngine::stores() const {
    return stores_;
}

const std::vector<Offer>& AppEngine::offers() const {
    return offers_;
}
