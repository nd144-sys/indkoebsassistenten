#pragma once

#include "IEngine.h"
#include <vector>

/// Concrete engine. 
class AppEngine final : public IEngine {
public:
    AppEngine() = default;
    ~AppEngine() override = default;

    void initialize() override;
    void shutdown() override;
    std::string status() const override;

    void addProduct(Product product) override;
    void addStore(Store store) override;
    void addOffer(Offer offer) override;

    const std::vector<Product>& products() const override;
    const std::vector<Store>& stores() const override;
    const std::vector<Offer>& offers() const override;

private:
    bool initialized_{false};
    
    std::vector<Product> products_;
    std::vector<Store> stores_;
    std::vector<Offer> offers_;

};
