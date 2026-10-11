#include "SelectedStorePricer.h"
#include "ShoppingList.h"
#include <stdexcept>

double SelectedStorePricer::total(const ShoppingList& list, const std::string& storeId, const std::vector<Offer>& offers) const {
    // Check if the shopping list is empty. 
    if(list.itemCount() <= 0){
        throw std::invalid_argument("The shopping list is empty");
    }

    double priceSum = 0.0;
    // Iterate through the shoppinglist
    for (auto item = list.items().begin(); item != list.items().end(); ++item) {
        // For each offer in offers
        for(auto offer = offers.begin(); offer != offers.end(); ++offer) {
            // If item and offer productID's match AND storeID's match, then sum up ( price * offer )
            if(offer->productId() == item->productId() && offer->storeId() == storeId) {
                priceSum += item->quantity() * offer->price(); 
            }
        }
    }
    return priceSum;
}