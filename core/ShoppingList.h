#pragma once

#include <string>
#include <vector>

/// One row on a list: which product, how many, and whether it is checked off.
/// Holds a product id, not a Product object — the catalog and the list stay decoupled.
class ShoppingListItem {
public:
    ShoppingListItem(std::string productId, double quantity);

    const std::string& productId() const;
    double quantity() const;
    bool checked() const;

    void setQuantity(double quantity);
    void setChecked(bool checked);

private:
    std::string productId_;
    double quantity_{1.0};
    bool checked_{false};
};

/// Named collection of list items. Owns its items by value (no pointers).
class ShoppingList {
public:
    ShoppingList(std::string id, std::string name);

    const std::string& id() const;
    const std::string& name() const;
    const std::vector<ShoppingListItem>& items() const;

    void setName(std::string name);

    void addItem(ShoppingListItem item);
    bool removeItem(const std::string& productId);
    bool setChecked(const std::string& productId, bool checked);

    std::size_t itemCount() const;

private:
    std::string id_;
    std::string name_;
    std::vector<ShoppingListItem> items_;
};
