#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    std::string description;
    double price;
    int stock;

public:
    Product(const std::string& n="", const std::string& d="", double p=0.0, int s=0);
    std::string getName() const;
    std::string getDescription() const;
    double getPrice() const;
    int getStock() const;
    void setStock(int s);
    // reduce stock by amount (no locking here; caller must lock)
    bool reduceStock(int amount);
};

#endif
