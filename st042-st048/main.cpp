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
