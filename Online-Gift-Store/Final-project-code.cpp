#include <iostream>
#include <string>
#include <fstream>
using namespace std;
// Define the Review class
class Review {
private:
    string text;
    int rating; // Rating on a scale of 1 to 5
public:
    // Default constructor
    Review() : text(""), rating(0) {}
    // Constructor with parameters
    Review(const string& _text, int _rating) : text(_text), rating(_rating) {}
    // Getter functions
    string getText() const { return text; }
    int getRating() const { return rating; }
};
class Product {
private:
    int id;
    string name;
    string description;
    int quantity; // Current stock quantity
    double price;
    Review reviews[100]; // Collection of reviews
    int reviewCount;
public:
    // Constructor with description parameter
    Product(int _id, string _name, string _description, int _quantity, double _price) 
        : id(_id), name(_name), description(_description), quantity(_quantity), price(_price), reviewCount(0) {}
    // Getter functions
    int getId() const { return id; }
    string getName() const { return name; }
    string getDescription() const { return description; }
    int getQuantity() const { return quantity; } // Get current stock quantity
    double getPrice() const { return price; }
    // Function to add stock
    void addStock(int quantityToAdd) {
        quantity += quantityToAdd;
        cout << "Stock added successfully. New quantity: " << quantity << endl;
    }
    // Function to update stock quantity
    void updateStock(int newQuantity) {
        quantity = newQuantity;
        cout << "Stock quantity updated successfully. New quantity: " << quantity << endl;
    }
    // Function to display current stock level
    void displayStock() const {
        cout << "Current Stock Level for " << name << ": " << quantity << endl;
    }
    // Function to add a review
    void addReview(const string& reviewText, int rating) {
        if (reviewCount < 100) {
            reviews[reviewCount++] = Review(reviewText, rating);
            cout << "Review added successfully!" << endl;
        } else {
            cout << "Maximum review limit reached." << endl;
        }
    }
    // Function to display reviews and ratings
    void displayReviews() const {
        if (reviewCount == 0) {
            cout << "No reviews available for this product." << endl;
        } else {
            cout << "Product Reviews:" << endl;
            for (int i = 0; i < reviewCount; ++i) {
                cout << "Rating: " << reviews[i].getRating() << " | Review: " << reviews[i].getText() << endl;
            }
        }
    }
};
// Define the User class
class User {
public:
    string username;
    string password;
    bool isAdmin;
    double balance;
    Product* shoppingCart[100];
    Product* orderHistory[100];
    Product* wishList[100]; // User's wish list
    string address[100]; // User's address
    string paymentMethods[100]; // User's payment methods
    string deliveryOptions[100]; // User's delivery options
    string orderTracking[100]; // User's order tracking information
    string giftCards[100]; // User's gift cards
    int cartSize = 0;
    int orderHistorySize = 0;
    int wishListSize = 0; // Size of the wish list
    int addressSize = 0;
    int paymentMethodsSize = 0;
    int deliveryOptionsSize = 0;
    int orderTrackingSize = 0;
    int giftCardsSize = 0;
    // Constructor
    User(const string& _username, const string& _password, bool _isAdmin = false, double _balance = 0.0) 
        : username(_username), password(_password), isAdmin(_isAdmin), balance(_balance) {}
    // Function to add a product to the shopping cart
    void addToCart(Product* product) {
        shoppingCart[cartSize++] = product;
        cout << "Product added to cart successfully!" << endl;
    }
      // Function to display shopping cart contents
    void displayCart() const {
        if (cartSize == 0) {
            cout << "Shopping cart is empty." << endl;
        } else {
            cout << "Shopping Cart:" << endl;
            for (int i = 0; i < cartSize; ++i) {
                cout << "Name: " << shoppingCart[i]->getName()
                     << " | Price: $" << shoppingCart[i]->getPrice() << endl;
            }
        }
    }
      // Function to add a product to the wish list
    void addToWishList(Product* product) {
        wishList[wishListSize++] = product;
        cout << "Product added to wish list successfully!" << endl;
    }
    // Function to display wish list contents
    void displayWishList() const {
        if (wishListSize == 0) {
            cout << "Wish list is empty." << endl;
        } else {
            cout << "Wish List:" << endl;
            for (int i = 0; i < wishListSize; ++i) {
                cout << "Name: " << wishList[i]->getName()
                     << " | Price: $" << wishList[i]->getPrice() << endl;
            }
        }
    }

// Function to place order
void placeOrder() {
    if (cartSize == 0) {
        cout << "Cannot place order. Shopping cart is empty." << endl;
    } else {
       
	    // Move products from shopping cart to order history
        for (int i = 0; i < cartSize; ++i) {
            orderHistory[orderHistorySize++] = shoppingCart[i];
        }
       
	    // Clear the shopping cart
        cartSize = 0;
        cout << "Order placed successfully!" << endl;
    }
}
   // Function to view order history
    void viewOrderHistory() const {
        if (orderHistorySize == 0) {
            cout << "Order history is empty." << endl;
        } else {
            cout << "Order History:" << endl;
            for (int i = 0; i < orderHistorySize; ++i) {
                // Output order details
            }
        }
    }
    // Function to edit profile information
    void editProfile() {
        int choice;
        cout << "Edit Profile:" << endl;
        cout << "1. Update Address" << endl;
        cout << "2. Add Payment Method" << endl;
        cout << "3. Add Delivery Option" << endl;
        cout << "4. Go Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string newAddress;
                cout << "Enter new address: ";
                cin.ignore(); // Ignore newline character
                getline(cin, newAddress);
                addAddress(newAddress);
                break;
            }
            case 2: {
                int paymentChoice;
                cout << "Choose payment method:" << endl;
                cout << "1. Card" << endl;
                cout << "2. Cash" << endl;
                cout << "Enter your choice: ";
                cin >> paymentChoice;
                if (paymentChoice == 1) {
                    string cardNumber;
                    cout << "Enter card number: ";
                    cin >> cardNumber;
                    addPaymentMethod("Card: " + cardNumber);
                } else if (paymentChoice == 2) {
                    addPaymentMethod("Cash");
                } else {
                    cout << "Invalid choice. Please try again." << endl;
                }
                break;
            }
            case 3: {
                string deliveryOption;
                cout << "Enter delivery option: ";
                cin.ignore(); // Ignore newline character
                getline(cin, deliveryOption);
                addDeliveryOption(deliveryOption);
                break;
            }
            case 4:
                cout << "Going back to main menu..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    // Function to add an address
    void addAddress(const string& newAddress) {
        address[addressSize++] = newAddress;
        cout << "Address added successfully!" << endl;
    }
    // Function to add a payment method
    void addPaymentMethod(const string& paymentMethod) {
        paymentMethods[paymentMethodsSize++] = paymentMethod;
        cout << "Payment method added successfully!" << endl;
    }
    // Function to add a delivery option
    void addDeliveryOption(const string& deliveryOption) {
        deliveryOptions[deliveryOptionsSize++] = deliveryOption;
        cout << "Delivery option added successfully!" << endl;
    }
    // Function to track orders
    void trackOrder(const string& orderID) {
        // Implement order tracking functionality here
        cout << "Order tracked successfully!" << endl;
    }
    // Function to add a gift card
    void addGiftCard(const string& giftCard) {
        giftCards[giftCardsSize++] = giftCard;
        cout << "Gift card added successfully!" << endl;
    }
        // Function to display order history
    void displayOrderHistory() const {
        if (orderHistorySize == 0) {
            cout << "Order history is empty." << endl;
        } else {
            cout << "Order History:" << endl;
            for (int i = 0; i < orderHistorySize; ++i) {
                cout << "Name: " << orderHistory[i]->getName()
                     << " | Price: $" << orderHistory[i]->getPrice() << endl;
            }
        }
    }
};
// Define the ProductManagementSystem class
class ProductManagementSystem {
private:
    Product* products[100];
    int productCount = 0;
public:
    // Function to add product (accessible to admin)
    void addProduct(User& user, int id, string name, string description, int quantity, double price) {
        if (user.isAdmin) {
            products[productCount++] = new Product(id, name, description, quantity, price);
            cout << "Product added successfully!" << endl;
        } else {
            cout << "Insufficient privilege to add product." << endl;
        }
    }
    // Function to display products
    void displayProducts() const {
        cout << "Product List:" << endl;
        for (int i = 0; i < productCount; ++i) {
            cout << "ID: " << products[i]->getId() << " | Name: " << products[i]->getName()
                 << " | Description: " << products[i]->getDescription()
                 << " | Quantity: " << products[i]->getQuantity() << " | Price: $" << products[i]->getPrice() << endl;
        }
    }
    // Function to search products by name
    void searchProductByName(const string& searchTerm) const {
        bool found = false;
        cout << "Search Results:" << endl;
        for (int i = 0; i < productCount; ++i) {
            if (products[i]->getName().find(searchTerm) != string::npos) {
                cout << "ID: " << products[i]->getId() << " | Name: " << products[i]->getName()
                     << " | Description: " << products[i]->getDescription()
                     << " | Quantity: " << products[i]->getQuantity() << " | Price: $" << products[i]->getPrice() << endl;
                found = true;
            }
        }
        if (!found)
            cout << "No matching products found." << endl;
    }
    // Function to filter products by price range
    void filterProductsByPrice(double minPrice, double maxPrice) const {
        bool found = false;
        cout << "Filtered Products:" << endl;
        for (int i = 0; i < productCount; ++i) {
            if (products[i]->getPrice() >= minPrice && products[i]->getPrice() <= maxPrice) {
                cout << "ID: " << products[i]->getId() << " | Name: " << products[i]->getName()
                     << " | Description: " << products[i]->getDescription()
                     << " | Quantity: " << products[i]->getQuantity() << " | Price: $" << products[i]->getPrice() << endl;
                found = true;
            }
        }
        if (!found)
            cout << "No products found in the specified price range." << endl;
    }
    // Function to get a product by its ID
    Product* getProductById(int productId) const {
        for (int i = 0; i < productCount; ++i) {
            if (products[i]->getId() == productId) {
                return products[i];
            }
        }
        return nullptr; // Product not found
    }
};
void writeToFile(const string& username, const string& password) {
    ofstream writefile(username + ".txt");
    if (writefile.is_open()) {
        writefile << password;
        writefile.close();
        cout << "User registered successfully!\n";
    } else {
        cerr << "Error writing to file.\n";
    }
}
// Function to register a new user
void registerUser() {
    string username, password, password2;
    cout << "Please enter your username: ";
    cin >> username;
    cout << "Please enter the password: ";
    cin >> password;
    cout << "Please re-enter your password: ";
    cin >> password2;
    if (password == password2) {
        writeToFile(username, password);
    } else {
        cout << "Passwords do not match. Registration failed.\n";
    }
}
// Function to login an existing user
bool loginUser() {
    string username, password;
    cout << "Please enter your username: ";
    cin >> username;
    cout << "Please enter your password: ";
    cin >> password;
    // Logic to verify username and password from stored data
    // For simplicity, we'll assume a successful login here
    return true;
}
// Function to logout
void logout() {
    // For this simple console-based application, logging out just means returning to the login/register screen
    cout << "Logged out successfully.\n";
}
int main() {
    cout << "Welcome to the Online Gift Store!" << endl;
    while (true) {
        // Ask user to register or login
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (!loginUser()) {
                    cout << "Login failed. Exiting..." << endl;
                    return 0;
                }
                // After successful registration or login, proceed to online Gift Store
                cout << "Welcome to the online Gift Store!" << endl;
                {
                    ProductManagementSystem pms;
                    // Create an admin user
                    User admin("admin", "adminpassword", true);
                    // Create a shopping cart for the user
                    User currentUser("currentuser", "currentuserpassword");
                    while (true) {
                        cout << "online Gift Store|Shop outside the box" << endl;
                        cout << "1.  Add Product" << endl;
                        cout << "2.  Display Products" << endl;
                        cout << "3.  Search Product by Name" << endl;
                        cout << "4.  Filter Products by Price Range" << endl;
                        cout << "5.  Add to Cart" << endl;
                        cout << "6.  View Shopping Cart" << endl;
                        cout << "7.  Edit Profile" << endl;
                        cout << "8.  Place Order" << endl;
                        cout << "9.  View Order History" << endl;
                        cout << "10. Track Order" << endl;
                        cout << "11. Add Gift Card" << endl;
                        cout << "12. Add Review and Rating" << endl;
                        cout << "13. Add to Wish List" << endl;
                        cout << "14. Manage Inventory" << endl; // New option for inventory management
                        cout << "15. Logout" << endl;
                        cout << "16. Exit" << endl;
                        cout << "Enter your choice: ";
                        cin >> choice;
                        switch (choice) {
                            case 1: {
                                int id, quantity;
                                string name, description;
                                double price;
                                cout << "Enter product ID: ";
                                cin >> id;
                                cout << "Enter product name: ";
                                cin >> name;
                                cout << "Enter product description: ";
                                cin.ignore(); // Ignore newline character
                                getline(cin, description); // Read entire line
                                cout << "Enter product quantity: ";
                                cin >> quantity;
                                cout << "Enter product price: ";
                                cin >> price;
                                pms.addProduct(admin, id, name, description, quantity, price);
                                break;
                            }
                            case 2:
                                pms.displayProducts();
                                break;
                            case 3:
                                // Search product by name
                            {
                                string searchTerm;
                                cout << "Enter product name to search: ";
                                cin.ignore(); // Ignore newline character
                                getline(cin, searchTerm);
                                pms.searchProductByName(searchTerm);
                            }
                            break;
                            case 4:
                                // Filter products by price range
                            {
                                double minPrice, maxPrice;
                                cout << "Enter minimum price: ";
                                cin >> minPrice;
                                cout << "Enter maximum price: ";
                                cin >> maxPrice;
                                pms.filterProductsByPrice(minPrice, maxPrice);
                            }
                            break;
                            case 5: {
                                // Add to Cart functionality
                                int productId;
                                cout << "Enter product ID to add to cart: ";
                                cin >> productId;
                                Product* productToAdd = pms.getProductById(productId);
                                if (productToAdd != nullptr) {
                                    currentUser.addToCart(productToAdd);
                                } else {
                                    cout << "Product not found!" << endl;
                                }
                                break;
                            }
                            case 6:
                                currentUser.displayCart();
                                break;
                            case 7:
                                currentUser.editProfile();
                            case 8:
                                currentUser.placeOrder();
                                break;
                            case 9:
                                currentUser.displayOrderHistory();
                                break;
                            case 10: {
                                string orderID;
                                cout << "Enter order ID to track: ";
                                cin >> orderID;
                                currentUser.trackOrder(orderID);
                                break;
                            }
                            case 11: {
                                string giftCard;
                                cout << "Enter gift card details: ";
                                cin.ignore(); // Ignore newline character
                                getline(cin, giftCard);
                                currentUser.addGiftCard(giftCard);
                                break;
                            }
                           case 12: {
                                // Add Review and Rating functionality
                                // Prompt user to enter review text and rating, then call addReview() method on the selected product
                                int productId;
                                string reviewText;
                                int rating;
                                cout << "Enter product ID to review: ";
                                cin >> productId;
                                cout << "Enter your review: ";
                                cin.ignore(); // Ignore newline character
                                getline(cin, reviewText);
                                cout << "Enter rating (1 to 5): ";
                                cin >> rating;
                                // getProductById(productId)->addReview(reviewText, rating); // Implement getProductById function
                                cout << "Review added successfully!" << endl; // Remove this line once implemented getProductById
                                break;
                            }
                            case 13: {
                                // Add to Wish List functionality
                                int productId;
                                cout << "Enter product ID to add to wish list: ";
                                cin >> productId;
                                Product* productToAdd = pms.getProductById(productId);
                                if (productToAdd != nullptr) {
                                    currentUser.addToWishList(productToAdd);
                                } else {
                                    cout << "Product not found!" << endl;
                                }
                                break;
                            }
                             case 14:
                                // Manage Inventory
                                {
                                    int productId, quantityToAdd, newQuantity;
                                    cout << "Enter product ID to manage inventory: ";
                                    cin >> productId;
                                    Product* productToManage = pms.getProductById(productId);
                                    if (productToManage != nullptr) {
                                        cout << "Current Stock Level: " << productToManage->getQuantity() << endl;
                                        cout << "1. Add Stock" << endl;
                                        cout << "2. Update Stock Quantity" << endl;
                                        cout << "Enter your choice: ";
                                        int inventoryChoice;
                                        cin >> inventoryChoice;
                                        switch (inventoryChoice) {
                                            case 1:
                                                cout << "Enter quantity to add: ";
                                                cin >> quantityToAdd;
                                                productToManage->addStock(quantityToAdd);
                                                break;
                                            case 2:
                                                cout << "Enter new stock quantity: ";
                                                cin >> newQuantity;
                                                productToManage->updateStock(newQuantity);
                                                break;
                                            default:
                                                cout << "Invalid choice." << endl;
                                        }
                                    } else {
                                        cout << "Product not found!" << endl;
                                    }
                                }
                                break;
                            case 15:
                                logout();
                                break;
                            case 16:
                                cout << "Thank you for using the Online Gift Store|Shop outside the box. Goodbye!" << endl;
                                return 0;
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                        }
                        if (choice == 14) // If logout, break from the inner loop
                            break;
                    }
                }
                break;
            case 3:
                cout << "Thank you for using the Online Gift Store. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
