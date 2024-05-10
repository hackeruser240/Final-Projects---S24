#include <iostream>
#include <string>

using namespace std;

// User class
class User {
public:
    string username, password, name, email, phone;
    void registerUser() {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter email: ";
        cin >> email;
        cout << "Enter phone: ";
        cin >> phone;
    }
    void login() {
        string enteredUsername, enteredPassword;
        cout << "Enter username: ";
        cin >> enteredUsername;
        cout << "Enter password: ";
        cin >> enteredPassword;
        if (enteredUsername == username && enteredPassword == password) {
            cout << "Login successful!" << endl;
        } else {
            cout << "Invalid username or password!" << endl;
        }
    }
    void profile() {
        cout << "Username: " << username << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
    }
};

// Vehicle class
class Vehicle {
public:
    int vehicleID;
    string type, brand, model, year, condition;
    bool availability;
    void addVehicle() {
        cout << "Enter vehicle ID: ";
        cin >> vehicleID;
        cout << "Enter vehicle type: ";
        cin >> type;
        cout << "Enter vehicle brand: ";
        cin >> brand;
        cout << "Enter vehicle model: ";
        cin >> model;
        cout << "Enter vehicle year: ";
        cin >> year;
        cout << "Enter vehicle condition: ";
        cin >> condition;
        availability = true;
    }
    void updateVehicle() {
        cout << "Enter new vehicle condition: ";
        cin >> condition;
    }
    void searchVehicle() {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Vehicle type: " << type << endl;
        cout << "Vehicle brand: " << brand << endl;
        cout << "Vehicle model: " << model << endl;
        cout << "Vehicle year: " << year << endl;
        cout << "Vehicle condition: " << condition << endl;
        if (availability) {
            cout << "Vehicle is available." << endl;
        } else {
            cout << "Vehicle is not available." << endl;
        }
    }
};

// Reservation class
class Reservation {
public:
    int reservationID, vehicleID, userID;
    string startDate, endDate, status;
    void makeReservation() {
        cout << "Enter vehicle ID: ";
        cin >> vehicleID;
        cout << "Enter user ID: ";
        cin >> userID;
        cout << "Enter start date: ";
        cin >> startDate;
        cout << "Enter end date: ";
        cin >> endDate;
        status = "pending";
    }
    void cancelReservation() {
        status = "cancelled";
    }
    void updateReservation() {
        cout << "Enter new start date: ";
        cin >> startDate;
        cout << "Enter new end date: ";
        cin >> endDate;
    }
};

// Booking class
class Booking {
public:
    int bookingID, reservationID;
    string paymentMethod, paymentStatus;
    void makeBooking() {
        cout << "Enter reservation ID: ";
        cin >> reservationID;
        cout << "Enter payment method: ";
        cin >> paymentMethod;
        paymentStatus = "pending";
    }
    void updateBooking() {
        cout << "Enter payment status: ";
        cin >> paymentStatus;
    }
    void confirmPayment() {
        if (paymentStatus == "paid") {
            cout << "Booking confirmed!" << endl;
        } else {
            cout << "Payment pending!" << endl;
        }
    }
};

// Pricing class
class Pricing {
public:
    string vehicleType;
    double dailyRate, weeklyRate, monthlyRate;
    void calculatePrice() {
        cout << "Enter vehicle type: ";
        cin >> vehicleType;
        cout << "Enter daily rate: ";
        cin >> dailyRate;
        cout << "Enter weekly rate: ";
        cin >> weeklyRate;
        cout << "Enter monthly rate: ";
        cin >> monthlyRate;
    }
};

// AvailabilityCalendar class
class AvailabilityCalendar {
public:
    int vehicleID;
    bool availabilityStatus;
    void updateAvailability() {
        cout << "Enter vehicle ID: ";
        cin >> vehicleID;
        cout << "Enter availability status (0/1): ";
        cin >> availabilityStatus;
    }
    void checkAvailability() {
        if (availabilityStatus) {
            cout << "Vehicle is available." << endl;
        } else {
            cout << "Vehicle is not available." << endl;
        }
    }
};

// GPS Tracking class
class GPSTracking {
public:
    int vehicleID;
    string location;
    void updateLocation() {
        cout << "Enter vehicle ID: ";
        cin >> vehicleID;
        cout << "Enter location: ";
        cin >> location;
    }
    void trackVehicle() {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Location: " << location << endl;
    }
};

// Maintenance class
class Maintenance {
public:
    int vehicleID;
    string maintenanceStatus;
    void scheduleMaintenance() {
        cout << "Enter vehicle ID: ";
        cin >> vehicleID;
        cout << "Enter maintenance status: ";
        cin >> maintenanceStatus;
    }
    void updateMaintenance() {
        cout << "Enter new maintenance status: ";
        cin >> maintenanceStatus;
    }
};

// Feedback class
class Feedback {
public:
    int rating;
    string comment;
    void addFeedback() {
        cout << "Enter rating (1-5): ";
        cin >> rating;
        cout << "Enter comment: ";
        cin >> comment;
    }
    void viewFeedback() {
        cout << "Rating: " << rating << endl;
        cout << "Comment: " << comment << endl;
    }
};

// Customer Support class
class CustomerSupport {
public:
    string issue, resolution;
    void reportIssue() {
        cout << "Enter issue: ";
        cin >> issue;
    }
    void resolveIssue() {
        cout << "Enter resolution: ";
        cin >> resolution;
    }
};

int main() {
    User user;
    Vehicle vehicle;
    Reservation reservation;
    Booking booking;
    Pricing pricing;
    AvailabilityCalendar availabilityCalendar;
    GPSTracking gpsTracking;
    Maintenance maintenance;
    Feedback feedback;
    CustomerSupport customerSupport;

    int choice;
    while (true) {
        cout << "1. Register User\n2. Login User\n3. Add Vehicle\n4. Search Vehicle\n5. Make Reservation\n6. Make Booking\n7. Update Booking\n8. Confirm Payment\n9. Calculate Price\n10. Update Availability\n11. Check Availability\n12. Update Location\n13. Track Vehicle\n14. Schedule Maintenance\n15. Update Maintenance\n16. Add Feedback\n17. View Feedback\n18. Report Issue\n19. Resolve Issue\n20. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                user.registerUser();
                break;
            case 2:
                user.login();
                break;
            case 3:
                vehicle.addVehicle();
                break;
            case 4:
                vehicle.searchVehicle();
                break;
            case 5:
                reservation.makeReservation();
                break;
            case 6:
                booking.makeBooking();
                break;
            case 7:
                booking.updateBooking();
                break;
            case 8:
                booking.confirmPayment();
                break;
            case 9:
                pricing.calculatePrice();
                break;
            case 10:
                availabilityCalendar.updateAvailability();
                break;
            case 11:
                availabilityCalendar.checkAvailability();
                break;
            case 12:
                gpsTracking.updateLocation();
                break;
            case 13:
                gpsTracking.trackVehicle();
                break;
            case 14:
                maintenance.scheduleMaintenance();
                break;
            case 15:
                maintenance.updateMaintenance();
                break;
            case 16:
                feedback.addFeedback();
                break;
            case 17:
                feedback.viewFeedback();
                break;
            case 18:
                customerSupport.reportIssue();
                break;
            case 19:
                customerSupport.resolveIssue();
                break;
            case 20:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
