#pragma once

#include "Offer.h"
#include "ShoppingList.h"

#include <string>
#include <vector>

/// Computes a shopping-list total. How prices are chosen is up to the implementation.
class IListPricer {
public:
    virtual ~IListPricer() = default;

    virtual double total(const ShoppingList& list,
                         const std::string& storeId,
                         const std::vector<Offer>& offers) const = 0;

protected:
    IListPricer() = default;

    IListPricer(const IListPricer&) = default;
    IListPricer& operator=(const IListPricer&) = default;
};
