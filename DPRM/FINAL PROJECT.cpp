#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class UserAuthenticator {
private:
    map<string, string> users; // username -> password mapping
    map<string, string> userRoles; // username -> role mapping

public:
    // Constructor
    UserAuthenticator() {
        // Add some sample users and their passwords
        users["user1"] = "password1";
        users["user2"] = "password2";

        // Assign roles to users
        userRoles["user1"] = "admin";
        userRoles["user2"] = "user";
    }

    // Method to authenticate user
    bool authenticateUser(const string& username, const string& password) {
        map<string, string>::iterator it = users.find(username);
        if (it != users.end() && it->second == password) {
            cout << "User authenticated successfully!" << endl;
            return true;
        }
        cout << "Invalid username or password." << endl;
        return false;
    }

    // Method to check authorization and return role
    string authorizeUser(const string& username) {
        map<string, string>::iterator it = userRoles.find(username);
        if (it != userRoles.end()) {
            return it->second;
        }
        return "";
    }

    // Method to add a new user
    void addUser(const string& username, const string& password, const string& role) {
        users[username] = password;
        userRoles[username] = role;
        cout << "User added successfully!" << endl;
    }
};

// Class for patient registration
class PatientRegistration {
private:
    map<string, pair<string, string>> patientDetails; // name -> (contact, date of birth) mapping

public:
    // Method to register a new patient
    void registerPatient(const string& name, const string& contact, const string& dob) {
        patientDetails[name] = make_pair(contact, dob);
        cout << "Patient " << name << " registered successfully!" << endl;
    }

    // Method to display patient details
    void displayPatientDetails(const string& name) {
        map<string, pair<string, string>>::iterator it = patientDetails.find(name);
        if (it != patientDetails.end()) {
            cout << "Name: " << it->first << endl;
            cout << "Contact: " << it->second.first << endl;
            cout << "Date of Birth: " << it->second.second << endl;
        } else {
            cout << "Patient not found." << endl;
        }
    }
};

// Class for doctor registration
class DoctorRegistration {
private:
    map<string, pair<string, string>> doctorDetails; // name -> (contact, specialization) mapping

public:
    // Method to register a new doctor
    void registerDoctor(const string& name, const string& contact, const string& specialization) {
        doctorDetails[name] = make_pair(contact, specialization);
        cout << "Doctor " << name << " registered successfully!" << endl;
    }

    // Method to display doctor details
    void displayDoctorDetails(const string& name) {
        map<string, pair<string, string>>::iterator it = doctorDetails.find(name);
        if (it != doctorDetails.end()) {
            cout << "Name: " << it->first << endl;
            cout << "Contact: " << it->second.first << endl;
            cout << "Specialization: " << it->second.second << endl;
        } else {
            cout << "Doctor not found." << endl;
        }
    }
};

// Class for patient history
class PatientHistory {
private:
    map<string, vector<string>> patientHistory; // name -> list of medical history entries

public:
    // Method to add patient history
    void addPatientHistory(const string& name, const string& history) {
        patientHistory[name].push_back(history);
        cout << "Patient history added successfully!" << endl;
    }

    // Method to display patient history
    void displayPatientHistory(const string& name) {
        map<string, vector<string>>::iterator it = patientHistory.find(name);
        if (it != patientHistory.end()) {
            cout << "Medical History of " << name << ":" << endl;
            for (const string& entry : it->second) {
                cout << "- " << entry << endl;
            }
        } else {
            cout << "Patient not found." << endl;
        }
    }
};

// Class for doctor history
class DoctorHistory {
private:
    map<string, vector<string>> doctorHistory; // name -> list of doctor history entries

public:
    // Method to add doctor history
    void addDoctorHistory(const string& name, const string& history) {
        doctorHistory[name].push_back(history);
        cout << "Doctor history added successfully!" << endl;
    }

    // Method to display doctor history
    void displayDoctorHistory(const string& name) {
        map<string, vector<string>>::iterator it = doctorHistory.find(name);
        if (it != doctorHistory.end()) {
            cout << "History of " << name << ":" << endl;
            for (const string& entry : it->second) {
                cout << "- " << entry << endl;
            }
        } else {
            cout << "Doctor not found." << endl;
        }
    }
};

// Class for appointment scheduling
class AppointmentScheduler {
private:
    map<string, string> appointments; // date -> patient name mapping

public:
    // Method to schedule an appointment
    void scheduleAppointment(const string& date, const string& patientName) {
        appointments[date] = patientName;
        cout << "Appointment scheduled successfully!" << endl;
    }

    // Method to cancel an appointment
    void cancelAppointment(const string& date) {
        map<string, string>::iterator it = appointments.find(date);
        if (it != appointments.end()) {
            appointments.erase(it);
            cout << "Appointment canceled successfully!" << endl;
        } else {
            cout << "No appointment found on that date." << endl;
        }
    }

    // Method to display scheduled appointments
    void displayAppointments() {
        if (appointments.empty()) {
            cout << "No appointments scheduled." << endl;
        } else {
            cout << "Scheduled Appointments:" << endl;
            for (const auto& appointment : appointments) {
                cout << "Date: " << appointment.first << ", Patient: " << appointment.second << endl;
            }
        }
    }
};

// Class for updating patient records
class RecordUpdater {
private:
    map<string, vector<string>> patientRecords; // patient name -> list of diagnoses and treatments

public:
    // Method to add a diagnosis or treatment to a patient's record
    void updatePatientRecord(const string& patientName, const string& update) {
        patientRecords[patientName].push_back(update);
        cout << "Patient record updated successfully!" << endl;
    }

    // Method to display patient's record
    void displayPatientRecord(const string& patientName) {
        map<string, vector<string>>::iterator it = patientRecords.find(patientName);
        if (it != patientRecords.end()) {
            cout << "Record of " << patientName << ":" << endl;
            for (const string& entry : it->second) {
                cout << "- " << entry << endl;
            }
        } else {
            cout << "Patient not found." << endl;
        }
    }
};

// Class for managing medical history
class MedicalHistory {
private:
    map<string, vector<string>> medicalHistory; // patient name -> list of medical history entries

public:
    // Method to add a medical history entry
    void addMedicalHistory(const string& patientName, const string& entry) {
        medicalHistory[patientName].push_back(entry);
        cout << "Medical history entry added successfully!" << endl;
    }

    // Method to display medical history for a patient
    void displayMedicalHistory(const string& patientName) {
        map<string, vector<string>>::iterator it = medicalHistory.find(patientName);
        if (it != medicalHistory.end()) {
            cout << "Medical History of " << patientName << ":" << endl;
            for (const string& entry : it->second) {
                cout << "- " << entry << endl;
            }
        } else {
            cout << "Medical history for " << patientName << " not found." << endl;
        }
    }
};

// Class for managing invoices
class InvoiceManager {
private:
    map<string, double> invoices; // patient name -> invoice amount mapping

public:
    // Method to generate an invoice for a patient
    void generateInvoice(const string& patientName, double amount) {
        invoices[patientName] += amount;
        cout << "Invoice generated successfully!" << endl;
    }

    // Method to display invoices
    void displayInvoices() {
        if (invoices.empty()) {
            cout << "No invoices found." << endl;
        } else {
            cout << "Invoices:" << endl;
            for (const auto& invoice : invoices) {
                cout << "Patient: " << invoice.first << ", Amount: $" << invoice.second << endl;
            }
        }
    }
};

// Class for managing medication
class MedicationManager {
private:
    map<string, vector<string>> medications; // patient name -> list of medications

public:
    // Method to add medication for a patient
    void addMedication(const string& patientName, const string& medication) {
        medications[patientName].push_back(medication);
        cout << "Medication added successfully!" << endl;
    }

    // Method to display medication for a patient
    void displayMedication(const string& patientName) {
        map<string, vector<string>>::iterator it = medications.find(patientName);
        if (it != medications.end()) {
            cout << "Medication for " << patientName << ":" << endl;
            for (const string& med : it->second) {
                cout << "- " << med << endl;
            }
        } else {
            cout << "Medication for " << patientName << " not found." << endl;
        }
    }
};

// Class for managing lab test results
class LabTestManager {
private:
    map<string, vector<string>> labTestResults; // patient name -> list of lab test results

public:
    // Method to add lab test results for a patient
    void addLabTestResults(const string& patientName, const string& results) {
        labTestResults[patientName].push_back(results);
        cout << "Lab test results added successfully!" << endl;
    }

    // Method to display lab test results for a patient
    void displayLabTestResults(const string& patientName) {
        map<string, vector<string>>::iterator it = labTestResults.find(patientName);
        if (it != labTestResults.end()) {
            cout << "Lab Test Results for " << patientName << ":" << endl;
            for (const string& result : it->second) {
                cout << "- " << result << endl;
            }
        } else {
            cout << "Lab test results for " << patientName << " not found." << endl;
        }
    }
};

// Class for searching patient records
class PatientRecordSearch {
private:
    map<string, pair<string, string>> patientDetails; // name -> (contact, date of birth) mapping

public:
    // Method to search patient record by name
    void searchByName(const string& name) {
        map<string, pair<string, string>>::iterator it = patientDetails.find(name);
        if (it != patientDetails.end()) {
            cout << "Patient Found:" << endl;
            cout << "Name: " << it->first << endl;
            cout << "Contact: " << it->second.first << endl;
            cout << "Date of Birth: " << it->second.second << endl;
        } else {
            cout << "Patient not found." << endl;
        }
    }

    // Method to search patient record by date of birth
    void searchByDOB(const string& dob) {
        for (const auto& patient : patientDetails) {
            if (patient.second.second == dob) {
                cout << "Patient Found:" << endl;
                cout << "Name: " << patient.first << endl;
                cout << "Contact: " << patient.second.first << endl;
                cout << "Date of Birth: " << patient.second.second << endl;
                return;
            }
        }
        cout << "Patient not found." << endl;
    }

    // Method to add patient details
    void addPatientDetails(const string& name, const string& contact, const string& dob) {
        patientDetails[name] = make_pair(contact, dob);
        cout << "Patient details added successfully!" << endl;
    }
};

int main() {
    UserAuthenticator authenticator;
    PatientRegistration patientRegistration;
    DoctorRegistration doctorRegistration;
    PatientHistory patientHistory;
    DoctorHistory doctorHistory;
    AppointmentScheduler appointmentScheduler;
    RecordUpdater recordUpdater;
    MedicalHistory medicalHistory;
    InvoiceManager invoiceManager;
    MedicationManager medicationManager;
    LabTestManager labTestManager;
    PatientRecordSearch recordSearch;

    int choice;
    string username, password, role;
    string name, contact, dob;
    string history, date, patientName, update;
    double amount;
    string medication, testResults;

    bool continueLoop = true;
    while (continueLoop) {
        cout << "Choose an option:" << endl;
        cout << "1. Add user" << endl;
        cout << "2. Login" << endl;
        cout << "3. Patient Registration" << endl;
        cout << "4. Doctor Registration" << endl;
        cout << "5. Add Patient History" << endl;
        cout << "6. Display Patient History" << endl;
        cout << "7. Add Doctor History" << endl;
        cout << "8. Display Doctor History" << endl;
        cout << "9. Schedule Appointment" << endl;
        cout << "10. Cancel Appointment" << endl;
        cout << "11. Display Scheduled Appointments" << endl;
        cout << "12. Update Patient Record" << endl;
        cout << "13. Display Patient Record" << endl;
        cout << "14. Add Medical History" << endl;
        cout << "15. Display Medical History" << endl;
        cout << "16. Generate Invoice" << endl;
        cout << "17. Display Invoices" << endl;
        cout << "18. Add Medication" << endl;
        cout << "19. Display Medication" << endl;
        cout << "20. Add Lab Test Results" << endl;
        cout << "21. Display Lab Test Results" << endl;
        cout << "22. Search Patient Record by Name" << endl;
        cout << "23. Search Patient Record by Date of Birth" << endl;
        cout << "24. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                // Prompt for username
                cout << "Enter username: ";
                cin >> username;

                // Prompt for password
                cout << "Enter password: ";
                cin >> password;

                // Prompt for role
                cout << "Enter role (Doctor/Patient): ";
                cin >> role;

                // Add the user
                authenticator.addUser(username, password, role);
                break;

            case 2:
                // Prompt for username
                cout << "Enter username: ";
                cin >> username;

                // Prompt for password
                cout << "Enter password: ";
                cin >> password;

                // Authenticate the user
                if(authenticator.authenticateUser(username, password)) {
                    // Authorize the user
                    string userRole = authenticator.authorizeUser(username);
                    if (!userRole.empty()) {
                        cout << "User role: " << userRole << endl;
                    } else {
                        cout << "Failed to authorize user." << endl;
                    }
                }
                break;

            case 3:
                // Prompt for patient details
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter contact information: ";
                cin >> contact;
                cout << "Enter date of birth (DD/MM/YYYY): ";
                cin >> dob;

                // Register the patient
                patientRegistration.registerPatient(name, contact, dob);
                break;

            case 4:
                // Prompt for doctor details
                cout << "Enter doctor name: ";
                cin >> name;
                cout << "Enter contact information: ";
                cin >> contact;
                cout << "Enter specialization: ";
                cin >> dob;

                // Register the doctor
                doctorRegistration.registerDoctor(name, contact, dob);
                break;

            case 5:
                // Prompt for patient name and history
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter patient history: ";
                cin.ignore(); // Clear buffer
                getline(cin, history);

                // Add patient history
                patientHistory.addPatientHistory(name, history);
                break;

            case 6:
                // Prompt for patient name and display history
                cout << "Enter patient name: ";
                cin >> name;

                // Display patient history
                patientHistory.displayPatientHistory(name);
                break;

            case 7:
                // Prompt for doctor name and history
                cout << "Enter doctor name: ";
                cin >> name;
                cout << "Enter doctor history: ";
                cin.ignore(); // Clear buffer
                getline(cin, history);

                // Add doctor history
                doctorHistory.addDoctorHistory(name, history);
                break;

            case 8:
                // Prompt for doctor name and display history
                cout << "Enter doctor name: ";
                cin >> name;

                // Display doctor history
                doctorHistory.displayDoctorHistory(name);
                break;

            case 9:
                // Prompt for appointment details
                cout << "Enter appointment date (YYYY-MM-DD): ";
                cin >> date;
                cout << "Enter patient name: ";
                cin >> patientName;

                // Schedule the appointment
                appointmentScheduler.scheduleAppointment(date, patientName);
                break;

            case 10:
                // Prompt for appointment date to cancel
                cout << "Enter appointment date to cancel (YYYY-MM-DD): ";
                cin >> date;

                // Cancel the appointment
                appointmentScheduler.cancelAppointment(date);
                break;

            case 11:
                // Display scheduled appointments
                appointmentScheduler.displayAppointments();
                break;

            case 12:
                // Prompt for patient name and update
                cout << "Enter patient name: ";
                cin >> patientName;
                cout << "Enter diagnosis or treatment to add: ";
                cin.ignore(); // Clear buffer
                getline(cin, update);

                // Update patient record
                recordUpdater.updatePatientRecord(patientName, update);
                break;

            case 13:
                // Prompt for patient name and display record
                cout << "Enter patient name: ";
                cin >> patientName;

                // Display patient record
                recordUpdater.displayPatientRecord(patientName);
                break;

            case 14:
                // Prompt for patient name and medical history entry
                cout << "Enter patient name: ";
                cin >> patientName;
                cout << "Enter medical history entry: ";
                cin.ignore(); // Clear buffer
                getline(cin, history);

                // Add medical history entry
                medicalHistory.addMedicalHistory(patientName, history);
                break;

            case 15:
                // Prompt for patient name and display medical history
                cout << "Enter patient name: ";
                cin >> patientName;

                // Display medical history
                medicalHistory.displayMedicalHistory(patientName);
                break;

            case 16:
                // Prompt for patient name and amount
                cout << "Enter patient name: ";
                cin >> patientName;
                cout << "Enter invoice amount: $";
                cin >> amount;

                // Generate invoice
                invoiceManager.generateInvoice(patientName, amount);
                break;

            case 17:
                // Display invoices
                invoiceManager.displayInvoices();
                break;

            case 18:
                // Prompt for patient name and medication
                cout << "Enter patient name: ";
                cin >> patientName;
                cout << "Enter medication: ";
                cin.ignore(); // Clear buffer
                getline(cin, medication);

                // Add medication
                medicationManager.addMedication(patientName, medication);
                break;

            case 19:
                // Prompt for patient name and display medication
                cout << "Enter patient name: ";
                cin >> patientName;

                // Display medication
                medicationManager.displayMedication(patientName);
                break;

            case 20:
                // Prompt for patient name and lab test results
                cout << "Enter patient name: ";
                cin >> patientName;
                cout << "Enter lab test results: ";
                cin.ignore(); // Clear buffer
                getline(cin, testResults);

                // Add lab test results
                labTestManager.addLabTestResults(patientName, testResults);
                break;

            case 21:
                // Prompt for patient name and display lab test results
                cout << "Enter patient name: ";
                cin >> patientName;

                // Display lab test results
                labTestManager.displayLabTestResults(patientName);
                break;

            case 22:
                // Prompt for patient name to search
                cout << "Enter patient name to search: ";
                cin >> name;

                // Search patient record by name
                recordSearch.searchByName(name);
                break;

            case 23:
                // Prompt for date of birth to search
                cout << "Enter date of birth to search (DD/MM/YYYY): ";
                cin >> dob;

                // Search patient record by date of birth
                recordSearch.searchByDOB(dob);
                break;

            case 24:
                continueLoop = false;
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 24." << endl;
                break;
        }
    }

    cout << "Exiting..." << endl;

    return 0;
}
