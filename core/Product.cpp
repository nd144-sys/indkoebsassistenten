#include "Product.h"
#include <string>

Product::Product(std::string id, std::string name, std::string category)
    : id_(id), name_(name), category_(category) {}

const std::string& Product::id() const {
    return id_;
}

const std::string& Product::name() const {
    return name_;
}

const std::string& Product::category() const {
    return name_;
}

void Product::setName(std::string name) {
    name_ = name;
}

void Product::setCategory(std::string category) {
    category_ = category;
}