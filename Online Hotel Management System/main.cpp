#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class RoomRates {
private:
    map<string, double> roomPrices;

public:
    RoomRates() {
        roomPrices["Single"] = 100.0;
        roomPrices["Double"] = 150.0;
        roomPrices["Suite"] = 200.0;
    }

    double getPrice(const string& roomType) {
        if (roomPrices.find(roomType) != roomPrices.end()) {
            return roomPrices[roomType];
        }
        return 0.0;
    }

    void setPrice(const string& roomType, double price) {
        roomPrices[roomType] = price;
    }

    void displayRoomPrices() {
        cout << "Room Prices:" << endl;
        for (const auto& pair : roomPrices) {
            cout << pair.first << ": $" << pair.second << " per night" << endl;
        }
        cout << endl;
    }
};

class RoomDetails {
private:
    string roomType;
    bool wifiAvailable;
    bool tvAvailable;
    string view;

public:
    RoomDetails(const string& type, bool wifi, bool tv, const string& roomView) {
        roomType = type;
        wifiAvailable = wifi;
        tvAvailable = tv;
        view = roomView;
    }

    void displayRoomDetails() {
        cout << "Room Type: " << roomType << endl;
        cout << "WiFi: " << (wifiAvailable ? "Available" : "Not Available") << endl;
        cout << "TV: " << (tvAvailable ? "Available" : "Not Available") << endl;
        cout << "View: " << view << endl;
    }
};

class UserAuthenticator {
private:
    map<string, string> users;
    map<string, string> userRoles;
    map<string, bool> signedUpUsers;

public:
    UserAuthenticator() {}

    bool authenticateUser(const string& username, const string& password) {
        map<string, string>::iterator it = users.find(username);
        if (it != users.end() && it->second == password) {
            cout << "User authenticated successfully!" << endl;
            return true;
        }
        cout << "Invalid username or password." << endl;
        return false;
    }

    bool hasSignedUp(const string& username) {
        return signedUpUsers[username];
    }

    string authorizeUser(const string& username) {
        map<string, string>::iterator it = userRoles.find(username);
        if (it != userRoles.end()) {
            return it->second;
        }
        return "";
    }

    void signUp(const string& username, const string& password, const string& role) {
        users[username] = password;
        userRoles[username] = role;
        signedUpUsers[username] = true;
        cout << "Sign up successful!" << endl;
    }

    void displayRoomDetails() {
        RoomDetails singleRoom("Single", true, true, "City View");
        RoomDetails doubleRoom("Double", true, true, "Garden View");
        RoomDetails suiteRoom("Suite", true, true, "Ocean View");

        cout << "Room Details:" << endl;
        cout << "1. Single Room" << endl;
        singleRoom.displayRoomDetails();
        cout << endl;

        cout << "2. Double Room" << endl;
        doubleRoom.displayRoomDetails();
        cout << endl;

        cout << "3. Suite Room" << endl;
        suiteRoom.displayRoomDetails();
        cout << endl;
    }

    void bookRoom() {
        cout << "Available Rooms:" << endl;
        cout << "1. Single Room" << endl;
        cout << "2. Double Room" << endl;
        cout << "3. Suite Room" << endl;

        int roomChoice;
        cout << "Enter room choice (1/2/3): ";
        cin >> roomChoice;

        string roomType;
        switch(roomChoice) {
            case 1:
                roomType = "Single";
                break;
            case 2:
                roomType = "Double";
                break;
            case 3:
                roomType = "Suite";
                break;
            default:
                cout << "Invalid room choice!" << endl;
                return;
        }

        cout << "You have chosen to book a " << roomType << " room." << endl;
    }
};

class PaymentProcessor {
public:
    void processPayment() {
        cout << "Please enter your payment details:" << endl;
        string paymentDetails;
        cout << "Enter credit/debit card details: ";
        cin >> paymentDetails;
        cout << "Payment processed successfully!" << endl;
    }
};

class RoomAvailability {
private:
    map<string, int> roomAvailability;

public:
    RoomAvailability() {
        roomAvailability["Single"] = 5;
        roomAvailability["Double"] = 3;
        roomAvailability["Suite"] = 2;
    }

    bool isRoomAvailable(const string& roomType) {
        return roomAvailability[roomType] > 0;
    }

    void bookRoom(const string& roomType) {
        if (roomAvailability[roomType] > 0) {
            roomAvailability[roomType]--;
            cout << "Booking successful! You have booked a " << roomType << " room." << endl;
        } else {
            cout << "Sorry, " << roomType << " rooms are currently unavailable." << endl;
        }
    }

    void checkIn(const string& roomType) {
        if (roomAvailability.find(roomType) != roomAvailability.end()) {
            cout << "Welcome! You have checked in to a " << roomType << " room." << endl;
        } else {
            cout << "You have not booked any room. Please book a room first." << endl;
        }
    }

    void checkOut(const string& roomType) {
        if (roomAvailability.find(roomType) != roomAvailability.end()) {
            roomAvailability[roomType]++;
            cout << "Thank you for staying with us. Goodbye!" << endl;
        } else {
            cout << "You have not checked in yet." << endl;
        }
    }

    void updateRoomAvailability(const string& roomType, int count) {
        roomAvailability[roomType] = count;
        cout << "Room availability updated successfully!" << endl;
    }

    void displayRoomAvailability() {
        cout << "Room Availability:" << endl;
        for (const auto& pair : roomAvailability) {
            cout << pair.first << " Room: " << pair.second << endl;
        }
    }
};

class Housekeeping {
private:
    RoomAvailability* availability;

public:
    Housekeeping(RoomAvailability* avail) : availability(avail) {}

    void updateRoomStatus(const string& roomType, int count) {
        availability->updateRoomAvailability(roomType, count);
        cout << "Room status updated successfully!" << endl;
    }

    void displayRoomStatus() {
        availability->displayRoomAvailability();
    }
};

class BookingModification {
private:
    map<string, pair<string, string>> bookingModifications;

public:
    void requestBookingModification(const string& username, const string& newRoomType) {
        bookingModifications[username] = make_pair(newRoomType, "Pending");
        cout << "Booking modification request sent successfully!" << endl;
    }

    void processBookingModification(const string& username, bool approve) {
        if (bookingModifications.find(username) != bookingModifications.end()) {
            if (approve) {
                string newRoomType = bookingModifications[username].first;
                cout << "Booking modification approved. User " << username << " has changed to a " << newRoomType << " room." << endl;
            } else {
                cout << "Booking modification request for user " << username << " rejected." << endl;
            }
            bookingModifications.erase(username);
        } else {
            cout << "No booking modification request found for user " << username << "." << endl;
        }
    }
};

class NotificationSystem {
private:
    map<string, vector<string>> notifications;

public:
    void addNotification(const string& username, const string& notification) {
        notifications[username].push_back(notification);
    }

    void displayNotifications(const string& username) {
        if (notifications.find(username) != notifications.end()) {
            cout << "Notifications for " << username << ":" << endl;
            for (const string& notification : notifications[username]) {
                cout << notification << endl;
            }
        } else {
            cout << "No notifications for " << username << "." << endl;
        }
    }
};

class FeedbackAndReviewSystem {
private:
    map<string, string> feedbacks;
    map<string, string> reviews;

public:
    void submitFeedback(const string& username, const string& feedback) {
        feedbacks[username] = feedback;
        cout << "Feedback submitted successfully!" << endl;
    }

    void submitReview(const string& username, const string& review) {
        reviews[username] = review;
        cout << "Review submitted successfully!" << endl;
    }

    void displayFeedback(const string& username) {
        if (feedbacks.find(username) != feedbacks.end()) {
            cout << "Feedback for " << username << ":" << endl;
            cout << feedbacks[username] << endl;
        } else {
            cout << "No feedback found for " << username << "." << endl;
        }
    }

    void displayReview(const string& username) {
        if (reviews.find(username) != reviews.end()) {
            cout << "Review for " << username << ":" << endl;
            cout << reviews[username] << endl;
        } else {
            cout << "No review found for " << username << "." << endl;
        }
    }
};

class BookingHistory {
private:
    map<string, vector<string>> history;

public:
    void addBooking(const string& username, const string& roomType) {
        history[username].push_back(roomType);
        cout << "Booking added to history!" << endl;
    }

    void displayBookingHistory(const string& username) {
        if (history.find(username) != history.end()) {
            cout << "Booking History for " << username << ":" << endl;
            for (const string& booking : history[username]) {
                cout << booking << endl;
            }
        } else {
            cout << "No booking history found for " << username << "." << endl;
        }
    }
};

int main() {
    RoomRates roomRates;
    UserAuthenticator authenticator;
    PaymentProcessor processor;
    RoomAvailability availability;
    Housekeeping housekeeping(&availability);
    BookingModification bookingModifier;
    NotificationSystem notifier;
    FeedbackAndReviewSystem feedbackAndReview;
    BookingHistory bookingHistory;

    int choice;
    string username, password, role, roomType;

    bool continueLoop = true;
    while (continueLoop) {
        cout << "Choose an option:" << endl;
        cout << "1. Sign Up" << endl;
        cout << "2. Login" << endl;
        cout << "3. View Room Details" << endl;
        cout << "4. Book a Room" << endl;
        cout << "5. View Room Prices" << endl;
        cout << "6. Set Room Price" << endl;
        cout << "7. Make Payment" << endl;
        cout << "8. Check Room Availability" << endl;
        cout << "9. Check-In" << endl;
        cout << "10. Check-Out" << endl;
        cout << "11. Update Room Availability" << endl;
        cout << "12. Display Room Availability" << endl;
        cout << "13. Display Room Status" << endl;
        cout << "14. Request Booking Modification" << endl;
        cout << "15. Process Booking Modification" << endl;
        cout << "16. Submit Feedback" << endl;
        cout << "17. Submit Review" << endl;
        cout << "18. Display Feedback" << endl;
        cout << "19. Display Review" << endl;
        cout << "20. Add Notification" << endl;
        cout << "21. View Notifications" << endl;
        cout << "22. View Booking History" << endl;
        cout << "23. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                cout << "Enter role (admin/user): ";
                cin >> role;
                if (!authenticator.hasSignedUp(username)) {
                    authenticator.signUp(username, password, role);
                } else {
                    cout << "User already signed up!" << endl;
                }
                break;

            case 2:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                if(authenticator.authenticateUser(username, password)) {
                    string userRole = authenticator.authorizeUser(username);
                    if (!userRole.empty()) {
                        cout << "User role: " << userRole << endl;
                    } else {
                        cout << "Failed to authorize user." << endl;
                    }
                }
                break;

            case 3:
                authenticator.displayRoomDetails();
                break;

            case 4:
                authenticator.bookRoom();
                bookingHistory.addBooking(username, roomType);
                break;

            case 5:
                roomRates.displayRoomPrices();
                break;

            case 6:
                cout << "Enter room type (Single/Double/Suite): ";
                cin >> roomType;
                cout << "Enter new price per night: $";
                double price;
                cin >> price;
                roomRates.setPrice(roomType, price);
                cout << "Price for " << roomType << " room set to $" << price << " per night." << endl;
                break;

            case 7:
                processor.processPayment();
                break;

            case 8:
                cout << "Enter room type (Single/Double/Suite): ";
                cin >> roomType;
                if (availability.isRoomAvailable(roomType)) {
                    cout << "Room type " << roomType << " is available." << endl;
                } else {
                    cout << "Room type " << roomType << " is not available." << endl;
                }
                break;

            case 9:
                cout << "Enter room type for check-in (Single/Double/Suite): ";
                cin >> roomType;
                availability.checkIn(roomType);
                break;

            case 10:
                cout << "Enter room type for check-out (Single/Double/Suite): ";
                cin >> roomType;
                availability.checkOut(roomType);
                break;

            case 11:
                {
                    string roomType;
                    int count;
                    cout << "Enter room type (Single/Double/Suite): ";
                    cin >> roomType;
                    cout << "Enter new count: ";
                    cin >> count;
                    housekeeping.updateRoomStatus(roomType, count);
                }
                break;

            case 12:
                availability.displayRoomAvailability();
                break;

            case 13:
                housekeeping.displayRoomStatus();
                break;

            case 14:
                {
                    string feedback;
                    cout << "Enter your username: ";
                    cin >> username;
                    cout << "Enter feedback: ";
                    cin.ignore();
                    getline(cin, feedback);
                    feedbackAndReview.submitFeedback(username, feedback);
                }
                break;

            case 15:
                {
                    string review;
                    cout << "Enter your username: ";
                    cin >> username;
                    cout << "Enter review: ";
                    cin.ignore();
                    getline(cin, review);
                    feedbackAndReview.submitReview(username, review);
                }
                break;

            case 16:
                cout << "Enter your username to view feedback: ";
                cin >> username;
                feedbackAndReview.displayFeedback(username);
                break;

            case 17:
                cout << "Enter your username to view review: ";
                cin >> username;
                feedbackAndReview.displayReview(username);
                break;

            case 18:
                {
                    string notification;
                    cout << "Enter username to send notification to: ";
                    cin >> username;
                    cout << "Enter notification: ";
                    cin.ignore();
                    getline(cin, notification);
                    notifier.addNotification(username, notification);
                    cout << "Notification added successfully!" << endl;
                }
                break;

            case 19:
                cout << "Enter your username: ";
                cin >> username;
                notifier.displayNotifications(username);
                break;

            case 20:
                cout << "Enter your username to view booking history: ";
                cin >> username;
                bookingHistory.displayBookingHistory(username);
                break;

            case 21:
                continueLoop = false;
                break;

            default:
                cout << "Invalid choice. Please choose again." << endl;
                break;
        }
    }

    return 0;
}
