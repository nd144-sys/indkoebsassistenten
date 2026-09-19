#include "ShoppingList.h"
#include <vector>

ShoppingListItem::ShoppingListItem(std::string productId, double quantity)
    : productId_(productId), quantity_(quantity) {}

const std::string& ShoppingListItem::productId() const {
    return productId_;
}

double ShoppingListItem::quantity() const {
    return quantity_;
}

bool ShoppingListItem::checked() const {
    return checked_;
}

void ShoppingListItem::setQuantity(double quantity) {
    if(quantity > 0) {
        quantity_ = quantity;   
    }
} 

void ShoppingListItem::setChecked(bool checked) {
    checked_ = checked;
}



ShoppingList::ShoppingList(std::string id, std::string name)
    : id_(std::move(id)), name_(name) {}

const std::string& ShoppingList::id() const {
    return id_;
}

const std::string& ShoppingList::name() const {
    return name_;
}

const std::vector<ShoppingListItem>& ShoppingList::items() const {
    return items_;
}

void ShoppingList::setName(std::string name) {
    name_ = name;
}

void ShoppingList::addItem(ShoppingListItem item) {
    items_.push_back(std::move(item));
}

bool ShoppingList::removeItem(const std::string& productId) {
    /// If the list of shopping items is nonempty, remove item and return true
    if(!items_.empty()) {
        for (auto it = items_.begin(); it != items_.end(); ++it) {
            if(it->productId() == productId){
                items_.erase(it);
                return true;
            }
        }
    }
    /// else return false
    return false;
}

bool ShoppingList::setChecked(const std::string& productId, bool checked) {
    /// If the list of shopping items is nonempty, call setChecked for the ShoppingListItem and return true
    if(!items_.empty()) {
        for (auto it = items_.begin(); it != items_.end(); ++it) {
            if(it->productId() == productId){
                it->setChecked(checked);
                return true;
            }
        }
    }
    /// else return false
    return false;
}

std::size_t ShoppingList::itemCount() const {
    return items_.size();
}