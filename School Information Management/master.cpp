	#include <iostream>
	#include <string>
	
	using namespace std;
	
	class User {
	private:
	    string username;
	    string password;
	    string role;
	    string email;
	public:
	    User(string _username = "", string _password = "", string _role = "", string _email = "") {
	        username = _username;
	        password = _password;
	        role = _role;
	        email = _email;
	    }
	
	    string getUsername() const {
	        return username;
	    }
	
	    string getPassword() const {
	        return password;
	    }
	
	    string getRole() const {
	        return role;
	    }
	
	    string getEmail() const {
	        return email;
	    }
	};
	
	class UserManagement {
	private:
	    static const int MAX_USERS = 100;
	    User users[MAX_USERS];
	    int numUsers = 0;
	public:
	    void registerUser() {
	        if (numUsers < MAX_USERS) {
	            string username, password, role, email;
	            cout << "Enter username: ";
	            cin >> username;
	            cout << "Enter password: ";
	            cin >> password;
	            cout << "Enter role (admin/teacher/parent/student): ";
	            cin >> role;
	            cout << "Enter email: ";
	            cin >> email;
	            users[numUsers] = User(username, password, role, email);
	            numUsers++;
	            cout << "User registered successfully." << endl;
	        } else {
	            cout << "User registration failed. Maximum users reached." << endl;
	        }
	    }
	
	    User* loginUser() {
	        string username, password;
	        cout << "Enter username: ";
	        cin >> username;
	        cout << "Enter password: ";
	        cin >> password;
	        for (int i = 0; i < numUsers; i++) {
	            if (users[i].getUsername() == username && users[i].getPassword() == password) {
	                return &users[i];
	            }
	        }
	        return nullptr;
	    }
	
	    void addStudentToClassroom() {
	        string studentName, classroomName;
	        cout << "Enter student's name: ";
	        cin >> studentName;
	        cout << "Enter classroom name: ";
	        cin >> classroomName;
	        cout << "Student " << studentName << " added to classroom " << classroomName << " successfully." << endl;
	    }
	
	    void addFeeForStudent() {
	        string studentName;
	        int amount;
	        cout << "Enter student's name: ";
	        cin >> studentName;
	        cout << "Enter fee amount: ";
	        cin >> amount;
	        
	        cout << "Fee added successfully for student " << studentName << ": $" << amount << endl;
	    }
	
	    void uploadHomework() {
	        string homeworkName;
	        cout << "Enter homework name: ";
	        cin >> homeworkName;
	        
	        cout << "Homework '" << homeworkName << "' uploaded successfully." << endl;
	    }
	
	    void markAssessment() {
	        string assessmentName;
	        cout << "Enter assessment name: ";
	        cin >> assessmentName;
	        
	        cout << "Assessment '" << assessmentName << "' marked successfully." << endl;
	    }
	
	    void sendNotificationToParents() {
	        string notification;
	        cout << "Enter notification message: ";
	        cin.ignore();
	        getline(cin, notification);
	        
	        cout << "Notification sent to parents: " << notification << endl;
	    }
	
	    void createEvent() {
	        string eventName, eventDate;
	        cout << "Enter event name: ";
	        cin >> eventName;
	        cout << "Enter event date: ";
	        cin >> eventDate;
	        cout << "Event '" << eventName << "' created successfully on " << eventDate << "." << endl;
	    }
	
	    void displayAllUsers() {
	        cout << "All registered users:" << endl;
	        for (int i = 0; i < numUsers; i++) {
	            cout << "Username: " << users[i].getUsername() << endl;
	            cout << "Role: " << users[i].getRole() << endl;
	            cout << "Email: " << users[i].getEmail() << endl;
	            cout << "-----------------------" << endl;
	        }
	    }
	};
	
	int main() {
	    UserManagement userManagement;
	    int choice;
	    while (true) {
	        cout << "Menu:" << endl;
	        cout << "1. Register user" << endl;
	        cout << "2. Login" << endl;
	        cout << "3. Add student to classroom" << endl;
	        cout << "4. Add fee for student" << endl;
	        cout << "5. Upload homework" << endl;
	        cout << "6. Mark assessment" << endl;
	        cout << "7. Send notification to parents" << endl;
	        cout << "8. Create event" << endl;
	        cout << "9. Display all users" << endl;
	        cout << "10. Logout" << endl;
	        cout << "11. Exit" << endl;
	        cout << "Enter your choice: ";
	        cin >> choice;
	        switch (choice) {
	            case 1:
	                userManagement.registerUser();
	                break;
	            case 2:
	                {
	                    User* loggedInUser = userManagement.loginUser();
	                    if (loggedInUser != nullptr) {
	                        cout << "Logged in as: " << loggedInUser->getUsername() << endl;
	                    } else {
	                        cout << "Invalid username or password." << endl;
	                    }
	                }
	                break;
	            case 3:
	                userManagement.addStudentToClassroom();
	                break;
	            case 4:
	                userManagement.addFeeForStudent();
	                break;
	            case 5:
	                userManagement.uploadHomework();
	                break;
	            case 6:
	                userManagement.markAssessment();
	                break;
	            case 7:
	                userManagement.sendNotificationToParents();
	                break;
	            case 8:
	                userManagement.createEvent();
	                break;
	            case 9:
	                userManagement.displayAllUsers();
	                break;
	            case 10:
	                cout << "Logged out." << endl;
	                break;
	            case 11:
	                cout << "Exiting..." << endl;
	                return 0;
	            default:
	                cout << "Invalid choice. Please enter a valid option." << endl;
	        }
	    }
	}
