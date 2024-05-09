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
