#include "Offer.h"
#include <stdexcept>


Offer::Offer(std::string productId, std::string storeId, double price)
    : productId_(std::move(productId)), storeId_(std::move(storeId)), price_(price) {
        if(price_ < 0) {
            throw std::invalid_argument("Price can not be a negative number");
        }
    }

const std::string& Offer::productId() const {
    return productId_;
}

const std::string& Offer::storeId() const {
    return storeId_;
}

double Offer::price() const {
    return price_;
}

void Offer::setPrice(double price) {
    if(price < 0) {
        throw std::invalid_argument("Price can not be a negative number");
    }

    price_ = price;
}