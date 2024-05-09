// User class for authentication
class User {
private:
    string email;
    string password;
    UserType type; // Indicates user type
    Payment* paymentHistory; // Payment history for the user
    int paymentCount; // Count of payments

public:
    User(string _email, string _password, UserType _type) : email(_email), password(_password), type(_type), paymentHistory(nullptr), paymentCount(0) {}

    bool authenticate(string _email, string _password) {
        return (email == _email && password == _password);
    }

    UserType getType() const {
        return type;
    }

    void addToPaymentHistory(string date, double totalAmount, string product1, string product2) {
        Payment* newPayment = new Payment(date, totalAmount, product1, product2);
        if (paymentHistory == nullptr) {
            paymentHistory = new Payment[1];
            paymentHistory[0] = *newPayment;
        }
        else {
            Payment* temp = new Payment[paymentCount + 1];
            for (int i = 0; i < paymentCount; ++i) {
                temp[i] = paymentHistory[i];
            }
            temp[paymentCount] = *newPayment;
            delete[] paymentHistory;
            paymentHistory = temp;
        }
        paymentCount++;
        delete newPayment;
    }

    void displayPaymentHistory() {
        cout << "\nPayment History:payment done" << endl;
        for (int i = 0; i < paymentCount; ++i) {
            cout << "Date: " << paymentHistory[i].date << endl;
            cout << "Total Amount: $" << paymentHistory[i].totalAmount << endl;
            cout << "Products Purchased: " << paymentHistory[i].product1 << ", " << paymentHistory[i].product2 << endl;
            cout << endl;
        }
    }

    ~User() {
        delete[] paymentHistory;
    }
};

// Product class for product listings
class Product {
private:
    string name;
    double price;
    string description;
    int stock;
    ShippingStatus shippingStatus;
    string trackingNumber;

public:
    Product(string _name, double _price, string _description, int _stock) : name(_name), price(_price), description(_description), stock(_stock), shippingStatus(ShippingStatus::NotShipped), trackingNumber("") {}

    Product() : name(""), price(0.0), description(""), stock(0), shippingStatus(ShippingStatus::NotShipped), trackingNumber("") {} // Default constructor

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Description: " << description << endl;
        cout << "Stock: " << stock << endl;
        cout << "Shipping Status: ";
        switch (shippingStatus) {
        case ShippingStatus::NotShipped:
            cout << "Not Shipped" << endl;
            break;
        case ShippingStatus::Shipped:
            cout << "Shipped (Tracking Number: " << trackingNumber << ")" << endl;
            break;
        case ShippingStatus::Delivered:
            cout << "Delivered (Tracking Number: " << trackingNumber << ")" << endl;
            break;
        }
    }

    void ship(string _trackingNumber) {
        shippingStatus = ShippingStatus::Shipped;
        trackingNumber = _trackingNumber;
    }

    void deliver() {
        shippingStatus = ShippingStatus::Delivered;
    }

    string getName() const {
        return name;
    }
};

// ShoppingCart class for managing shopping cart
class ShoppingCart {
private:
    static const int MAX_ITEMS = 10; // Maximum items in the cart
    Product items[MAX_ITEMS]; // Array to hold products
    int itemCount;

public:
    ShoppingCart() : itemCount(0) {}

    void addToCart(Product product) {
        if (itemCount < MAX_ITEMS) {
            items[itemCount++] = product;
        }
        else {
            cout << "Cart is full!" << endl;
        }
    }

    void displayCart() {
        cout << "Shopping Cart:" << endl;
        for (int i = 0; i < itemCount; ++i) {
            items[i].displayInfo();
            cout << endl;
        }
    }
};

// Admin class for managing products
class Admin {
public:
    bool authenticate(string _email, string _password) {
        // Perform admin authentication
        // For simplicity, hardcoding the admin credentials
        return (_email == "sultan@gmail.com" && _password == "password123");
    }

    void adminPanel() {
        char choice;
        do {
            cout << "\nAdmin Panel" << endl;
            cout << "1. Add Product" << endl;
            cout << "2. Edit Product" << endl;
            cout << "3. Delete Product" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case '1':
                addProduct();
                break;
            case '2':
                editProduct();
                break;
            case '3':
                deleteProduct();
                break;
            case '4':
                cout << "Exiting Admin Panel..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        } while (choice != '4');
    }

    void addProduct() {
        string name;
        cout << "Enter name of the product to add: ";
        cin.ignore();
        getline(cin, name);
        cout << "Product '" << name << "' added successfully!" << endl;
    }

    void editProduct() {
        string name;
        cout << "Enter name of the product to edit: ";
        cin.ignore();
        getline(cin, name);
        cout << "Product '" << name << "' edited successfully!" << endl;
    }

    void deleteProduct() {
        string name;
        cout << "Enter name of the product to delete: ";
        cin.ignore();
        getline(cin, name);
        cout << "Product '" << name << "' deleted successfully!" << endl;
    }
};

int main() {
    // Sample user for authentication
    User user("hussnain@gmail.com", "password123", UserType::Regular);

    // Sample products for listing
    Product product1("Smartphone", 999.99, "A high-end smartphone with advanced features.", 10);
    Product product2("Laptop", 1499.99, "Powerful laptop for gaming and productivity.", 5);

    // Sample shopping cart
    ShoppingCart cart;

    // Authentication
    string email, password;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;

    Admin admin;
    if (admin.authenticate(email, password)) {
        cout << "Authentication successful! You are logged in as an admin." << endl;
        admin.adminPanel();
    }
    else if (user.authenticate(email, password)) {
        cout << "Authentication successful! You are logged in as a regular user." << endl;

        // Display product listings
        cout << "\nProduct Listings:\n";
        product1.displayInfo();
        cout << endl;
        product2.displayInfo();
        cout << endl;

        // Add products to cart
        cart.addToCart(product1);
        cart.addToCart(product2);

        // Display shopping cart
        cart.displayCart();

        // Simulate payment
        user.addToPaymentHistory("2024-05-10", 2499.98, product1.getName(), product2.getName());

        // Display payment history
        user.displayPaymentHistory();
    }
    else {
        cout << "Authentication failed!" << endl;
    }

    return 0;
}
