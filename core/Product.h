#pragma once

#include <string>

/// Catalog item. Identity lives here; store-specific prices do not.
class Product {
public:
    Product(std::string id, std::string name, std::string category);

    const std::string& id() const;
    const std::string& name() const;
    const std::string& category() const;

    void setName(std::string name);
    void setCategory(std::string category);

private:
    std::string id_;
    std::string name_;
    std::string category_;
};
