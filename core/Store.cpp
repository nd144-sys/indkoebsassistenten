#include "Store.h"

Store::Store(std::string id, std::string name)
    : id_(std::move(id)), name_(std::move(name)) {}

const std::string& Store::id() const {
    return id_;
}

const std::string& Store::name() const {
    return name_;
}

void Store::setName(std::string name) {
    name_ = std::move(name);
}