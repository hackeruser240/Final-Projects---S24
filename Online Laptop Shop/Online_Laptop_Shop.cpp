#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class AccountType { CUSTOMER, ADMIN };

class Review {
private:
    string username;
    string reviewText;
    int rating;

public:
    Review(string username, string reviewText, int rating) {
        this->username = username;
        this->reviewText = reviewText;
        this->rating = rating;
    }

    void displayReview() const {
        cout << "Username: " << username << endl;
        cout << "Rating: " << rating << " stars" << endl;
        cout << "Review: " << reviewText << endl;
    }
};

class User {
private:
    string username;
    string email;
    string password;
    AccountType accountType;
    vector<string> shoppingCart;
    vector<string> orderHistory;

public:
    User() {}

    User(string username, string email, string password, AccountType accountType) {
        this->username = username;
        this->email = email;
        this->password = password;
        this->accountType = accountType;
    }

    void displayInfo() {
        cout << "Username: " << username << endl;
        cout << "Email: " << email << endl;
        cout << "Account Type: " << (accountType == AccountType::CUSTOMER ? "Customer" : "Admin") << endl;
    }

    string getUsername() const {
        return username;
    }
    
    string getEmail() const {
        return email;
    }

    string getPassword() const {
        return password;
    }

    AccountType getAccountType() const {
        return accountType;
    }

    bool verifyPassword(string inputPassword) const {
        return password == inputPassword;
    }

    void setPassword(string newPassword) {
        password = newPassword;
    }

    void addToCart(const string& laptopBrand) {
        shoppingCart.push_back(laptopBrand);
        cout << "Added " << laptopBrand << " to cart." << endl;
    }

    void displayCart() const {
        cout << "Shopping Cart:" << endl;
        for (const auto& item : shoppingCart) {
            cout << item << endl;
        }
    }

    void removeItemFromCart(const string& laptopBrand) {
        for (auto it = shoppingCart.begin(); it != shoppingCart.end(); ++it) {
            if (*it == laptopBrand) {
                shoppingCart.erase(it);
                cout << "Removed " << laptopBrand << " from cart." << endl;
                return;
            }
        }
        cout << laptopBrand << " is not in the cart." << endl;
    }

    const vector<string>& getShoppingCart() const {
        return shoppingCart;
    }

    void addToOrderHistory(const string& order) {
        orderHistory.push_back(order);
    }

    const vector<string>& getOrderHistory() const {
        return orderHistory;
    }
};

class Laptop {
private:
    string brand;
    string model;
    string specifications;
    double price;
    vector<Review> reviews;

public:
    Laptop(string brand, string model, string specifications, double price) {
        this->brand = brand;
        this->model = model;
        this->specifications = specifications;
        this->price = price;
    }

    void displayInfo() const {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Specifications: " << specifications << endl;
        cout << "Price: $" << price << endl;
    }

    const string& getBrand() const {
        return brand;
    }
    
    const string& getSpecifications() const {
        return specifications;
    }

    double getPrice() const {
        return price;
    }

    void addReview(const Review& review) {
        reviews.push_back(review);
    }

    void displayReviews() const {
        cout << "Reviews for " << brand << " " << model << ":" << endl;
        for (const auto& review : reviews) {
            review.displayReview();
            cout << endl;
        }
    }
};

class LaptopCatalog {
private:
    vector<Laptop> laptops;

public:
    void addLaptop(const Laptop& laptop) {
        laptops.push_back(laptop);
    }

    void displayCatalog() const {
        cout << "Laptop Catalog" << endl;
        for (const auto& laptop : laptops) {
            laptop.displayInfo();
            cout << endl;
        }
    }
    
    void searchByBrand(const string& brand) const {
        cout << "Search Results for Brand: " << brand << endl;
        bool found = false;
        for (const auto& laptop : laptops) {
            if (laptop.getBrand() == brand) {
                laptop.displayInfo();
                cout << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No laptops found with brand " << brand << endl;
        }
    }

    void searchBySpecifications(const string& specs) const {
        cout << "Search Results for Specifications: " << specs << endl;
        bool found = false;
        for (const auto& laptop : laptops) {
            if (laptop.getSpecifications() == specs) {
                laptop.displayInfo();
                cout << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No laptops found with specifications " << specs << endl;
        }
    }

    void searchByPriceRange(double minPrice, double maxPrice) const {
        cout << "Search Results for Price Range: $" << minPrice << " - $" << maxPrice << endl;
        bool found = false;
        for (const auto& laptop : laptops) {
            if (laptop.getPrice() >= minPrice && laptop.getPrice() <= maxPrice) {
                laptop.displayInfo();
                cout << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No laptops found within the specified price range" << endl;
        }
    }

    void displayProductDetails(const string& brand) const {
        cout << "Product Details for Brand: " << brand << endl;
        bool found = false;
        for (const auto& laptop : laptops) {
            if (laptop.getBrand() == brand) {
                laptop.displayInfo();
                // Add code to display images, descriptions, and technical specifications here
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No product details found for brand " << brand << endl;
        }
    }

    void addToCart(User& user, const string& laptopBrand) {
        user.addToCart(laptopBrand);
    }

    void displayCart(User& user) const {
        user.displayCart();
    }

    void removeItemFromCart(User& user, const string& laptopBrand) {
        user.removeItemFromCart(laptopBrand);
    }

    const vector<Laptop>& getLaptops() const {
        return laptops;
    }

    void displayReviews(const string& brand) const {
        for (const auto& laptop : laptops) {
            if (laptop.getBrand() == brand) {
                laptop.displayReviews();
                return;
            }
        }
        cout << "No reviews found for brand " << brand << endl;
    }

    void addReviewToLaptop(const string& brand, const Review& review) {
        for (auto& laptop : laptops) {
            if (laptop.getBrand() == brand) {
                laptop.addReview(review);
                cout << "Review added successfully for " << brand << " " << laptop.getBrand() << "." << endl;
                return;
            }
        }
        cout << "Laptop brand " << brand << " not found." << endl;
    }
};

class Checkout {
public:
    void registeredUserCheckout(User& user, const vector<string>& shoppingCart, int paymentOption) {
        double totalPrice = calculateTotalPrice(shoppingCart);
        cout << "Total Price: $" << totalPrice << endl;
        processPayment(totalPrice, paymentOption);
        // Construct order summary
        string orderSummary = "Paid $" + to_string(totalPrice) + " via ";
        if (paymentOption == 1) {
            orderSummary += "Credit/Debit Card.";
        } else if (paymentOption == 2) {
            orderSummary += "PayPal.";
        } else if (paymentOption == 3) {
            orderSummary += "Other Online Payment Gateway.";
        }
        // Add order summary to user's order history
        user.addToOrderHistory(orderSummary);
        cout << "Checkout process completed for user " << user.getUsername() << endl;
    }

private:
    double calculateTotalPrice(const vector<string>& shoppingCart) {
        double totalPrice = 0.0;
        // Simulate price lookup based on laptop brand
        for (const auto& laptop : shoppingCart) {
            if (laptop == "Dell") {
                totalPrice += 699.99;
            } else if (laptop == "HP") {
                totalPrice += 899.99;
            } else if (laptop == "Lenovo") {
                totalPrice += 1499.99;
            }
        }
        return totalPrice;
    }

    void processPayment(double totalPrice, int paymentOption) {
        switch (paymentOption) {
            case 1:
                cout << "Paid $" << totalPrice << " via Credit/Debit Card." << endl;
                break;
            case 2:
                cout << "Paid $" << totalPrice << " via PayPal." << endl;
                break;
            case 3:
                cout << "Paid $" << totalPrice << " via Other Online Payment Gateway." << endl;
                break;
            default:
                cout << "Invalid payment option." << endl;
        }
    }
};

class UserDatabase {
private:
    vector<User> users;

public:
    void registerUser() {
        string username, email, password;
        int accountTypeChoice;

        cout << "Enter username: ";
        cin >> username;

        cout << "Enter email: ";
        cin >> email;

        cout << "Enter password: ";
        cin >> password;

        cout << "Select Account Type:\n1. Customer\n2. Admin\nEnter choice: ";
        cin >> accountTypeChoice;

        AccountType accountType = (accountTypeChoice == 1) ? AccountType::CUSTOMER : AccountType::ADMIN;

        User newUser(username, email, password, accountType);
        users.push_back(newUser);

        cout << "User registered successfully!" << endl;
    }

    User* loginUser(string username, string password) {
        for (auto& user : users) {
            if (user.getUsername() == username && user.verifyPassword(password)) {
                return &user;
            }
        }
        return nullptr; // Return nullptr if user not found or password doesn't match
    }

    void displayAdminDashboard() {
        cout << "Admin Dashboard" << endl;
        cout << "1. Manage Products\n2. Manage Orders\n3. Manage User Accounts\n4. Manage Inventory\n5. Website Settings\n6. Exit\nEnter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                // Add code for managing products
                cout << "Managing Products..." << endl;
                break;
            case 2:
                // Add code for managing orders
                cout << "Managing Orders..." << endl;
                break;
            case 3:
                // Add code for managing user accounts
                cout << "Managing User Accounts..." << endl;
                break;
            case 4:
                // Add code for managing inventory
                cout << "Managing Inventory..." << endl;
                break;
            case 5:
                // Add code for website settings
                cout << "Website Settings..." << endl;
                break;
            case 6:
                cout << "Exiting admin dashboard..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    void passwordRecovery(string userEmail) {
        for (auto& user : users) {
            if (user.getEmail() == userEmail) {
                string newPassword;
                cout << "Enter new password: ";
                cin >> newPassword;
                user.setPassword(newPassword);
                cout << "Password updated successfully!" << endl;
                return;
            }
        }
        cout << "User with this email does not exist." << endl;
    }
};

int main() {
    UserDatabase database;
    LaptopCatalog catalog;
    Checkout checkout;
    User* loggedInUser = nullptr;

    // Populate the catalog with sample laptops
    catalog.addLaptop(Laptop("Dell", "Inspiron 15", "Core i5, 8GB RAM, 512GB SSD", 699.99));
    catalog.addLaptop(Laptop("HP", "Pavilion x360", "Core i7, 16GB RAM, 1TB HDD", 899.99));
    catalog.addLaptop(Laptop("Lenovo", "ThinkPad X1 Carbon", "Core i7, 16GB RAM, 1TB SSD", 1499.99));

    int choice;
    while (true) {
        cout << "1. Register\n2. Login\n3. Password Recovery\n4. View Laptops\n5. Search Laptops\n6. Product Details\n7. Add to Cart\n8. Manage Cart\n9. Checkout\n10. View Order History\n11. Track Orders\n12. Laptop Reviews\n13. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            database.registerUser();
        } else if (choice == 2) {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            loggedInUser = database.loginUser(username, password);
            if (loggedInUser != nullptr) {
                cout << "Login successful!" << endl;
                if (loggedInUser->getAccountType() == AccountType::ADMIN) {
                    int adminChoice;
                    cout << "1. Access Admin Dashboard\n2. Logout\nEnter your choice: ";
                    cin >> adminChoice;
                    if (adminChoice == 1) {
                        database.displayAdminDashboard();
                    } else if (adminChoice == 2) {
                        cout << "Logging out..." << endl;
                        loggedInUser = nullptr; // Reset logged-in user
                    } else {
                        cout << "Invalid choice. Logging out..." << endl;
                        loggedInUser = nullptr; // Reset logged-in user
                    }
                } else {
                    loggedInUser->displayInfo();
                }
            } else {
                cout << "Invalid username or password. Please try again." << endl;
            }
        } else if (choice == 3) {
            string userEmail;
            cout << "Enter your email for password recovery: ";
            cin >> userEmail;
            database.passwordRecovery(userEmail);
        } else if (choice == 4) {
            catalog.displayCatalog();
        } else if (choice == 5) {
            int searchChoice;
            cout << "Search Laptops by:\n1. Brand\n2. Specifications\n3. Price Range\nEnter your choice: ";
            cin >> searchChoice;

            if (searchChoice == 1) {
                string brand;
                cout << "Enter brand to search for: ";
                cin >> brand;
                catalog.searchByBrand(brand);
            } else if (searchChoice == 2) {
                string specifications;
                cout << "Enter specifications to search for: ";
                cin >> specifications;
                catalog.searchBySpecifications(specifications);
            } else if (searchChoice == 3) {
                double minPrice, maxPrice;
                cout << "Enter minimum price: $";
                cin >> minPrice;
                cout << "Enter maximum price: $";
                cin >> maxPrice;
                catalog.searchByPriceRange(minPrice, maxPrice);
            } else {
                cout << "Invalid search choice." << endl;
            }
        } else if (choice == 6) {
            string brand;
            cout << "Enter brand to view details: ";
            cin >> brand;
            catalog.displayProductDetails(brand);
        } else if (choice == 7) {
            string laptopBrand;
            if (loggedInUser != nullptr) { // Check if user is logged in
                cout << "Enter laptop brand to add to cart: ";
                cin >> laptopBrand;
                catalog.addToCart(*loggedInUser, laptopBrand);
            } else {
                cout << "You need to log in to add items to the cart." << endl;
            }
        } else if (choice == 8) {
            if (loggedInUser != nullptr) { // Check if user is logged in
                int cartChoice;
                cout << "1. Display Cart\n2. Remove Item from Cart\nEnter your choice: ";
                cin >> cartChoice;
                if (cartChoice == 1) {
                    catalog.displayCart(*loggedInUser);
                } else if (cartChoice == 2) {
                    string laptopBrand;
                    cout << "Enter laptop brand to remove from cart: ";
                    cin >> laptopBrand;
                    catalog.removeItemFromCart(*loggedInUser, laptopBrand);
                } else {
                    cout << "Invalid choice." << endl;
                }
            } else {
                cout << "You need to log in to manage your cart." << endl;
            }
        } else if (choice == 9) {
            if (loggedInUser != nullptr) {
                const vector<string>& userCart = loggedInUser->getShoppingCart();
                if (!userCart.empty()) {
                    int paymentOption;
                    cout << "Select Payment Option:\n1. Credit/Debit Card\n2. PayPal\n3. Other Online Payment Gateway\nEnter your choice: ";
                    cin >> paymentOption;
                    // Convert userCart from vector<string> to vector<Laptop> before passing to checkout
                    vector<Laptop> cartAsLaptops;
                    for (const auto& brand : userCart) {
                        for (const auto& laptop : catalog.getLaptops()) {
                            if (laptop.getBrand() == brand) {
                                cartAsLaptops.push_back(laptop);
                                break;
                            }
                        }
                    }
                    checkout.registeredUserCheckout(*loggedInUser, userCart, paymentOption);
                } else {
                    cout << "Your cart is empty. Add items before checkout." << endl;
                }
            } else {
                cout << "You need to log in before checkout." << endl;
            }
        } else if (choice == 10) {
            if (loggedInUser != nullptr) {
                cout << "Order History for " << loggedInUser->getUsername() << ":" << endl;
                const vector<string>& orderHistory = loggedInUser->getOrderHistory();
                if (orderHistory.empty()) {
                    cout << "No orders found." << endl;
                } else {
                    for (const auto& order : orderHistory) {
                        cout << order << endl;
                    }
                }
            } else {
                cout << "You need to log in to view order history." << endl;
            }
        } else if (choice == 11) {
            cout << "You need to log in to track orders." << endl;
        } else if (choice == 12) {
            int reviewChoice;
            cout << "1. Add Review\n2. View Reviews\nEnter your choice: ";
            cin >> reviewChoice;

            if (reviewChoice == 1) {
                // Add review
            } else if (reviewChoice == 2) {
                string brand;
                cout << "Enter brand to view reviews: ";
                cin >> brand;
                catalog.displayReviews(brand);
            } else {
                cout << "Invalid choice." << endl;
            }
        } else if (choice == 13) {
            cout << "Exiting the program..." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}