#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <string>
#include "product.h"
#include "shoppingcart.h"
#include "user.h"

using namespace std;

mutex catalogMutex;

// Attempt to perform checkout for a user (thread-safe)
bool attemptCheckout(User &user) {
    lock_guard<mutex> lock(catalogMutex);

    if (user.cart.empty()) {
        cout << user.getName() << "'s cart is empty. Nothing to checkout.\n";
        return false;
    }

    // Check stock for all items first
    for (const auto &it : user.cart.getItems()) {
        Product* p = it.first;
        int qty = it.second;
        if (p->getStock() < qty) {
            cout << "Checkout failed for " << user.getName()
                 << ": not enough stock for " << p->getName() << ".\n";
            return false;
        }
    }

    // All available -> reduce stock
    for (const auto &it : user.cart.getItems()) {
        Product* p = it.first;
        int qty = it.second;
        bool ok = p->reduceStock(qty);
        (void)ok; // we already checked, so it should succeed
    }

    double total = user.cart.getTotal();
    double discount = user.getDiscount();
    double finalTotal = total - (total * discount);

    cout << "\n=== Order for " << user.getName() << " ===\n";
    user.cart.viewCart();
    cout << "Subtotal: $" << total << "\n";
    cout << "Discount: " << (discount * 100) << "%\n";
    cout << "Total after discount: $" << finalTotal << "\n";
    cout << "Order processed.\n\n";

    user.cart.clearCart();
    return true;
}

// Simulate a user session: add items, wait a bit, then try to checkout
void simulateUserSession(User *user, vector<Product*> wishlist, vector<int> qtys, int waitMs) {
    cout << user->getName() << " starts shopping.\n";
    for (size_t i = 0; i < wishlist.size(); ++i) {
        user->cart.addProduct(wishlist[i], qtys[i]);
        cout << user->getName() << " added " << wishlist[i]->getName()
             << " x" << qtys[i] << " to cart.\n";
        this_thread::sleep_for(chrono::milliseconds(100)); // small pause
    }
    // Wait to create concurrency overlap
    this_thread::sleep_for(chrono::milliseconds(waitMs));
    // Attempt checkout (this is where we lock and update stock)
    attemptCheckout(*user);
}

int main() {
    // Create some products
    Product apple("Apple", "Fresh red apple", 1.50, 5);
    Product bread("Bread", "Whole grain loaf", 2.50, 3);
    Product milk("Milk", "1L milk", 3.00, 2);

    // Put pointers in a vector for easy passing
    vector<Product*> catalog = { &apple, &bread, &milk };

    // Create users
    PremiumUser alice("Alice", "alice@example.com", "NY");
    VIPUser bob("Bob", "bob@example.com", "CA");
    RegularUser carol("Carol", "carol@example.com", "TX");

    // Simulate what each user wants (product pointers & quantities)
    vector<Product*> aliceWishlist = { &apple, &bread };
    vector<int> aliceQtys = { 2, 1 };

    vector<Product*> bobWishlist = { &bread, &milk };
    vector<int> bobQtys = { 2, 1 };

    vector<Product*> carolWishlist = { &apple, &milk };
    vector<int> carolQtys = { 3, 1 };

    // Start threads simulating users shopping concurrently
    thread t1(simulateUserSession, &alice, aliceWishlist, aliceQtys, 300);
    thread t2(simulateUserSession, &bob, bobWishlist, bobQtys, 200);
    thread t3(simulateUserSession, &carol, carolWishlist, carolQtys, 100);

    // join threads
    t1.join();
    t2.join();
    t3.join();

    // After threads finish, show remaining stock
    cout << "\n=== Remaining stock in catalog ===\n";
    for (auto p : catalog) {
        cout << p->getName() << ": " << p->getStock() << " left\n";
    }

    // Simple interactive checkout (optional manual)
    cout << "\nType 'exit' to end program, or press enter to finish: ";
    string tmp;
    getline(cin, tmp);
    return 0;
}
