# IT320-7
This project is a C++ console-based online shopping system designed to demonstrate fundamental concepts in object-oriented programming (OOP), multithreading, and concurrency control. The program models a simplified version of an online shopping experience where users can browse available products, add items to their shopping carts, and complete a simulated checkout process.

The system also uses multithreading to simulate multiple users interacting with the store at the same time. This feature mimics real-world scenarios where several customers might be shopping concurrently on the same website. Thread synchronization is achieved through the use of mutex locks to ensure that shared resources, such as product quantities, remain consistent even when accessed by multiple threads simultaneously.

The project was created to fulfill a final course requirement and serves as a practical application of C++ programming principles, including encapsulation, inheritance, and data protection. It highlights the connection between theoretical concepts and their real-world use in software engineering, particularly in e-commerce applications.
When executed, the program:

Initializes a set of products (such as apples, bread, etc.).

Creates multiple user objects, including Regular, Premium, and VIP users.

Launches threads that simulate users adding products to their carts at the same time.

Displays the contents of each shopping cart.

Prompts the user to confirm checkout and applies any discount based on the user’s type.
product.h / product.cpp	Defines the Product class. Each product includes attributes such as name, description, price, and stock quantity. The file also provides methods to view, modify, and access these details. These files form the foundation of the product catalog.
shoppingcart.h / shoppingcart.cpp	Contains the ShoppingCart class, which manages a list of products that a user has selected. It allows adding, viewing, and clearing products, and provides a function to calculate the total price of all items. This class serves as the connection between users and products.
user.h / user.cpp	Defines the User base class and derived classes such as PremiumUser and VIPUser. Each user has personal information (name, email, address) and a ShoppingCart object. The subclasses implement specific privileges like discounts. This demonstrates inheritance and polymorphism.
main.cpp	The core driver of the program. It creates the products and user objects, manages threads to simulate multiple shoppers, controls checkout logic, and handles user input. This file brings all other components together into one functioning system.
Object-Oriented Design

The program was built using OOP principles to ensure modularity and clarity. By separating functionality into classes (Product, ShoppingCart, and User), each component can be modified or extended without affecting the others. For example, adding a new product type or user role would require minimal code changes. This modularity reflects how real-world systems are structured for scalability.

2. Inheritance for User Roles

Inheritance was used to represent different user types — Regular, Premium, and VIP — each with distinct discount levels. This approach avoids repetitive code and illustrates polymorphism, where derived classes can override or extend the functionality of their base class. It also mirrors real-world e-commerce tiers like loyalty programs.

3. Encapsulation and Data Safety

All class attributes (such as price and stock) were declared private or protected to prevent direct external access. Public getter and setter functions control how data is modified, maintaining integrity and preventing errors. This design ensures the system behaves predictably, even under concurrent access.

4. Multithreading with Mutex Locks

A key feature of this project is the use of multithreading to simulate multiple users shopping simultaneously. Threads represent concurrent user sessions, and a std::mutex ensures that shared data (like product stock) remains accurate. Without locks, two users might “buy” the same product at once, resulting in inconsistent data. Using mutexes demonstrates a core concept of concurrent programming: thread safety.

5. Console-Based Interface for Simplicity

The system runs entirely in the console for simplicity and clarity. This design keeps the focus on logic, not graphical elements. While a graphical interface could enhance realism, the text-based design makes it easier to demonstrate functionality within a short final project timeline.

Updates stock quantities and outputs a final purchase summary.Clone or download this repository.

Open your terminal or command prompt in the project folder.

Compile and run using:

g++ *.cpp -o shop
./shop
The accompanying video shows the full workflow, including:

Product creation and cart management

Simultaneous users shopping with threads

Checkout process with discounts

Thread-safe operations using mutex locks
This project demonstrates how C++ object-oriented design and multithreading can work together to build realistic applications. It emphasizes structured programming, secure data handling, and concurrent process management — all essential skills for professional software development. While simple in appearance, the project provides a strong foundation for understanding how modern e-commerce platforms function internally.

Follow the on-screen instructions to add products, view carts, and complete purchases.

This provides a straightforward yet complete example of how an online shopping system might work at a basic level.
