#include <iostream>
#include <string>
using namespace std;

class PatientManagement {
protected:
    struct Patient {
        int ID;
        string Name;
        string MedicalHistory;
        string MobileNumber;
        Patient* next;
    };

    Patient* head;

public:
    PatientManagement() {
        head = nullptr;
    }

    bool isPatientOld(int id) {
        Patient* temp = head;
        while (temp != nullptr) {
            if (temp->ID == id) {
                return true; // Patient exists
            }
            temp = temp->next;
        }
        return false; // New patient
    }

    void addPatient(int id, string name, string medicalHistory,std::string mobileNumber) {
        if (isPatientOld(id)) {
            cout << "Patient already exists!\n";
            return;
        }

        Patient* newPatient = new Patient{id, name, medicalHistory, mobileNumber, nullptr};
        if (head == nullptr) {
            head = newPatient;
        } else {
            Patient* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newPatient;
        }
        cout << "Patient added successfully!\n";
    }

    void searchPatient(int id) {
        Patient* temp = head;
        while (temp != nullptr) {
            if (temp->ID == id) {
                cout << "\nPatient Found:";
                cout << "\nID: " << temp->ID;
                cout << "\nName: " << temp->Name;
                cout << "\nMobile Number: " << temp->MobileNumber;
                cout << "\nMedical History: " << temp->MedicalHistory << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "\nPatient not found!\n";
    }
};

class ManageRooms : public PatientManagement {
private:
    struct Room {
        int roomNumber;
        bool isAvailable;
        int allocatedPatientID;
        Room* next;
    };

    Room* roomHead;

public:
    ManageRooms() {
        roomHead = nullptr;
    }

    void addRoom(int roomNumber) {
        Room* newRoom = new Room{roomNumber, true, -1, roomHead};
        roomHead = newRoom;
        cout << "Room added successfully!\n";
    }

    void allocateRoom(int roomNumber, int patientID) {
        if (!isPatientOld(patientID)) {
            cout << "Patient not registered! Please register the patient first.\n";
            return;
        }

        Room* temp = roomHead;
        while (temp != nullptr) {
            if (temp->roomNumber == roomNumber && temp->isAvailable) {
                temp->isAvailable = false;
                temp->allocatedPatientID = patientID;
                cout << "Room allocated successfully!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Room allocation failed! Room is either occupied or does not exist.\n";
    }
};

class ScheduleAppointment : public PatientManagement {
public:
    void bookAppointment(int patientID, string date, string time, string doctor) {
        if (!isPatientOld(patientID)) {
            cout << "Patient not registered! Please register the patient first.\n";
            return;
        }
        cout << "Appointment booked for Patient ID " << patientID << " on " << date << " at " << time << " with Dr. " << doctor << ".\n";
    }
};

class GenerateBill : public PatientManagement {
public:
    void createBill(int patientID, double amount) {
        if (!isPatientOld(patientID)) {
            cout << "Patient not registered! Please register the patient first.\n";
            return;
        }
        cout << "Bill of $" << amount << " generated for Patient ID " << patientID << ".\n";
    }
};

int main() {
    PatientManagement pm;
    ManageRooms mr;
    ScheduleAppointment sa;
    GenerateBill gb;

    int choice;
    do {
        cout << "\n1. Manage Patients\n2. Schedule Appointment\n3. Manage Staff\n4. Manage Rooms\n5. Generate Bill\n6. Search Patient\n7. Generate Report\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string mobile;
            string name, medicalHistory;
            cout << "Enter Patient ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Medical History: ";
            getline(cin, medicalHistory);
            cout << "Enter Mobile Number: ";
            cin >> mobile;
            pm.addPatient(id, name, medicalHistory, mobile);
            break;
        }
        case 2: {
            int id;
            string date, time, doctor;
            cout << "Enter Patient ID: ";
            cin >> id;
            cout << "Enter Date (DD/MM/YYYY): ";
            cin >> date;
            cout << "Enter Time (HH:MM): ";
            cin >> time;
            cout << "Enter Doctor Name: ";
            cin.ignore();
            getline(cin, doctor);
            sa.bookAppointment(id, date, time, doctor);
            break;
        }
        case 4: {
            int roomNumber, patientID;
            cout << "Enter Room Number: ";
            cin >> roomNumber;
            mr.addRoom(roomNumber);
            cout << "Enter Room Number to Allocate: ";
            cin >> roomNumber;
            cout << "Enter Patient ID: ";
            cin >> patientID;
            mr.allocateRoom(roomNumber, patientID);
            break;
        }
        case 5: {
            int id;
            double amount;
            cout << "Enter Patient ID: ";
            cin >> id;
            cout << "Enter Bill Amount: ";
            cin >> amount;
            gb.createBill(id, amount);
            break;
        }
        case 6: {
            int id;
            cout << "Enter Patient ID to Search: ";
            cin >> id;
            pm.searchPatient(id);
            break;
        }
        case 0:
            cout << "Exiting program!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
