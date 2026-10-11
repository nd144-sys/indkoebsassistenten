#include "PriceOptimizer.h"
#include "ShoppingList.h"
#include "SelectedStorePricer.h"
#include <limits>
#include <string>

std::vector<BestOfferResult> PriceOptimizer::findCheapestItems(
    const ShoppingList& list, 
    const std::vector<Offer>& offers) 
{
    std::vector<BestOfferResult> results;

    // Iterate through the list of items
    for (auto i = list.items().begin(); i != list.items().end(); ++i) {
        
        double lowestPriceSoFar = std::numeric_limits<double>::max();
        std::string lowestPriceStoreId = "none";

        // Iterate through each offer in 'offers'
        for (auto offer = offers.begin(); offer != offers.end(); ++offer) {
            // Check that the offer ID matches the item ID, and the offer price is the lowest so far.
            if(offer->productId() == i->productId() && offer->price() < lowestPriceSoFar) {
                // Update the lowest price so far
                lowestPriceSoFar = offer->price();
                lowestPriceStoreId = offer->storeId();
            }
        }
        // Check that a valid offer was found and create a BestOfferResult struct
        if(lowestPriceSoFar != std::numeric_limits<double>::max()){
            BestOfferResult bestOfferResult;
            bestOfferResult.productId = i->productId();
            bestOfferResult.storeId = lowestPriceStoreId;
            bestOfferResult.price = lowestPriceSoFar;
            bestOfferResult.lineTotal = bestOfferResult.price * i->quantity(); // price * amount of items

            // Push the BestOfferResult onto results vector
            results.push_back(std::move(bestOfferResult));
        }
        

    }
    return results;
}

std::string PriceOptimizer::findCheapestStore(
    const ShoppingList &list, 
    const std::vector<std::string> &storeIds, 
    const std::vector<Offer> &offers) 
{
    SelectedStorePricer pricer;

    double lowestBasketTotalSoFar = std::numeric_limits<double>::max();
    std::string lowestTotalStoreId = "none";

    // Iterate through each store id in 'storeIds'
    for (const auto& id : storeIds) {
        // Calculate the total shopping list price of the store
        double storeTotal = pricer.total(list, id, offers);

        // Check if the total is the lowest so far
        if(storeTotal > 0.0 && storeTotal < lowestBasketTotalSoFar) {
            lowestBasketTotalSoFar = storeTotal;
            lowestTotalStoreId = id;
        }
    }
    return lowestTotalStoreId;
}
