#include "Product.h"
#include <string>

Product::Product(std::string id, std::string name, std::string category)
    : id_(std::move(id)), name_(std::move(name)), category_(std::move(category)) {}

const std::string& Product::id() const {
    return id_;
}

const std::string& Product::name() const {
    return name_;
}

const std::string& Product::category() const {
    return category_;
}

void Product::setName(std::string name) {
    name_ = std::move(name);
}

void Product::setCategory(std::string category) {
    category_ = std::move(category);
}