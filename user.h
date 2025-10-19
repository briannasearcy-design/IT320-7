#ifndef USER_H
#define USER_H

#include "shoppingcart.h"
#include <string>

class User {
protected:
    std::string name;
    std::string email;
    std::string address;
    double discount; // 0.0 - 1.0

public:
    ShoppingCart cart;
    User(const std::string& n="", const std::string& e="", const std::string& a="", double d=0.0);
    virtual ~User() = default;
    std::string getName() const;
    double getDiscount() const;
};

class RegularUser : public User {
public:
    RegularUser(const std::string& n, const std::string& e, const std::string& a)
    : User(n,e,a,0.0) {}
};

class PremiumUser : public User {
public:
    PremiumUser(const std::string& n, const std::string& e, const std::string& a)
    : User(n,e,a,0.10) {}
};

class VIPUser : public User {
public:
    VIPUser(const std::string& n, const std::string& e, const std::string& a)
    : User(n,e,a,0.20) {}
};

#endif
