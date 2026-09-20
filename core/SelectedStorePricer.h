#pragma once

#include "IListPricer.h"

/// Sums quantity * offer.price for the given storeId.
class SelectedStorePricer final : public IListPricer {
public:
    SelectedStorePricer() = default;

    double total(const ShoppingList& list,
                 const std::string& storeId,
                 const std::vector<Offer>& offers) const override;
};
