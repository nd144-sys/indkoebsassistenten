#pragma once

#include "ShoppingList.h"
#include "Offer.h"
#include <vector>
#include <string>

/// A structure which keeps the cheapest price for a given item
struct BestOfferResult {
    std::string productId;
    std::string storeId;
    double price;
    double lineTotal; // Price times amount
};

class PriceOptimizer {
public:
    // Cherry-picking: Finds the cheapest offers for every item on the list
    static std::vector<BestOfferResult> findCheapestItems(
        const ShoppingList& list, 
        const std::vector<Offer>& offers);
    
    // Finds the store id for the store with the cheapest list.
    static std::string findCheapestStore(
        const ShoppingList& list, 
        const std::vector<std::string>& storeIds, 
        const std::vector<Offer>& offers);
};