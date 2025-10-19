#include "shoppingcart.h"
#include <iostream>

void ShoppingCart::addProduct(Product* p, int qty) {
    if (!p || qty <= 0) return;
    // if same product exists, increase qty
    for (auto &it : items) {
        if (it.first == p) {
            it.second += qty;
            return;
        }
    }
    items.push_back({p, qty});
}

void ShoppingCart::removeProduct(size_t index) {
    if (index < items.size()) items.erase(items.begin() + index);
}

void ShoppingCart::updateQuantity(size_t index, int qty) {
    if (index < items.size() && qty > 0) items[index].second = qty;
}

double ShoppingCart::getTotal() const {
    double total = 0.0;
    for (const auto &it : items) total += it.first->getPrice() * it.second;
    return total;
}

void ShoppingCart::viewCart() const {
    if (items.empty()) {
        std::cout << "Cart is empty.\n";
        return;
    }
    std::cout << "Cart contents:\n";
    for (size_t i = 0; i < items.size(); ++i) {
        const auto &it = items[i];
        std::cout << i+1 << ") " << it.first->getName()
                  << " x" << it.second
                  << " @$" << it.first->getPrice()
                  << " each (stock: " << it.first->getStock() << ")\n";
    }
    std::cout << "Cart total (no discount): $" << getTotal() << "\n";
}

const std::vector<std::pair<Product*, int>>& ShoppingCart::getItems() const {
    return items;
}

void ShoppingCart::clearCart() { items.clear(); }

bool ShoppingCart::empty() const { return items.empty(); }
