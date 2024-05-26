#include<iostream>
#include<fstream>
#include<string>

using namespace std;



struct Date
{
	int day;
	int month;
	int year;


	friend ostream& operator<<(ostream& cout, Date& d)
	{
		cout << d.day << "/ " << d.month << " /" << d.year;
		return cout;
	}
};


class Task
{
private:

	string title;
	string description;
	Date dueDate;
	bool IsCompleted;

public:

	Task();
	Task(string title, string desc);
	void createTask(string title, string desc, Date dueDate);
	void UpdateTask();
	void updateTitle();
	void updateDescription();
	void updateDueDate();
	void markAsCompleted();
	void ListTask();
};
#include<fstream>

Task::Task()
{
	this->title = "";
	this->description = "";
	this->dueDate = { 0,0,0 };
	this->IsCompleted = false;
}
Task::Task(string title, string desc)
{
	this->title = title;
	this->description = desc;
	this->dueDate = { 0,0,0 };
	this->IsCompleted = false;
}
void Task::createTask(string title, string desc, Date dueDate)
{
	this->title = title;
	this->description = desc;
	this->dueDate = dueDate;
	this->IsCompleted = false;
}
void Task::UpdateTask()
{
	cout << "------------What do You Want To Update----------\n";
	cout << "1) Update Title.\n";
	cout << "2) Update Description.\n";
	cout << "3) Update Due Date.\n";
	int choice;
	cin >> choice;
	cin.ignore();
	switch (choice)
	{
	case 1:
		updateTitle();
		break;
	case 2:
		updateDescription();
		break;
	case 3:
		updateDueDate();
		break;
	}
}




void Task::updateTitle()
{
	string tempTitle;
	cout << "Enter New Title For Your Task \n";
	getline(cin, tempTitle);
	this->title = tempTitle;
}
void Task::updateDescription()
{
	string tempDesc;
	cout << "Enter New Description For Your Task \n";
	getline(cin, tempDesc);
	this->title = tempDesc;
}


void Task::updateDueDate()
{
	Date tempDate;
	cout << "Enter New Due Date For Your Task (dd / mm / yyyy)\n";
	char d;
	cin >> tempDate.day >> d >> tempDate.month >> d >> tempDate.year;
	this->dueDate = tempDate;
}
void Task::markAsCompleted()
{
	if (!IsCompleted)
	{
		this->IsCompleted = true;
	}
}

void Task::ListTask()
{
	cout << "Title :\t-----------" << this->title << "---------\n\n";
	cout << "Description :\t" << this->description << "\n";
	cout << "Due Date :   " << this->dueDate << "\n";
	cout << "Completion Status :   ";
	{
		if (IsCompleted)
		{
			cout << "Completed\n";
		}
		else if (!IsCompleted)
		{
			cout << "Pending\n";
		}
	}
}



class User
{
private:
	string name;
	string password;
	Task* tasks;
	int taskSize;

public:
	bool IsLoggedIn;
	User();
	User(string name);
	User(string name, string password);
	string& getName();
	string& getPassword();
	void ResetPass(string newpassword);
	void DeleteTask(int index);
	void AddTask(Task& task);
	void EditTask(int index);
	void ViewProfile();
	//bool Login(string n, string p);
	bool CreateAccount(ofstream& wrt);
	void handleUser();
	bool LogOut();
};







User::User()
{
	this->name = "";
	this->password = "";
	this->taskSize = 0;
	this->tasks = new Task[taskSize];
	bool IsLoggedIn = false;
}
User::User(string name)
{
	this->name = name;
	this->password = "";
	this->taskSize = 0;
	this->tasks = new Task[taskSize];
	bool IsLoggedIn = false;
}
User::User(string name, string password)
{
	this->name = name;
	this->password = password;
	this->taskSize = 0;
	this->tasks = new Task[taskSize];
	bool IsLoggedIn = false;
}
string& User::getName()
{
	return this->name;
}
string& User::getPassword()
{
	return this->password;
}
void User::ResetPass(string newpassword)
{

}
void User::DeleteTask(int index)
{
	Task* temp = new Task[this->taskSize - 1];
	int ind = 0;
	for (int i = 0; i < this->taskSize; i++)
	{
		if (i != index)
		{
			temp[ind] = tasks[i];
			ind++;
		}
	}
	this->taskSize--;
	delete[]tasks;
	tasks = temp;
}



void User::AddTask(Task& task)
{
	Task* temp = new Task[this->taskSize + 1];

	for (int i = 0; i < this->taskSize; i++)
	{
		temp[i] = tasks[i];
	}
	temp[this->taskSize] = task;
	this->taskSize++;
	delete[]tasks;
	tasks = temp;
}




void User::EditTask(int index)
{
	for (int i = 0; i < this->taskSize; i++)
	{
		if (i == index)
		{
			tasks[i].UpdateTask();
			break;
		}
	}
}
void User::ViewProfile()
{
	cout << "Name :\t\t" << this->name << "\n";
	cout << "Number Of Tasks :\t" << this->taskSize << "\n";
	for (int i = 0; i < this->taskSize; i++)
	{
		this->tasks[i].ListTask();
		cout << "\n\n";
	}
}




void User::handleUser()
{
	cout << "------------What do You Want To Do----------\n";
	cout << "1) Update Task.\n";
	cout << "2) Delete Task.\n";
	cout << "3) Add A New Task.\n";
	cout << "4) List All Tasks.\n";
	int choice;
	cin >> choice;
	cin.ignore();
	if (choice == 1)
	{
		cout << "Enter Number Of Task You Want To Update\n";
		cin >> choice;
		EditTask(choice);
	}
	else if (choice == 2)
	{

		cout << "Enter Number Of Task You Want To Delete\n";
		cin >> choice;
		DeleteTask(choice);
	}
	else if (choice == 3)
	{

		string temptitle;
		string tempdesc;
		Date tempdueDate;
		cout << "Enter Title of Your Task\n";
		getline(cin, temptitle);
		cout << "Enter Description of Your Task\n";
		getline(cin, tempdesc);
		cout << "Enter Due Date of Your Task (dd/mm/yyyy)\n";
		cin >> tempdueDate.day >> tempdueDate.month >> tempdueDate.year;
		Task temp;
		temp.createTask(temptitle, tempdesc, tempdueDate);
		AddTask(temp);
	}
	else if (choice == 4)
	{
		ViewProfile();
	}
}





bool User::CreateAccount(ofstream& wrt)
{
	cout << "Enter Name\n";
	getline(cin, this->name);
	cout << "Enter Password\n";
	getline(cin, this->password);
	wrt << this->name << " ";
	wrt << this->password << "\n";
	return true;
}






bool User::LogOut()
{
	IsLoggedIn = false;
	return true;
}







class TaskManager
{
private:
	User* users;
	int sizeofUsers;
public:

	TaskManager();
	TaskManager(User* users, int size);
	int getUserSize();
	void setSizeOfUsers(int& size);
	void AddUser(User& user);
	void DeleteUser(int index);
	void HandleUserTasks();
	void ViewAllTasks();
	void ListUsers();
	bool signUp(ofstream& wrt);
	bool Login(ifstream& rdr);
	bool LogOut();
};







TaskManager::TaskManager()
{
	this->users = nullptr;
	this->sizeofUsers = 0;
}
TaskManager::TaskManager(User* users, int size)
{
	this->sizeofUsers = size;
	this->users = new User[size];
	for (int i = 0; i < size; i++)
	{
		this->users[i] = users[i];
	}
}
void TaskManager::AddUser(User& user)
{
	User* temp = new User[this->sizeofUsers + 1];

	for (int i = 0; i < this->sizeofUsers; i++)
	{
		temp[i] = this->users[i];
	}
	temp[this->sizeofUsers] = user;
	this->sizeofUsers++;
	delete[]users;
	this->users = temp;
}
void TaskManager::DeleteUser(int index)
{
	User* temp = new User[this->sizeofUsers - 1];
	int ind = 0;
	for (int i = 0; i < this->sizeofUsers; i++)
	{
		if (i != index)
		{
			temp[ind] = this->users[i];
			ind++;
		}
	}
	this->sizeofUsers--;
	delete[]users;
	this->users = temp;
}


void TaskManager::HandleUserTasks()
{
	for (int i = 0; i < sizeofUsers; i++)
	{
		if (users[i].IsLoggedIn)
		{
			users[i].handleUser();
		}
	}
}


void TaskManager::ViewAllTasks()
{
	for (int i = 0; i < sizeofUsers; i++)
	{
		if (users[i].IsLoggedIn)
		{
			users[i].ViewProfile();
		}
	}
}


void TaskManager::ListUsers()
{
	for (int i = 0; i < sizeofUsers; i++)
	{
		users[i].ViewProfile();
	}
}



bool TaskManager::LogOut()
{
	for (int i = 0; i < sizeofUsers; i++)
	{
		if (users[i].IsLoggedIn)
		{
			bool check = users[i].LogOut();
			return check;
		}
	}
	return false;
}


bool TaskManager::signUp(ofstream& wrt)
{

	User temp;
	temp.CreateAccount(wrt);
	AddUser(temp);
	return true;
}



int TaskManager::getUserSize()
{
	return sizeofUsers;
}



void TaskManager::setSizeOfUsers(int& size)
{
	this->sizeofUsers = size;
}


bool TaskManager::Login(ifstream& rdr)
{
	cout << "Enter Name\n";
	string tempname;
	getline(cin, tempname);
	string temppass;
	cout << "Enter Password\n";
	getline(cin, temppass);

	while (rdr)
	{
		for (int i = 0; i < sizeofUsers; i++)
		{
			if (strcmp(tempname.c_str(), users[i].getName().c_str()) == 0 && strcmp(temppass.c_str(), users[i].getPassword().c_str()) == 0)
			{
				users[i].IsLoggedIn = true;
				return true;
			}
		}

	}
	return false;

}







int main()
{
	ofstream wrt("data.txt", ios::app);
	ifstream rdr("data.txt");


	int n;

	cout << "1) Sign Up\n";
	cout << "2) Login\n";
	cout << "3) LogOut\n";
	cout << "4) Handle Profile\n";
	cout << "5) List Users\n";
	cout << "0) To Close Task Manager\n";
	cin >> n;
	cin.ignore();
	TaskManager T;
	while (n != 0)
	{
		if (n == 1)
		{
			if (T.signUp(wrt))
			{
				cout << "Sign up successfully\n";
			}
			else
			{
				cout << "Error Signing in\n";
			}
		}
		else if (n == 2)
		{
			if (T.Login(rdr))
			{
				cout << "Login successfully\n";
			}
			else
			{
				cout << "Error Loging in\n";
			}
		}
		else if (n == 3)
		{
			if (T.LogOut())
			{
				cout << "Loged Out successfully\n";
			}
			else
			{
				cout << "Error while Loging out\n";
			}
		}
		else if (n == 4)
		{
			T.HandleUserTasks();
		}
		else if (n == 5)
		{
			T.ListUsers();
		}
		cout << "1) Sign Up\n";
		cout << "2) Login\n";
		cout << "3) LogOut\n";
		cout << "4) Handle Profile\n";
		cout << "5) List Users\n";
		cout << "0) To Close Task Manager\n";
		cin >> n;
		cin.ignore();
	}


	return 0;
}
