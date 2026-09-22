#include <iostream>
#include <cassert>
#include <vector>
#include "SelectedStorePricer.h"
#include "ShoppingList.h"
#include "Offer.h"

int main() {
    try {
        // 1. Opret data
        ShoppingList list("L1", "Test List");
        list.addItem(ShoppingListItem("milk", 2.0)); 
        list.addItem(ShoppingListItem("bread", 1.0)); 

        std::vector<Offer> offers;
        offers.push_back(Offer("milk", "Netto", 12.50)); 
        offers.push_back(Offer("bread", "Netto", 20.00)); 

        // 2. Kør pricer
        SelectedStorePricer pricer;
        double actualTotal = pricer.total(list, "Netto", offers);

        // 3. Tjek resultatet
        assert(actualTotal == 45.00);

        std::cout << "SUCCESS: SelectedStorePricer calculates correctly: " << actualTotal << " DKK\n";
    } 
    catch (const std::exception& e) {
        std::cerr << "ERROR: Test failed with exception: " << e.what() << "\n";
    }
    return 0;
}
