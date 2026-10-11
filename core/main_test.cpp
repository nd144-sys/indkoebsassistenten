#include <iostream>
#include <cassert>
#include <memory>
#include <vector>
#include <string>

#include "IEngine.h"
#include "SelectedStorePricer.h"
#include "PriceOptimizer.h"
#include "ShoppingList.h"
#include "Store.h"
#include "Product.h"
#include "Offer.h"

int main() {
    try {
        // 1. Create and initialize the engine
        std::unique_ptr<IEngine> engine = createEngine();
        engine->initialize();

        // 2. Populate the database (Stores and Products)
        engine->addStore(Store("Netto", "Netto Risskov"));
        engine->addStore(Store("Føtex", "Føtex Trøjborg"));
        engine->addProduct(Product("milkØko", "Arla Økologisk Mælk", "Milk"));
        engine->addProduct(Product("breadLimpan", "Pågen Limpan", "Bread"));

        // 3. Populate the database (Offers)
        engine->addOffer(Offer("milkØko", "Netto", 12.5));
        engine->addOffer(Offer("milkØko", "Føtex", 10.0));
        engine->addOffer(Offer("breadLimpan", "Netto", 6.75));
        engine->addOffer(Offer("breadLimpan", "Føtex", 8.5));

        // 4. Create the Shopping List
        ShoppingList list("L1", "Test List");
        list.addItem(ShoppingListItem("milkØko", 2.0)); 
        list.addItem(ShoppingListItem("breadLimpan", 1.0)); 


        // 5. Test SelectedStorePricer
        SelectedStorePricer pricer;
        double nettoTotal = pricer.total(list, "Netto", engine->offers());
        assert(nettoTotal == 31.75);

        // 6. Test PriceOptimizer (Cherry-picking)
        PriceOptimizer optimizer;
        std::vector<BestOfferResult> bestOffers = optimizer.findCheapestItems(list, engine->offers());

        assert(bestOffers.size() == 2);

        // The milk from Føtex should be cheapest (And there should be a quantity of 2 * 10.0 kr)
        assert(bestOffers[0].productId == "milkØko");
        assert(bestOffers[0].storeId == "Føtex");
        assert(bestOffers[0].price == 10.0);
        assert(bestOffers[0].lineTotal == 20.0);

        // The bread from Netto should be cheapest
        assert(bestOffers[1].productId == "breadLimpan");
        assert(bestOffers[1].storeId == "Netto");
        assert(bestOffers[1].price == 6.75);


        // 7. Test PriceOptimizer (Cheapest overall store)
        std::vector<std::string> storeIds;
        for (const auto& store : engine->stores()) {
            storeIds.push_back(store.id());
        }
        std::string bestStore = optimizer.findCheapestStore(list, storeIds, engine->offers());

        // The items on the shopping list costs 31.75 in Netto and 28.5 in Føtex. Therefore Føtex should be the cheapest store.
        assert(bestStore == "Føtex");

        // 8. Clean up
        engine->shutdown();

        std::cout << "SUCCESS: The AppEngine successfully powered the shopping assistant!\n";
    } 
    catch (const std::exception& e) {
        std::cerr << "ERROR: Test 1 failed with exception: " << e.what() << "\n";
    }

    try {
        // 1. Create data
        ShoppingList list("L1", "Test List");
        list.addItem(ShoppingListItem("milk", 2.0)); 
        list.addItem(ShoppingListItem("bread", 1.0)); 

        std::vector<Offer> offers;
        offers.push_back(Offer("milk", "Netto", 12.50)); 
        offers.push_back(Offer("bread", "Netto", 20.00)); 

        // 2. Run prices
        SelectedStorePricer pricer;
        double actualTotal = pricer.total(list, "Netto", offers);

        // 3. Check the result
        assert(actualTotal == 45.00);

        std::cout << "SUCCESS: SelectedStorePricer calculates correctly: " << actualTotal << " DKK\n";
    } 
    catch (const std::exception& e) {
        std::cerr << "ERROR: Test 2 failed with exception: " << e.what() << "\n";
    }
    return 0;
}
