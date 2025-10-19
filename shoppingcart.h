#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "product.h"
#include <vector>
#include <utility>

class ShoppingCart {
private:
    // vector of <Product*, quantity>
    std::vector<std::pair<Product*, int>> items;

public:
    void addProduct(Product* p, int qty = 1);
    void removeProduct(size_t index);
    void updateQuantity(size_t index, int qty);
    double getTotal() const;
    void viewCart() const;
    const std::vector<std::pair<Product*, int>>& getItems() const;
    void clearCart();
    bool empty() const;
};

#endif
