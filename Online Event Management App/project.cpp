#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Event {
private:
    string name;
    string date;
    string location;

public:
    Event(string n, string d, string l) : name(n), date(d), location(l) {}

    void display() const {
        cout << "Event: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Location: " << location << endl;
    }
};

class Ticket {
private:
    string eventName;
    string eventDate;
    string eventLocation;
    string ticketType;
    int quantity;
    double price;

public:
    Ticket(string name, string date, string location, string type, int qty, double p) 
        : eventName(name), eventDate(date), eventLocation(location), ticketType(type), quantity(qty), price(p) {}

    void displayTicketDetails() const {
        cout << "Event Name: " << eventName << endl;
        cout << "Date: " << eventDate << endl;
        cout << "Location: " << eventLocation << endl;
        cout << "Ticket Type: " << ticketType << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total Price: $" << (price * quantity) << endl;
    }
};

class Payment {
private:
    string cardNumber;
    string cardHolderName;
    string expiryDate;
    string cvv;

public:
    Payment(string number, string holder, string expiry, string cvv) 
        : cardNumber(number), cardHolderName(holder), expiryDate(expiry), cvv(cvv) {}

    bool processPayment(double amount) {
        // Placeholder for payment processing logic
        cout << "Payment processed successfully for amount $" << amount << endl;
        return true;
    }
};

class UserAuthenticator {
private:
    map<string, string> users;
    map<string, string> userRoles;

public:
    UserAuthenticator() {
        users["admin"] = "admin123";
        users["user1"] = "password1";
        users["user2"] = "password2";
        userRoles["admin"] = "admin";
        userRoles["user1"] = "user";
        userRoles["user2"] = "user";
    }

    bool authenticateUser(const string& username, const string& password) {
        auto it = users.find(username);
        if (it != users.end() && it->second == password) {
            cout << "User authenticated successfully!" << endl;
            return true;
        }
        cout << "Invalid username or password." << endl;
        return false;
    }

    string authorizeUser(const string& username) {
        auto it = userRoles.find(username);
        if (it != userRoles.end()) {
            return it->second;
        }
        return "";
    }

    void addUser(const string& username, const string& password, const string& role) {
        users[username] = password;
        userRoles[username] = role;
        cout << "User added successfully!" << endl;
    }
};

class OnlineTicketingSystem {
private:
    vector<Ticket> tickets;

public:
    void generateTicket(string name, string date, string location, string type, int qty, double price) {
        Ticket newTicket(name, date, location, type, qty, price);
        tickets.push_back(newTicket);
        cout << "Ticket generated successfully!" << endl;
    }

    void displayAllTickets() const {
        if (tickets.empty()) {
            cout << "No tickets generated yet." << endl;
            return;
        }

        cout << "Generated Tickets:" << endl;
        for (const Ticket& ticket : tickets) {
            ticket.displayTicketDetails();
            cout << endl;
        }
    }
};

class EventScheduler {
private:
    vector<Event> scheduledEvents;

public:
    void scheduleEvent(const Event& event) {
        scheduledEvents.push_back(event);
        cout << "Event scheduled successfully!" << endl;
    }

    void displayScheduledEvents() const {
        if (scheduledEvents.empty()) {
            cout << "No events scheduled yet." << endl;
            return;
        }

        cout << "Scheduled Events:" << endl;
        for (const Event& event : scheduledEvents) {
            event.display();
            cout << endl;
        }
    }
};

class Venue {
private:
    string name;
    string location;
    string facilities;

public:
    Venue(string n, string loc, string fac) : name(n), location(loc), facilities(fac) {}

    void displayVenueDetails() const {
        cout << "Venue Name: " << name << endl;
        cout << "Location: " << location << endl;
        cout << "Facilities: " << facilities << endl;
    }
};

class VenueManager {
private:
    vector<Venue> venues;

public:
    void addVenue(const string& name, const string& location, const string& facilities) {
        venues.push_back(Venue(name, location, facilities));
        cout << "Venue added successfully!" << endl;
    }

    void displayAllVenues() const {
        if (venues.empty()) {
            cout << "No venues available yet." << endl;
            return;
        }

        cout << "Available Venues:" << endl;
        for (const Venue& venue : venues) {
            venue.displayVenueDetails();
            cout << endl;
        }
    }
};

class Speaker {
private:
    string name;
    string topic;

public:
    Speaker(string n, string t) : name(n), topic(t) {}

    void displaySpeakerDetails() const {
        cout << "Speaker Name: " << name << endl;
        cout << "Topic: " << topic << endl;
    }
};

class SpeakerManager {
private:
    vector<Speaker> speakers;

public:
    void addSpeaker(const string& name, const string& topic) {
        speakers.push_back(Speaker(name, topic));
        cout << "Speaker added successfully!" << endl;
    }

    void displayAllSpeakers() const {
        if (speakers.empty()) {
            cout << "No speakers available yet." << endl;
            return;
        }

        cout << "Available Speakers:" << endl;
        for (const Speaker& speaker : speakers) {
            speaker.displaySpeakerDetails();
            cout << endl;
        }
    }
};

class FeedbackSurvey {
private:
    map<string, int> eventFeedbacks; // Event name -> rating

public:
    void addFeedback(const string& eventName, int rating) {
        eventFeedbacks[eventName] = rating;
    }

    void displayAllFeedbacks() const {
        if (eventFeedbacks.empty()) {
            cout << "No feedback available yet." << endl;
            return;
        }

        cout << "Feedbacks:" << endl;
        for (const auto& feedback : eventFeedbacks) {
            cout << "Event: " << feedback.first << ", Rating: " << feedback.second << endl;
        }
    }
};

class Networking {
private:
    map<string, string> attendees; // Username -> Name
    map<string, vector<string>> connections; // Username -> Connections

public:
    void addAttendee(const string& username, const string& name) {
        attendees[username] = name;
    }

    void connectAttendees(const string& username1, const string& username2) {
        connections[username1].push_back(username2);
        connections[username2].push_back(username1);
        cout << attendees[username1] << " and " << attendees[username2] << " are now connected." << endl;
    }

    void displayAttendeeConnections(const string& username) const {
        auto it = connections.find(username);
        if (it != connections.end()) {
            cout << "Connections for " << attendees.at(username) << ":" << endl;
            for (const string& connection : it->second) {
                cout << " - " << attendees.at(connection) << endl;
            }
        } else {
            cout << "No connections found for " << attendees.at(username) << endl;
        }
    }

    void displayAllAttendees() const {
        cout << "Attendees:" << endl;
        for (const auto& attendee : attendees) {
            cout << "Username: " << attendee.first << ", Name: " << attendee.second << endl;
        }
    }
};

class Customization {
private:
    string brandingElements;
    string logo;
    string customTheme;

public:
    Customization() {}

    Customization(string elements, string logoPath, string theme) 
        : brandingElements(elements), logo(logoPath), customTheme(theme) {}

    void displayCustomizationDetails() const {
        cout << "Branding Elements: " << brandingElements << endl;
        cout << "Logo: " << logo << endl;
        cout << "Custom Theme: " << customTheme << endl;
    }
};

class SocialMediaIntegration {
public:
    void shareEventDetails(const string& eventName, const string& eventDate, const string& eventLocation) {
        cout << "Event Details shared on social media platforms:" << endl;
        cout << "Event Name: " << eventName << endl;
        cout << "Date: " << eventDate << endl;
        cout << "Location: " << eventLocation << endl;
    }

    void displaySocialMediaFeed() {
        // Placeholder for displaying social media feed
        cout << "Social Media Feed: " << endl;
        cout << "1. Twitter: Latest tweets about the event" << endl;
        cout << "2. Facebook: Recent posts related to the event" << endl;
        cout << "3. Instagram: Event photos and stories" << endl;
    }
};

int main() {
    UserAuthenticator authenticator;
    OnlineTicketingSystem ticketingSystem;
    EventScheduler eventScheduler;
    VenueManager venueManager;
    SpeakerManager speakerManager;
    FeedbackSurvey feedbackSurvey;
    Networking networking;
    Customization customization;
    SocialMediaIntegration socialMedia;

    int choice;
    string username, password, role;

    do {
        cout << "\nChoose an option:" << endl;
        cout << "1. Add user" << endl;
        cout << "2. Login" << endl;
        cout << "3. Create Event" << endl;
        cout << "4. Display Events" << endl;
        cout << "5. Generate Ticket" << endl;
        cout << "6. Display All Tickets" << endl;
        cout << "7. Schedule Event" << endl;
        cout << "8. Display Scheduled Events" << endl;
        cout << "9. Add Venue" << endl;
        cout << "10. Display All Venues" << endl;
        cout << "11. Add Speaker" << endl;
        cout << "12. Display All Speakers" << endl;
        cout << "13. Add Feedback" << endl;
        cout << "14. Display All Feedbacks" << endl;
        cout << "15. Make Payment" << endl;
        cout << "16. Add Attendee" << endl;
        cout << "17. Connect Attendees" << endl;
        cout << "18. Display Attendee Connections" << endl;
        cout << "19. Display All Attendees" << endl;
        cout << "20. Customize Event Page" << endl;
        cout << "21. Share Event Details on Social Media" << endl;
        cout << "22. Display Social Media Feed" << endl;
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
                authenticator.addUser(username, password, role);
                break;

            case 2:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                if (authenticator.authenticateUser(username, password)) {
                    string userRole = authenticator.authorizeUser(username);
                    if (!userRole.empty()) {
                        cout << "User role: " << userRole << endl;
                    } else {
                        cout << "Failed to authorize user." << endl;
                    }
                }
                break;

            case 3: {
                string userRole = authenticator.authorizeUser(username);
                if (userRole == "admin") {
                    string name, date, location;
                    cout << "Enter event name: ";
                    cin.ignore(); // Clear the input buffer
                    getline(cin, name);
                    cout << "Enter event date: ";
                    getline(cin, date);
                    cout << "Enter event location: ";
                    getline(cin, location);
                    eventScheduler.scheduleEvent(Event(name, date, location));
                    cout << "Event created successfully!\n";
                } else {
                    cout << "You are not authorized to create events.\n";
                }
                break;
            }

            case 4: {
                eventScheduler.displayScheduledEvents();
                break;
            }

            case 5: {
                string name, date, location, type;
                int qty;
                double price;
                cout << "Enter event name: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, name);
                cout << "Enter event date: ";
                getline(cin, date);
                cout << "Enter event location: ";
                getline(cin, location);
                cout << "Enter ticket type: ";
                getline(cin, type);
                cout << "Enter quantity: ";
                cin >> qty;
                cout << "Enter price per ticket: $";
                cin >> price;
                ticketingSystem.generateTicket(name, date, location, type, qty, price);
                break;
            }

            case 6:
                ticketingSystem.displayAllTickets();
                break;

            case 7: {
                string name, date, location;
                cout << "Enter event name: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, name);
                cout << "Enter event date: ";
                getline(cin, date);
                cout << "Enter event location: ";
                getline(cin, location);
                eventScheduler.scheduleEvent(Event(name, date, location));
                break;
            }

            case 8:
                eventScheduler.displayScheduledEvents();
                break;

            case 9: {
                string name, location, facilities;
                cout << "Enter venue name: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, name);
                cout << "Enter location: ";
                getline(cin, location);
                cout << "Enter facilities: ";
                getline(cin, facilities);
                venueManager.addVenue(name, location, facilities);
                break;
            }

            case 10:
                venueManager.displayAllVenues();
                break;

            case 11: {
                string name, topic;
                cout << "Enter speaker name: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, name);
                cout << "Enter topic: ";
                getline(cin, topic);
                speakerManager.addSpeaker(name, topic);
                break;
            }

            case 12:
                speakerManager.displayAllSpeakers();
                break;

            case 13: {
                string eventName;
                int rating;
                cout << "Enter event name: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, eventName);
                cout << "Rate the event (1-10): ";
                cin >> rating;
                if (rating < 1 || rating > 10) {
                    cout << "Invalid rating. Rating should be between 1 and 10." << endl;
                } else {
                    feedbackSurvey.addFeedback(eventName, rating);
                    cout << "Feedback added successfully!" << endl;
                }
                break;
            }

            case 14:
                feedbackSurvey.displayAllFeedbacks();
                break;

            case 15: {
                string cardNumber, cardHolderName, expiryDate, cvv;
                double amount;
                cout << "Enter card number: ";
                cin >> cardNumber;
                cout << "Enter card holder name: ";
                cin.ignore();
                getline(cin, cardHolderName);
                cout << "Enter expiry date (MM/YY): ";
                cin >> expiryDate;
                cout << "Enter CVV: ";
                cin >> cvv;
                cout << "Enter payment amount: $";
                cin >> amount;

                Payment payment(cardNumber, cardHolderName, expiryDate, cvv);
                if (payment.processPayment(amount)) {
                    cout << "Payment successful!" << endl;
                } else {
                    cout << "Payment failed. Please try again." << endl;
                }
                break;
            }

            case 16: {
                string name;
                cout << "Enter attendee username: ";
                cin >> username;
                cout << "Enter attendee name: ";
                cin.ignore();
                getline(cin, name);
                networking.addAttendee(username, name);
                break;
            }

            case 17: {
                string username1, username2;
                cout << "Enter first attendee username: ";
                cin >> username1;
                cout << "Enter second attendee username: ";
                cin >> username2;
                networking.connectAttendees(username1, username2);
                break;
            }

            case 18: {
                cout << "Enter attendee username: ";
                cin >> username;
                networking.displayAttendeeConnections(username);
                break;
            }

            case 19:
                networking.displayAllAttendees();
                break;

            case 20: {
                string elements, logo, theme;
                cout << "Enter branding elements: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, elements);
                cout << "Enter logo path: ";
                getline(cin, logo);
                cout << "Enter custom theme: ";
                getline(cin, theme);
                customization = Customization(elements, logo, theme);
                cout << "Customization options set successfully!" << endl;
                break;
            }

            case 21: {
                string eventName, eventDate, eventLocation;
                cout << "Enter event name: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, eventName);
                cout << "Enter event date: ";
                getline(cin, eventDate);
                cout << "Enter event location: ";
                getline(cin, eventLocation);
                socialMedia.shareEventDetails(eventName, eventDate, eventLocation);
                break;
            }

            case 22:
                socialMedia.displaySocialMediaFeed();
                break;

            case 23:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please choose again." << endl;
                break;
        }
    } while (choice != 23);

    return 0;
}
