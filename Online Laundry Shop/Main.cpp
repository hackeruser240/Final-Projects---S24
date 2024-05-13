#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define the Service class
class Service {
private:
    string name;
    double price;

public:
    // Constructor
    Service(const string& _name, double _price) : name(_name), price(_price) {}

    // Getter functions
    string getName() const { return name; }
    double getPrice() const { return price; }
};

// Define the LaundryItem class
class LaundryItem {
private:
    int id;
    string name;
    double weight; // Weight of the item in kilograms
    string material; // Material of the item (e.g., cotton, wool)
    bool isWashed; // Whether the item has been washed

public:
    // Constructor
    LaundryItem(int _id, string _name, double _weight, string _material)
        : id(_id), name(_name), weight(_weight), material(_material), isWashed(false) {}

    // Getter functions
    int getId() const { return id; }
    string getName() const { return name; }
    double getWeight() const { return weight; }
    string getMaterial() const { return material; }
    bool getIsWashed() const { return isWashed; }

    // Function to mark item as washed
    void markAsWashed() {
        isWashed = true;
        cout << name << " has been washed." << endl;
    }
};

// Define the LaundryOrder class
class LaundryOrder {
private:
    int orderId;
    vector<LaundryItem*> items;
    string status;

public:
    // Constructor
    LaundryOrder(int _orderId) : orderId(_orderId), status("Pending") {}

    // Getter functions
    int getOrderId() const { return orderId; }
    string getStatus() const { return status; }

    // Function to add an item to the order
    void addItem(LaundryItem* item) {
        items.push_back(item);
    }

    // Function to update order status
    void updateStatus(const string& newStatus) {
        status = newStatus;
    }

    // Function to display order details
    void displayOrder() const {
        cout << "Order ID: " << orderId << endl;
        cout << "Status: " << status << endl;
        cout << "Items in the order:" << endl;
        for (const auto& item : items) {
            cout << "- Name: " << item->getName() << " | Weight: " << item->getWeight() << "kg | Material: " << item->getMaterial() << endl;
        }
    }
};

// Define the Customer class
class Customer {
public:
    string username;
    string password;
    double balance;
    vector<Service> availableServices; // Vector to store available services
    vector<LaundryItem*> laundryCart;
    vector<LaundryOrder*> orderHistory;
    Service* selectedService; // Pointer to the selected service
    int orderIdCounter;

    // Constructor
    Customer(const string& _username, const string& _password, double _balance = 0.0)
        : username(_username), password(_password), balance(_balance), selectedService(nullptr), orderIdCounter(1) {}

    // Function to add an item to the laundry cart
    void addToCart(LaundryItem* item) {
        laundryCart.push_back(item);
        cout << item->getName() << " added to cart successfully!" << endl;
    }

    // Function to display the laundry cart
    void displayCart() const {
        if (laundryCart.empty()) {
            cout << "Laundry cart is empty." << endl;
        } else {
            cout << "Laundry Cart:" << endl;
            for (const auto& item : laundryCart) {
                cout << "Name: " << item->getName() << " | Weight: " << item->getWeight() << "kg | Material: " << item->getMaterial() << endl;
            }
        }
    }

    // Function to place a laundry order
    void placeOrder() {
        if (laundryCart.empty()) {
            cout << "Cannot place order. Laundry cart is empty." << endl;
        } else {
            // Create a new order
            LaundryOrder* newOrder = new LaundryOrder(orderIdCounter++);

            // Move items from cart to order
            for (const auto& item : laundryCart) {
                newOrder->addItem(item);
            }

            // Update order status
            newOrder->updateStatus("Processing");

            // Add order to history
            orderHistory.push_back(newOrder);

            // Clear the cart
            laundryCart.clear();

            cout << "Laundry order placed successfully!" << endl;
        }
    }

    // Function to display order history
    void displayOrderHistory() const {
        if (orderHistory.empty()) {
            cout << "Order history is empty." << endl;
        } else {
            cout << "Laundry Order History:" << endl;
            for (const auto& order : orderHistory) {
                order->displayOrder();
                cout << endl;
            }
        }
    }

    // Function to update the selected service
    void updateService(Service* service) {
        selectedService = service;
    }

    // Function to display selected service
    void displaySelectedService() const {
        if (selectedService != nullptr) {
            cout << "Selected Service: " << selectedService->getName() << " (" << selectedService->getPrice() << " rupees)" << endl;
        } else {
            cout << "No service selected." << endl;
        }
    }

    // Function to add a service
    void addService(const Service& service) {
        availableServices.push_back(service);
    }

    // Function to display available services
    void displayServices() const {
        cout << "Available Services:" << endl;
        for (const auto& service : availableServices) {
            cout << service.getName() << ": " << service.getPrice() << " rupees" << endl;
        }
    }
};

// Function to register a new customer
void registerCustomer() {
    string username, password, password2;

    cout << "Please enter your username: ";
    cin >> username;

    cout << "Please enter the password: ";
    cin >> password;

    cout << "Please re-enter your password: ";
    cin >> password2;

    if (password == password2) {
        // Perform registration tasks (e.g., store username and password)
        cout << "Customer registered successfully!" << endl;

        // Create a new customer
        Customer newCustomer(username, password);

        // Add available services
        // Assuming Regular Wash and Dry Clean are available services
        Service regularWash("Regular Wash", 500);
        Service dryClean("Dry Clean", 1000);

        // Display available services
        cout << "Available Services:" << endl;
        cout << "1. " << regularWash.getName() << " (" << regularWash.getPrice() << " rupees)" << endl;
        cout << "2. " << dryClean.getName() << " (" << dryClean.getPrice() << " rupees)" << endl;

        int choice;
        cout << "Enter the number corresponding to the service you want to select: ";
        cin >> choice;

        if (choice == 1) {
            newCustomer.updateService(&regularWash);
        } else if (choice == 2) {
            newCustomer.updateService(&dryClean);
        } else {
            cout << "Invalid choice. Service not selected." << endl;
        }

        // Display selected service
        newCustomer.displaySelectedService();
    } else {
        cout << "Passwords do not match. Registration failed.\n";
    }
}

// Function to login an existing customer
bool loginCustomer() {
    // Placeholder for login logic
    return true;
}

// Function to logout
void logout() {
    // Placeholder for logout logic
    cout << "Logged out successfully.\n";
}

// Function to change service
void changeService(Customer& customer) {
    // Implementation remains the same
}

// Function to track order
void trackOrder(const Customer& customer) {
    customer.displayOrderHistory();
}

int main() {
    cout << "Welcome to the Online Laundry Shop!" << endl;

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
                registerCustomer();
                break;
            case 2:
                if (!loginCustomer()) {
                    cout << "Login failed. Exiting..." << endl;
                    return 0;
                }
                // After successful registration or login, proceed to online Laundry Shop
                cout << "Welcome to the online Laundry Shop!" << endl;
                {
                    // Create a customer
                    Customer currentCustomer("currentuser", "currentuserpassword");

                    while (true) {
                        cout << "Online Laundry Shop|Laundry made easy" << endl;
                        cout << "1. Add Laundry Item to Cart" << endl;
                        cout << "2. View Laundry Cart" << endl;
                        cout << "3. Place Laundry Order" << endl;
                        cout << "4. View Order History" << endl;
                        cout << "5. Change Service" << endl;
                        cout << "6. View Selected Service" << endl;
                        cout << "7. Track Order" << endl;
                        cout << "8. Logout" << endl;
                        cout << "9. Exit" << endl;
                        cout << "Enter your choice: ";
                        cin >> choice;
                        switch (choice) {
                            case 1: {
                                int id;
                                string name, material;
                                double weight;
                                cout << "Enter item ID: ";
                                cin >> id;
                                cout << "Enter item name: ";
                                cin >> name;
                                cout << "Enter item material: ";
                                cin >> material;
                                cout << "Enter item weight (in kg): ";
                                cin >> weight;
                                LaundryItem* newItem = new LaundryItem(id, name, weight, material);
                                currentCustomer.addToCart(newItem);
                                break;
                            }
                            case 2:
                                currentCustomer.displayCart();
                                break;
                            case 3:
                                currentCustomer.placeOrder();
                                break;
                            case 4:
                                currentCustomer.displayOrderHistory();
                                break;
                            case 5:
                                changeService(currentCustomer);
                                break;
                            case 6:
                                currentCustomer.displaySelectedService();
                                break;
                            case 7:
                                trackOrder(currentCustomer);
                                break;
                            case 8:
                                logout();
                                break;
                            case 9:
                                cout << "Thank you for using the Online Laundry Shop|Laundry made easy. Goodbye!" << endl;
                                return 0;
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                        }
                        if (choice == 8) // If logout, break from the inner loop
                            break;
                    }
                }
                break;
            case 3:
                cout << "Thank you for using the Online Laundry Shop. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
