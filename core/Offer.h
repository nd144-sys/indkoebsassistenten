#pragma once

#include <string>

/// A price for one product in one store. This is how comparison works:
/// Product has no price; Offer does.
class Offer {
public:
    Offer(std::string productId, std::string storeId, double price);

    const std::string& productId() const;
    const std::string& storeId() const;
    double price() const;

    void setPrice(double price);

private:
    std::string productId_;
    std::string storeId_;
    double price_{0.0};
};
