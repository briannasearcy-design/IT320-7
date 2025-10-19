#include "product.h"

Product::Product(const std::string& n, const std::string& d, double p, int s)
: name(n), description(d), price(p), stock(s) {}

std::string Product::getName() const { return name; }
std::string Product::getDescription() const { return description; }
double Product::getPrice() const { return price; }
int Product::getStock() const { return stock; }
void Product::setStock(int s) { stock = s; }

bool Product::reduceStock(int amount) {
    if (amount <= 0) return false;
    if (stock < amount) return false;
    stock -= amount;
    return true;
}
