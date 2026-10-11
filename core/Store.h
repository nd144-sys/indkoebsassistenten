#pragma once

#include <string>

/// A physical retailer. Location and opening hours come later.
class Store {
public:
    Store(std::string id, std::string name);

    const std::string& id() const;
    const std::string& name() const;

    void setName(std::string name);

private:
    std::string id_;
    std::string name_;
};
