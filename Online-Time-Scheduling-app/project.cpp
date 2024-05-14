#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Task {
private:
    string title;
    string description;
    string date;
    string time;

public:
    // Constructors
    Task() : title(""), description(""), date(""), time("") {}
    Task(const string& title, const string& description, const string& date, const string& time)
        : title(title), description(description), date(date), time(time) {}

    // Function to display task details
    void display() const {
        cout << "Title: " << title << endl;
        cout << "Description: " << description << endl;
        cout << "Date: " << date << endl;
        cout << "Time: " << time << endl;
    }

    // Getter methods
    string getTitle() const { return title; }
    string getDate() const { return date; }
    string getTime() const { return time; }

    // Function to validate the time format
    bool validateTimeFormat(const string& timeStr) const {
        // Time format: HH:MM
        if (timeStr.length() != 5)
            return false;
        if (timeStr[2] != ':')
            return false;
        if (!isdigit(timeStr[0]) || !isdigit(timeStr[1]) || !isdigit(timeStr[3]) || !isdigit(timeStr[4]))
            return false;
        if (stoi(timeStr.substr(0, 2)) > 23 || stoi(timeStr.substr(3, 2)) > 59)
            return false;
        return true;
    }
};

class TimeSchedulingSystem {
private:
    string adminPassword;
    string loggedInUser;
    Task* tasks;
    int numTasks;
    int capacity;

    struct Event {
        string title;
        time_t startTime;
        time_t endTime;
    };

    Event* events; // Declare events array as a member
    int numEvents; // Declare numEvents and eventCapacity as members
    int eventCapacity;

    // Feedback related members
    string feedback;

public:
    TimeSchedulingSystem() : adminPassword("password"), events(nullptr), numEvents(0), eventCapacity(10), tasks(nullptr), numTasks(0), capacity(10), feedback("") {
        events = new Event[eventCapacity];
        tasks = new Task[capacity];
    }

    ~TimeSchedulingSystem() {
        delete[] events;
        delete[] tasks;
    }

    void registerUser() {
        string username, password, email, fullName;
        cout << "Enter a username: ";
        cin >> username;
        cout << "Enter a password: ";
        cin >> password;
        cout << "Enter email: ";
        cin >> email;
        cout << "Enter full name: ";
        cin.ignore(); // Ignore newline character left in the buffer
        getline(cin, fullName);

        cout << "User registered successfully!" << endl;
    }

    int login() {
        string pass ="";
        cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\tADMIN LOGIN SYSTEM ";
        cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\tEnter Password: ";
        cin >> pass;

        if (pass == adminPassword) {
            cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
            system("PAUSE");
            system("CLS");
            return 1;
        }
        else {
            cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n\a\a";
            system("PAUSE");
            system("CLS");
            return login();
        }
    }

    void loginUser() {
        string username, password;
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;

        loggedInUser = username;

        cout << "Login successful!" << endl;
    }

    void logoutUser() {
        loggedInUser = "";
        cout << "Logged out successfully!" << endl;
    }

    void displayMenu() {
        cout << "\n[1] Register User\n[2] Login User\n[3] Logout User\n[4] Add Task\n[5] View All Tasks\n[6] View Tasks by Date\n[7] Search Tasks\n[8] Track Deadlines\n[9] Add Event\n[10] View All Events\n[11] Edit Event\n[12] Provide Feedback\n[13] Delete Task\n[14] Delete Event\n[15] Exit" << endl;
    }

    void run() {
        cout << "Welcome to the Time Scheduling System!" << endl;

        // Admin login
        while (login() != 1) {
            cout << "Please try again." << endl;
        }

        while (true) {
            displayMenu();
            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    registerUser();
                    break;
                case 2:
                    loginUser();
                    break;
                case 3:
                    if (loggedInUser != "")
                        logoutUser();
                    else
                        cout << "You are not logged in." << endl;
                    break;
                case 4:
                    addTask();
                    break;
                case 5:
                    displayAllTasks();
                    break;
                case 6:
                    displayCalendarView();
                    break;
                case 7:
                    searchTasks();
                    break;
                case 8:
                    trackDeadlines();
                    break;
                case 9:
                    addEvent();
                    break;
                case 10:
                    viewAllEvents();
                    break;
                case 11:
                    editEvent(); // Add the option to edit event
                    break;
                case 12:
                    provideFeedback(); // Add the feedback option
                    break;
                case 13:
                    deleteTask(); // Add the option to delete task
                    break;
                case 14:
                    deleteEvent(); // Add the option to delete event
                    break;
                case 15:
                    cout << "Goodbye!" << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    void addTask() {
        string title, description, date, time;
        cout << "Enter task title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter task description: ";
        getline(cin, description);
        cout << "Enter task date (YYYY-MM-DD): ";
        cin >> date;
        cout << "Enter task time (HH:MM): ";
        cin >> time;

        // Validate time format
        Task newTask(title, description, date, time);
        if (!newTask.validateTimeFormat(time)) {
            cout << "Invalid time format. Time must be in HH:MM format." << endl;
            return;
        }

        if (numTasks == capacity) {
            // Resize the array if capacity is reached
            capacity *= 2;
            Task* temp = new Task[capacity];
            for (int i = 0; i < numTasks; ++i) {
                temp[i] = tasks[i];
            }
            delete[] tasks;
            tasks = temp;
        }

        tasks[numTasks++] = newTask;
        cout << "Task added successfully!" << endl;
    }

    void displayAllTasks() const {
        if (numTasks == 0) {
            cout << "No tasks available." << endl;
            return;
        }
        cout << "All Tasks:" << endl;
        for (int i = 0; i < numTasks; ++i) {
            cout << "Task " << i + 1 << ":" << endl;
            tasks[i].display();
            cout << endl;
        }
    }

    void displayCalendarView() const {
        cout << "Calendar View:" << endl;
        cout << "------------------------------" << endl;
        cout << "Date            Tasks" << endl;
        cout << "------------------------------" << endl;

        // Loop through each date from 1 to 31
        for (int day = 1; day <= 31; ++day) {
            cout << day << ":" << endl;
            bool tasksFound = false;

            // Loop through all tasks to find tasks for the current date
            for (int i = 0; i < numTasks; ++i) {
                int taskDay = stoi(tasks[i].getDate().substr(8, 2));
                if (taskDay == day) {
                    // If a task is found for the current date, display it
                    cout << "    " << tasks[i].getTitle() << " at " << tasks[i].getTime() << endl;
                    tasksFound = true;
                }
            }

            // If no tasks were found for the current date, indicate that
            if (!tasksFound) {
                cout << "    No tasks" << endl;
            }
        }

        cout << "------------------------------" << endl;
    }

    void addEvent() {
        Event newEvent; // Declare newEvent here

        cout << "Enter event title: ";
        cin.ignore();
        getline(cin, newEvent.title);

        cout << "Enter event start time (YYYY-MM-DD HH:MM): ";
        string startTimeStr;
        getline(cin, startTimeStr);
        tm startTimeStruct = {};
        sscanf(startTimeStr.c_str(), "%d-%d-%d %d:%d", &startTimeStruct.tm_year, &startTimeStruct.tm_mon,
               &startTimeStruct.tm_mday, &startTimeStruct.tm_hour, &startTimeStruct.tm_min);
        startTimeStruct.tm_year -= 1900; // tm_year is years since 1900
        startTimeStruct.tm_mon--;        // tm_mon is months since January
        newEvent.startTime = mktime(&startTimeStruct);

        cout << "Enter event end time (YYYY-MM-DD HH:MM): ";
        string endTimeStr;
        getline(cin, endTimeStr);
        tm endTimeStruct = {};
        sscanf(endTimeStr.c_str(), "%d-%d-%d %d:%d", &endTimeStruct.tm_year, &endTimeStruct.tm_mon,
               &endTimeStruct.tm_mday, &endTimeStruct.tm_hour, &endTimeStruct.tm_min);
        endTimeStruct.tm_year -= 1900;
        endTimeStruct.tm_mon--;
        newEvent.endTime = mktime(&endTimeStruct);

        if (numEvents == eventCapacity) {
            // Resize the array if capacity is reached
            eventCapacity *= 2;
            Event* temp = new Event[eventCapacity]; // Declare temp here
            for (int i = 0; i < numEvents; ++i) {
                temp[i] = events[i];
            }
            delete[] events;
            events = temp;
        }

        events[numEvents++] = newEvent;
        cout << "Event added successfully!" << endl;
    }

    void viewAllEvents() const {
        if (numEvents == 0) {
            cout << "No events available." << endl;
            return;
        }
        cout << "All Events:" << endl;
        for (int i = 0; i < numEvents; ++i) {
            cout << "Event " << i + 1 << ":" << endl;
            cout << "Title: " << events[i].title << endl;
            cout << "Start Time: " << asctime(localtime(&events[i].startTime));
            cout << "End Time: " << asctime(localtime(&events[i].endTime)) << endl;
            cout << endl;
        }
    }

    void editEvent() {
        if (numEvents == 0) {
            cout << "No events available to edit." << endl;
            return;
        }

        // Display all events to let the user choose which one to edit
        cout << "Available Events:" << endl;
        for (int i = 0; i < numEvents; ++i) {
            cout << i + 1 << ". " << events[i].title << endl;
        }

        int choice;
        cout << "Enter the index of the event you want to edit: ";
        cin >> choice;
        if (choice < 1 || choice > numEvents) {
            cout << "Invalid choice." << endl;
            return;
        }

        // Edit the selected event
        Event& selectedEvent = events[choice - 1]; // Get a reference to the selected event
        cout << "Enter new title: ";
        cin.ignore();
        getline(cin, selectedEvent.title);
        cout << "Enter new start time (YYYY-MM-DD HH:MM): ";
        string startTimeStr;
        getline(cin, startTimeStr);
        tm startTimeStruct = {};
        sscanf(startTimeStr.c_str(), "%d-%d-%d %d:%d", &startTimeStruct.tm_year, &startTimeStruct.tm_mon,
               &startTimeStruct.tm_mday, &startTimeStruct.tm_hour, &startTimeStruct.tm_min);
        startTimeStruct.tm_year -= 1900; // tm_year is years since 1900
        startTimeStruct.tm_mon--;        // tm_mon is months since January
        selectedEvent.startTime = mktime(&startTimeStruct);
        cout << "Enter new end time (YYYY-MM-DD HH:MM): ";
        string endTimeStr;
        getline(cin, endTimeStr);
        tm endTimeStruct = {};
        sscanf(endTimeStr.c_str(), "%d-%d-%d %d:%d", &endTimeStruct.tm_year, &endTimeStruct.tm_mon,
               &endTimeStruct.tm_mday, &endTimeStruct.tm_hour, &endTimeStruct.tm_min);
        endTimeStruct.tm_year -= 1900;
        endTimeStruct.tm_mon--;
        selectedEvent.endTime = mktime(&endTimeStruct);

        cout << "Event edited successfully!" << endl;
    }

    void deleteTask() {
        if (numTasks == 0) {
            cout << "No tasks available to delete." << endl;
            return;
        }

        // Display all tasks to let the user choose which one to delete
        cout << "Available Tasks:" << endl;
        for (int i = 0; i < numTasks; ++i) {
            cout << i + 1 << ". " << tasks[i].getTitle() << endl;
        }

        int choice;
        cout << "Enter the index of the task you want to delete: ";
        cin >> choice;
        if (choice < 1 || choice > numTasks) {
            cout << "Invalid choice." << endl;
            return;
        }

        // Shift tasks to overwrite the deleted task
        for (int i = choice - 1; i < numTasks - 1; ++i) {
            tasks[i] = tasks[i + 1];
        }
        numTasks--;

        cout << "Task deleted successfully!" << endl;
    }

    void deleteEvent() {
        if (numEvents == 0) {
            cout << "No events available to delete." << endl;
            return;
        }

        // Display all events to let the user choose which one to delete
        cout << "Available Events:" << endl;
        for (int i = 0; i < numEvents; ++i) {
            cout << i + 1 << ". " << events[i].title << endl;
        }

        int choice;
        cout << "Enter the index of the event you want to delete: ";
        cin >> choice;
        if (choice < 1 || choice > numEvents) {
            cout << "Invalid choice." << endl;
            return;
        }

        // Shift events to overwrite the deleted event
        for (int i = choice - 1; i < numEvents - 1; ++i) {
            events[i] = events[i + 1];
        }
        numEvents--;

        cout << "Event deleted successfully!" << endl;
    }

    void provideFeedback() {
        cout << "Enter your feedback: ";
        cin.ignore();
        getline(cin, feedback);
        cout << "Thank you for your feedback!" << endl;
    }

    void searchTasks() const {
        int searchOption;
        cout << "Choose search option:" << endl;
        cout << "1. Search by Title" << endl;
        cout << "2. Search by Date" << endl;
        cout << "3. Search by Time" << endl;
        cout << "Enter your choice: ";
        cin >> searchOption;

        switch (searchOption) {
            case 1:
                searchByTitle();
                break;
            case 2:
                searchByDate();
                break;
            case 3:
                searchByTime();
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }

    void searchByTitle() const {
        string query;
        cout << "Enter title query: ";
        cin >> query;

        bool found = false;
        for (int i = 0; i < numTasks; ++i) {
            if (tasks[i].getTitle() == query) {
                tasks[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No tasks found with the title containing \"" << query << "\"" << endl;
        }
    }

    void searchByDate() const {
        string query;
        cout << "Enter date query (YYYY-MM-DD): ";
        cin >> query;

        bool found = false;
        for (int i = 0; i < numTasks; ++i) {
            if (tasks[i].getDate() == query) {
                tasks[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No tasks found on date \"" << query << "\"" << endl;
        }
    }

    void searchByTime() const {
        string query;
        cout << "Enter time query (HH:MM): ";
        cin >> query;

        bool found = false;
        for (int i = 0; i < numTasks; ++i) {
            if (tasks[i].getTime() == query) {
                tasks[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No tasks found at time \"" << query << "\"" << endl;
        }
    }

    void trackDeadlines() const {
        if (numTasks == 0) {
            cout << "No tasks available." << endl;
            return;
        }

        // Create a copy of tasks array to avoid modifying the original array
        Task* sortedTasks = new Task[numTasks];
        for (int i = 0; i < numTasks; ++i) {
            sortedTasks[i] = tasks[i];
        }

        // Sort the tasks based on their deadlines (ascending order)
        for (int i = 0; i < numTasks - 1; ++i) {
            for (int j = 0; j < numTasks - i - 1; ++j) {
                if (sortedTasks[j].getDate() > sortedTasks[j + 1].getDate() ||
                    (sortedTasks[j].getDate() == sortedTasks[j + 1].getDate() && sortedTasks[j].getTime() > sortedTasks[j + 1].getTime())) {
                    swap(sortedTasks[j], sortedTasks[j + 1]);
                }
            }
        }

        // Display the sorted tasks
        cout << "Tasks sorted by deadlines (from nearest to farthest):" << endl;
        for (int i = 0; i < numTasks; ++i) {
            cout << "Task " << i + 1 << ":" << endl;
            sortedTasks[i].display();
            cout << endl;
        }

        // Deallocate memory for the sorted tasks array
        delete[] sortedTasks;
    }
};

int main() {
    TimeSchedulingSystem system;
    system.run();
    return 0;
}
