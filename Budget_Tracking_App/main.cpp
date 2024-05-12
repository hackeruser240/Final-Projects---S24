#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
public:
    string username, password, name, email;

    void registerUser() {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter email: ";
        cin >> email;
    }

    void login() {
        string enteredUsername, enteredPassword;
        cout << "Enter username: ";
        cin >> enteredUsername;
        cout << "Enter password: ";
        cin >> enteredPassword;
        if (enteredUsername == username && enteredPassword == password) {
            cout << "Login successful!" << endl;
        }
        else {
            cout << "Invalid username or password!" << endl;
        }
    }

    void passwordRecovery() {
        cout << "Enter new password: ";
        cin >> password;
    }

    void viewProfile() {
        cout << "Username: " << username << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
    }
};

class Budget {
public:
    double income, expense, balance;

    void setBudget(double income, double expense) {
        this->income = income;
        this->expense = expense;
        balance = income - expense;
    }

    void trackBudget() {
        cout << "Income: " << income << endl;
        cout << "Expense: " << expense << endl;
        cout << "Balance: " << balance << endl;
    }

    void editBudget(double newIncome, double newExpense) {
        income = newIncome;
        expense = newExpense;
        balance = income - expense;
    }
};

class Expense {
public:
    string description;
    double amount;

    void setExpense(string description, double amount) {
        this->description = description;
        this->amount = amount;
    }
};

class Income {
public:
    string description;
    double amount;

    void setIncome(string description, double amount) {
        this->description = description;
        this->amount = amount;
    }
};

class BudgetTrackingApp {
public:
    User user;
    Budget budget;
    vector<Expense> expenses;
    vector<Income> incomes;

    void budgetInput();
    void expenseInput();
    void incomeInput();
    void trackBudget();
    void expenseHistory();
    void incomeHistory();
    void budgetAlerts();
    void basicAnalytics();
    void passwordRecovery();
    void editBudget();
    void searchExpenses();
    void searchIncomes();
    void viewProfile();
    void displayMenu();
};

void BudgetTrackingApp::budgetInput() {
    double income, expense;
    cout << "Enter income: ";
    cin >> income;
    cout << "Enter expense: ";
    cin >> expense;
    budget.setBudget(income, expense);
}

void BudgetTrackingApp::expenseInput() {
    string description;
    double amount;
    cout << "Enter expense description: ";
    cin >> description;
    cout << "Enter expense amount: ";
    cin >> amount;
    Expense expense;
    expense.setExpense(description, amount);
    expenses.push_back(expense);
}

void BudgetTrackingApp::incomeInput() {
    string description;
    double amount;
    cout << "Enter income description: ";
    cin >> description;
    cout << "Enter income amount: ";
    cin >> amount;
    Income income;
    income.setIncome(description, amount);
    incomes.push_back(income);
}

void BudgetTrackingApp::trackBudget() {
    budget.trackBudget();
}

void BudgetTrackingApp::expenseHistory() {
    for (Expense expense : expenses) {
        cout << "Description: " << expense.description << endl;
        cout << "Amount: " << expense.amount << endl;
    }
}

void BudgetTrackingApp::incomeHistory() {
    for (Income income : incomes) {
        cout << "Description: " << income.description << endl;
        cout << "Amount: " << income.amount << endl;
    }
}

void BudgetTrackingApp::budgetAlerts() {
  
    budget.balance = budget.income - budget.expense;

    if (budget.balance < 0) {
        cout << "Budget alert: You have overspent!" << endl;
    }
}


void BudgetTrackingApp::basicAnalytics() {
    cout << "Total income: " << budget.income << endl;
    cout << "Total expense: " << budget.expense << endl;
    cout << "Total balance: " << budget.balance << endl;
}

void BudgetTrackingApp::passwordRecovery() {
    user.passwordRecovery();
}

void BudgetTrackingApp::editBudget() {
    double newIncome, newExpense;
    cout << "Enter new income: ";
    cin >> newIncome;
    cout << "Enter new expense: ";
    cin >> newExpense;
    budget.editBudget(newIncome, newExpense);
}

void BudgetTrackingApp::searchExpenses() {
    string description;
    cout << "Enter expense description to search: ";
    cin >> description;
    bool found = false;
    for (Expense expense : expenses) {
        if (expense.description == description) {
            cout << "Description: " << expense.description << endl;
            cout << "Amount: " << expense.amount << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No expense found with the given description." << endl;
    }
}

void BudgetTrackingApp::searchIncomes() {
    string description;
    cout << "Enter income description to search: ";
    cin >> description;
    bool found = false;
    for (Income income : incomes) {
        if (income.description == description) {
            cout << "Description: " << income.description << endl;
            cout << "Amount: " << income.amount << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No income found with the given description." << endl;
    }
}

void BudgetTrackingApp::viewProfile() {
    user.viewProfile();
}

void BudgetTrackingApp::displayMenu() {
    cout << "--------------------------" << endl;
    cout << "       MENU OPTIONS       " << endl;
    cout << "--------------------------" << endl;
    cout << "| 1. Register User       |" << endl;
    cout << "| 2. Login               |" << endl;
    cout << "| 3. Budget Input        |" << endl;
    cout << "| 4. Expense Input       |" << endl;
    cout << "| 5. Income Input        |" << endl;
    cout << "| 6. Track Budget        |" << endl;
    cout << "| 7. Expense History     |" << endl;
    cout << "| 8. Income History      |" << endl;
    cout << "| 9. Budget Alerts       |" << endl;
    cout << "| 10. Basic Analytics    |" << endl;
    cout << "| 11. Password Recovery  |" << endl;
    cout << "| 12. Edit Budget        |" << endl;
    cout << "| 13. Search Expenses    |" << endl;
    cout << "| 14. Search Incomes     |" << endl;
    cout << "| 15. View Profile       |" << endl;
    cout << "| 16. Exit               |" << endl;
    cout << "--------------------------" << endl;
    cout << "Enter your choice: ";
}

int main() {
    BudgetTrackingApp app;

    cout << "--------------------------" << endl;
    cout << "  Welcome to Budget App!  " << endl;
    cout << "--------------------------" << endl;

    while (true) {
        app.displayMenu();
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "--------------------------" << endl;\
                cout << "|   Register User Menu   |" << endl;
                cout << "--------------------------" << endl;
                app.user.registerUser();
                break;
            case 2:
                cout << "--------------------------" << endl;
                cout << "|       Login Menu       |" << endl;
                cout << "--------------------------" << endl;
                app.user.login();
                break;
            case 3:
                cout << "--------------------------" << endl;
                cout << "|    Budget Input Menu   |" << endl;
                cout << "--------------------------" << endl;
                app.budgetInput();
                break;
            case 4:
                cout << "--------------------------" << endl;
                cout << "|   Expense Input Menu   |" << endl;
                cout << "--------------------------" << endl;
                app.expenseInput();
                break;
            case 5:
                cout << "--------------------------" << endl;
                cout << "|    Income Input Menu   |" << endl;
                cout << "--------------------------" << endl;
                app.incomeInput();
                break;
            case 6:
                cout << "--------------------------" << endl;
                cout << "|    Track Budget Menu   |" << endl;
                cout << "--------------------------" << endl;
                app.trackBudget();
                break;
            case 7:
                cout << "--------------------------" << endl;
                cout << "|   Expense History Menu |" << endl;
                cout << "--------------------------" << endl;
                app.expenseHistory();
                break;
            case 8:
                cout << "--------------------------" << endl;
                cout << "|    Income History Menu |" << endl;
                cout << "--------------------------" << endl;
                app.incomeHistory();
                break;
            case 9:
                cout << "--------------------------" << endl;
                cout << "|    Budget Alerts Menu  |" << endl;
                cout << "--------------------------" << endl;
                app.budgetAlerts();
                break;
            case 10:
                cout << "--------------------------" << endl;
                cout << "|  Basic Analytics Menu  |" << endl;
                cout << "--------------------------" << endl;
                app.basicAnalytics();
                break;
            case 11:
                cout << "--------------------------" << endl;
                cout << "| Password Recovery Menu |" << endl;
                cout << "--------------------------" << endl;
                app.passwordRecovery();
                break;
            case 12:
                cout << "--------------------------" << endl;
                cout << "|    Edit Budget Menu    |" << endl;
                cout << "--------------------------" << endl;
                app.editBudget();
                break;
            case 13:
                cout << "--------------------------" << endl;
                cout << "|  Search Expenses Menu  |" << endl;
                cout << "--------------------------" << endl;
                app.searchExpenses();
                break;
            case 14:
                cout << "--------------------------" << endl;
                cout << "|   Search Incomes Menu  |" << endl;
                cout << "--------------------------" << endl;
                app.searchIncomes();
                break;
            case 15:
                cout << "--------------------------" << endl;
                cout << "|    View Profile Menu   |" << endl;
                cout << "--------------------------" << endl;
                app.viewProfile();
                break;
            case 16:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}
