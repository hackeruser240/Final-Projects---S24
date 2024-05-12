#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Admin {
private:
    string username;
    string password;
public:
Admin(const string& username, const string& password) : username(username), password(password) {}

     string getUsername() const { return username; }
    string getPassword() const { return password; }

   
};

class Inventory {
private:
    int quantity;
    double price;
public:
    Inventory(int quantity, double price) : quantity(quantity), price(price) {}
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    // Other methods for managing the inventory
};

class Room {
private:
    string type;
    double rate;
    bool available;
    vector<Inventory> inventory;
public:
    Room(const string& type, double rate) : type(type), rate(rate), available(true) {}
    void addInventory(const Inventory& inv) {
        inventory.push_back(inv);
    }
    string getName() const { return type; }
    double getRate() const { return rate; }
    // Other methods for managing the room
};

class RateManager {
private:
    double rate;
public:
    RateManager(double rate) : rate(rate) {}
    void updateRate(double newRate) {
        rate = newRate;
    }
    double getRate() const { return rate; }
	    // Other methods for managing the rate
};

class Discount {
private:
    double amount;
public:
    Discount(double amount) : amount(amount) {}
    double getAmount() const { return amount; }
	    // Other methods for managing the discount
};

class Promotion {
private:
    string description;
public:
    Promotion(const string& description) : description(description) {}
    string getDescription() const { return description; }
    // Other methods for managing the promotion
};

class Report {
private:
    vector<string> data;
public:
    Report(const vector<string>& data) : data(data) {}
    void generateReport() {
        cout << "Generating report..." << endl;
        // Output report data
        for (vector<string>::iterator it = data.begin(); it != data.end(); ++it) {
            cout << *it << endl;
        }
        cout << "Report generation complete." << endl;
    }
};

class Payment {
private:
    string paymentMethod;
    double amount;
public:
    Payment(const string& paymentMethod, double amount) : paymentMethod(paymentMethod), amount(amount) {}
    void processPayment() {
        cout << "Processing payment of " << amount << " via " << paymentMethod << endl;
        // Additional payment processing logic here
    }
	    // Other methods for managing the payment
};

class Booking; // Forward declaration

class User {
private:
    string name;
    string password;
    vector<Booking> bookings;
public:
    User(const string& name, const string& password) : name(name), password(password) {}
    void displayUserInfo() const {
        cout << "User Name: " << name << endl;
        cout << "Password " << password << endl;
    }
    void addBooking(const Booking& booking) {
        bookings.push_back(booking);
    }
	    // Other methods for managing the user
};


class Booking {
private:
    Room room;
    string checkInDate;
    string checkOutDate;

public:
    Booking(const Room& room, const string& checkInDate, const string& checkOutDate) 
        : room(room), checkInDate(checkInDate), checkOutDate(checkOutDate) {}
    
    string getCheckInDate() const {
        return checkInDate;
    }

    string getCheckOutDate() const {
        return checkOutDate;
    }
};

class SearchFilter {
private:
    string type;
public:
    SearchFilter(const string& type) : type(type) {}
    string getType() const { return type; }
    // Other methods for managing the search filter

};

class Review {
private:
    string comment;
    int rating;
public:
    Review(const string& comment, int rating) : comment(comment), rating(rating) {}
    
    string getComment() const {
        return comment;
    }

    int getRating() const {
        return rating;
    }
	    // Other methods for managing the review
};

class CancellationPolicy {
private:
    string policy;
public:
    CancellationPolicy(const string& policy) : policy(policy) {}

    string getPolicy() const {
        return policy;
    }
	    // Other methods for managing the cancellation policy
};

class RoomAssignment {
private:
    Room room;
    string user;
public:
    RoomAssignment(Room& room, const string& user) : room(room), user(user) {}

    Room& getRoom() {
        return room;
    }

    string getUser() const {
        return user;
    }
	    // Other methods for managing the room assignment
};

class PaymentSystem {
private:
    string provider;
public:
    PaymentSystem(const string& provider) : provider(provider) {}

    string getProvider() const {
        return provider;
    }
	    // Other methods for managing the payment system
};

class RoomReservation {
private:
    string roomName;
    string user;
    string checkInDate;
    string checkOutDate;
public:
    RoomReservation(const string& roomName, const string& user, const string& checkInDate, const string& checkOutDate)
        : roomName(roomName), user(user), checkInDate(checkInDate), checkOutDate(checkOutDate) {}

    string getRoomName() const {
        return roomName;
    }

    string getUser() const {
        return user;
    }

    string getCheckInDate() const {
        return checkInDate;
    }

    string getCheckOutDate() const {
        return checkOutDate;
    }
	    // Other methods for managing the room reservation
};


int main() {
   char choice;
    cout << "WOLCOME TO HOTEL RESERVATION SYSTEM :" << endl << endl;
    start:
    cout << "Choose an option:" << endl;
    cout << "1. Admin" << endl;
    cout << "2. Inventory" << endl;
    cout << "3. Room Availability" << endl;
    cout << "4. Booked Rooms" << endl;
    cout << "5. Rate Manager" << endl;
    cout << "6. Discount" << endl;
    cout << "7. Promotion" << endl;
    cout << "8. Report" << endl;
    cout << "9. Payment" << endl;
    cout << "10 User login (press(a))" << endl;
    cout << "11.SearchFilter  (press(b))" << endl;
    cout << "12.Booking room (press(c))" << endl;
    cout << "13.Review  (press(d))" << endl;
    cout << "14.CancellationPolicy  (press(e))" << endl;
    cout << "15.PaymentSystem  (press(f))" << endl;
    cout << "16.RoomReservation  (press(g))" << endl;
    cout << "17.Exit  (press(h))" << endl << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case '1': {
            // Admin
             cout<< endl;
            Admin admin("admin", "admin123");
              cout << "WELCOME ADMIN! :" << endl;
            cout << "Admin Username: " << admin.getUsername() << endl;
            cout << "Admin Password: " << admin.getPassword() << endl;
                       cout << endl;
		    break;
        }
        case '2': {
            // Inventory
             cout<< endl;
            Inventory item(10, 2000);
               cout << "GETTING AVAILABLE ROOMS QUANTITY AND THEIR PRICES..." << endl;
            cout << "Item Quantity: " << item.getQuantity() << endl;
            cout << "Item Price: $" << item.getPrice() << endl;
                      cout << endl;
		    break;
        }
        case '3': {
            // Room
             cout<< endl;
             cout << "Rooms are available... :" << endl << endl;
            Room room("Luxgerious", 3000);
            cout << "Room Name: " << room.getName() << endl;
            cout << "Room Rate: $" << room.getRate() << "/night" << endl;
                     Room room1("Standerd", 1000);
            cout << "Room Name: " << room1.getName() << endl;
            cout << "Room Rate: $" << room1.getRate() << "/night" << endl;
                      cout << endl;
		    break;
        }
        
        case '4': {
            // RoomAssignment
             cout<< endl;
             cout << "BOOKED ROOMS.... " << endl;    
            Room room2("Luxgerious", 3000);
            RoomAssignment roomAssignment(room2, "Ahmad ");
            cout << "Assigned Room: " << roomAssignment.getRoom().getName() << endl;
            cout << "Assigned User: " << roomAssignment.getUser() << endl;
            // RoomAssignment
             cout<< endl;
            Room rooom1("Standerd", 1000);
            RoomAssignment roomAssignment1(rooom1, "Ali ");
            cout << "Assigned Room: " << roomAssignment1.getRoom().getName() << endl;
            cout << "Assigned User: " << roomAssignment1.getUser() << endl;
		              cout << endl;
		    break;
        }
        
        case '5': {
            // RateManager
            cout << endl;
           cout << "Managing rates... :" << endl;
  
            RateManager rateManager(0.1);
            rateManager.updateRate(3000);
            cout << endl;
            cout << "Updated Rate: " << rateManager.getRate() << endl;
                       cout << endl;
		    break;
        }
        case '6': {
            // Discount
            cout << endl;
            cout << "GENERATING DISCOUNTS :" << endl;
  
            Discount discount(2000);
             cout<< endl;
            cout << "Discount amount: " << discount.getAmount() << endl;
            cout << endl;
		              cout << endl;
		    break;
        }
        case '7': {
            // Promotion
            
             cout << "GENERATING PROMOTIONS :" << endl << endl;
            Promotion promotion("Free upgrade to premium package");
            cout << "Promotion description: " << promotion.getDescription() << endl;
               cout << endl;
		    break;
        }
        case '8': {
            // Report
            cout << "GENERATING REPORTS... :" << endl;
            vector<string> reportData;
            reportData.push_back("Entry 1");
            reportData.push_back("Entry 2");
            reportData.push_back("Entry 3");
            Report report(reportData);
            report.generateReport();
                      cout << endl;
		    break;
        }
        case '9': {
            // Payment
            cout << "Payment details...(admin function) :" << endl;
            Payment payment("Credit Card", 1000.0);
            payment.processPayment();
                     cout << endl;
		    break;
        }
        case 'a': {
            // User
         cout << "USER HAS LOGIN SUCCESSFULLY" << endl;
            User user("Bilal Saleem", "pasword123");
            user.displayUserInfo();
                      cout << endl;
		    break;
        }
        case 'b': {
            // SearchFilter
         cout << "Searching for room.... " << endl;
            SearchFilter filter("Standard");
            cout << "Search Filter Type: " << filter.getType() << endl;
                      cout << endl;
		    break;
        }
        case 'c': {
            // Booking
             cout << "BOOKING ROOM... :" << endl;
            Room room1("Standard", 1000);
            Booking booking(room1, "2024-05-12", "2024-05-15");
            cout << "Check-In Date: " << booking.getCheckInDate() << endl;
            cout << "Check-Out Date: " << booking.getCheckOutDate() << endl;
                     cout << endl;
		    break;
        }
        case 'd': {
            // Review
             cout << "Submitting review... " << endl;
            Review review("Great hotel, excellent service!", 5);
            cout << "Review Comment: " << review.getComment() << endl;
            cout << "Review Rating: " << review.getRating() << " stars" << endl;
                      cout << endl;
		    break;
        }
        case 'e': {
            // CancellationPolicy
             cout << "Canceling Booking... " << endl;    
            CancellationPolicy policy("Free cancellation up to 24 hours before check-in");
            cout << "Cancellation Policy: " << policy.getPolicy() << endl;
                     cout << endl;
		    break;
        }

        case 'f': {
            // PaymentSystem
             cout << "Payment options... " << endl; 
            PaymentSystem paymentSystem("PayPal");
            cout << "Payment System Provider: " << paymentSystem.getProvider() << endl;
            PaymentSystem paymentSystem1("Bank transfer");
            cout << "Payment System Provider: " << paymentSystem1.getProvider() << endl;          
		             cout << endl;
		    break;
        }
        case 'g': {
            // RoomReservation
            RoomReservation reservation("Standard Room", "Farhan", "2024-05-15", "2024-05-20");
            cout << "Room Name: " << reservation.getRoomName() << endl;
            cout << "User: " << reservation.getUser() << endl;
            cout << "Check-in Date: " << reservation.getCheckInDate() << endl;
            cout << "Check-out Date: " << reservation.getCheckOutDate() << endl;
                   cout << endl;
	        break;
        }
        case 'h':
            return 0; // Exit the program if '20' is chosen
        default:
            cout << "Invalid choice. Please try again." << endl;
            goto start; // Jump to the start label to get the choice again
    }

    goto start; // Loop until the user chooses to exit

}
