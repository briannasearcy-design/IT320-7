#include "user.h"

User::User(const std::string& n, const std::string& e, const std::string& a, double d)
: name(n), email(e), address(a), discount(d) {}

std::string User::getName() const { return name; }
double User::getDiscount() const { return discount; }
