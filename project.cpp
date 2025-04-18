#include <iostream>
#include <string>
using namespace std;

// Class for managing patients
class PatientManagement {
public:
    int ID;
    string Mobile_no;
    string Name;
    string Medical;
    PatientManagement* next;

    // Default constructor
    PatientManagement() {
        ID = 0;
        Mobile_no = "";
        Name = "";
        Medical = "";
        next = nullptr;
    }

    // Parameterized constructor
    PatientManagement(int id,  std::string mobile_no, string name, string medicalhistory) {
        ID = id;
        Mobile_no = mobile_no;
        Name = name;
        Medical = medicalhistory;
        next = nullptr;
    }

    static PatientManagement* head;

    void getinfo(int id, string mobile_no, string name, string medicalhistory) {
        PatientManagement* new_patient = new PatientManagement(id, mobile_no, name, medicalhistory);
        if (head == nullptr) {
            head = new_patient;
        } else {
            PatientManagement* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_patient;
        }
        cout << "Patient added successfully!\n";
    }

    bool isPatientRegistered(int id) {
        PatientManagement* temp = head;
        while (temp != nullptr) {
            if (temp->ID == id) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void searchpatient(int id) {
        PatientManagement* temp = head;
        while (temp != nullptr) {
            if (temp->ID == id) {
                cout << "\nPatient Found:";
                cout << "\nPatient Name:\t" << temp->Name;
                cout << "\nPatient ID:\t" << temp->ID;
                cout << "\nPatient Mobile Number:\t" << temp->Mobile_no;
                cout << "\nPatient Medical History:\t" << temp->Medical << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "\nPatient not found.\n";
    }

    void generatereport(int id) {
        PatientManagement* temp = head;
        while (temp != nullptr) {
            if (temp->ID == id) {
                cout << "\nPatient Report:";
                cout << "\nPatient Name:\t" << temp->Name;
                cout << "\nPatient ID:\t" << temp->ID;
                cout << "\nPatient Mobile Number:\t" << temp->Mobile_no;
                cout << "\nPatient Medical History:\t" << temp->Medical << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "\nPatient not found.\n";
    }

    void displaypatients() {
        if (head == nullptr) {
            cout << "\nNo patients to display.\n";
            return;
        }
        PatientManagement* temp = head;
        while (temp != nullptr) {
            cout << "\nPatient ID:\t" << temp->ID;
            cout << "\nPatient Name:\t" << temp->Name;
            cout << "\nPatient Mobile No:\t" << temp->Mobile_no;
            cout << "\nPatient Medical History:\t" << temp->Medical << "\n";
            temp = temp->next;
        }
    }
};
PatientManagement* PatientManagement::head = nullptr;

// Class for scheduling appointments
class ScheduleAppointment {
public:
    struct Appointment {
        int patientID;
        string date;
        string time;
        string doctor;
        Appointment* next;
    };
    Appointment* head;

    ScheduleAppointment() {
        head = nullptr;
    }

    void bookappointment(int patientID, string date, string time, string doctor, PatientManagement& pm) {
        if (!pm.isPatientRegistered(patientID)) {
            cout << "\nPatient not registered. Cannot book appointment.\n";
            return;
        }

        Appointment* temp = head;
        while (temp != nullptr) {
            if (temp->date == date && temp->time == time && temp->doctor == doctor) {
                cout << "\nThe time slot is already booked. Please choose another time slot.\n";
                return;
            }
            temp = temp->next;
        }
        Appointment* newAppointment = new Appointment();
        newAppointment->patientID=patientID;
        newAppointment->date = date;
        newAppointment->time = time;
        newAppointment->doctor = doctor;
        newAppointment->next = head;
        head = newAppointment;
        cout << "\nAppointment booked successfully for Patient ID: " << patientID << "\n";
    }

    void cancelappointment(int patientID, string date, string time, string doctor) {
        Appointment* temp = head;
        Appointment* prev = nullptr;
        while (temp != nullptr) {
            if (temp->patientID == patientID && temp->date == date && temp->time == time && temp->doctor == doctor) {
                if (prev == nullptr) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "\nAppointment canceled successfully for Patient ID: " << patientID << "\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "\nAppointment not found.\n";
    }

    void viewappointments() {
        if (head == nullptr) {
            cout << "\nNo appointments to display.\n";
            return;
        }
        Appointment* temp = head;
        while (temp != nullptr) {
            cout << "\nPatient ID: " << temp->patientID;
            cout << "\nDate: " << temp->date;
            cout << "\nTime: " << temp->time;
            cout << "\nDoctor: " << temp->doctor << "\n";
            temp = temp->next;
        }
    }
};

// Class for managing staff
class ManageStaff {
public:
    struct Staff {
        int staffID;
        string name;
        string position;
        string contact;
        Staff* next;
    };

    Staff* head;

    ManageStaff() {
        head = nullptr;
    }

    void addstaff(int staffID, string name, string position, string contact) {
        Staff* newStaff = new Staff();
        newStaff->staffID = staffID;
        newStaff->name = name;
        newStaff->position = position;
        newStaff->contact = contact;
        newStaff->next = nullptr;

        if (head == nullptr) {
            head = newStaff;
        } else {
            Staff* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newStaff;
        }
        cout << "\nNew staff member added successfully!\n";
    }

    void viewstaff() {
        if (head == nullptr) {
            cout << "\nNo staff members to display.\n";
            return;
        }
        Staff* temp = head;
        while (temp != nullptr) {
            cout << "\nStaff ID: " << temp->staffID;
            cout << "\nName: " << temp->name;
            cout << "\nPosition: " << temp->position;
            cout << "\nContact: " << temp->contact << "\n";
            temp = temp->next;
        }
    }
};

// Class for managing rooms
class ManageRooms 
{
private:
    struct Room {
        int roomNumber;
        string roomType;
        bool availability;
        int patientID;
        Room* next;
    };

    Room* head;

public:
    ManageRooms() {
        head = nullptr;
    }

    void addRoom(int roomNumber, string roomType) {
        Room* newRoom = new Room();
        newRoom->roomNumber = roomNumber;
        newRoom->roomType = roomType;
        newRoom->availability = true;
        newRoom->patientID = -1;
        newRoom->next = head;
        head = newRoom;
    }

    void displayRooms() {
        if (head == nullptr) {
            cout << "\nNo rooms to display.\n";
            return;
        }
        Room* temp = head;
        while (temp != nullptr) {
            cout << "\nRoom Number: " << temp->roomNumber
                 << ", Room Type: " << temp->roomType
                 << ", Availability: " << (temp->availability ? "Available" : "Occupied")
                 << ", Patient ID: " << (temp->patientID == -1 ? "None" : to_string(temp->patientID)) << "\n";
            temp = temp->next;
        }
    }

    bool allocateRoom(int roomNumber, int patientID, PatientManagement& pm) {
        if (!pm.isPatientRegistered(patientID)) {
            cout << "\nPatient not registered. Cannot allocate room.\n";
            return false;
        }

        Room* temp = head;
        while (temp != nullptr) {
            if (temp->roomNumber == roomNumber && temp->availability)  {
                temp->availability = false;
                temp->patientID = patientID;
                return true;
            }
            temp = temp->next;
        }
          return false;
    }
};

// Class for generating bills
class GenerateBill {
public:
    struct Service {
        string serviceName;
        double serviceCost;
        Service* next;
    };

    Service* head;

    GenerateBill() {
        head = nullptr;
    }

    void addservice(string serviceName, double serviceCost) {
        Service* newService = new Service();
        newService->serviceName = serviceName;
        newService->serviceCost = serviceCost;
        newService->next = head;
        head = newService;
    }

    void createbill(int patientID, PatientManagement& pm) {
        if (!pm.isPatientRegistered(patientID)) {
            cout << "\nPatient not registered. Cannot generate bill.\n";
            return;
        }

        cout << "\nGenerating Bill for Patient ID: " << patientID;
        Service* temp = head;
        double totalCharges = 0;

        cout << "\nServices Provided:";
        while (temp != nullptr) {
            cout << "\nService Name: " << temp->serviceName;
            cout << "\nService Cost: " << temp->serviceCost << "\n";
            totalCharges += temp->serviceCost;
            temp = temp->next;
        }

        cout << "\nTotal Charges: " << totalCharges << "\n";
    }
};

// Main function
int main() {
    PatientManagement pm;
    ScheduleAppointment sa;
    ManageStaff ms;
    ManageRooms mr;
    GenerateBill gb;

    int choice;
    do {
        cout << "\n1. Manage Patients\n2. Schedule Appointment\n3. Manage Staff\n4. Manage Rooms\n5. Generate Bill\n6. Search Patient\n7. Generate Report \n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string mobile_no;
            string name, medicalhistory;
            cout << "\nEnter Patient ID: ";
            cin >> id;
            cout << "Enter Mobile Number: ";
            cin >> mobile_no;
            cout << "Enter Patient Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Medical History: ";
            getline(cin, medicalhistory);
            pm.getinfo(id, mobile_no, name, medicalhistory);
            break;
        }
        case 2: {
            int patientID;
            string date, time, doctor;
            cout << "\nEnter Patient ID: ";
            cin >> patientID;
            cout << "Enter Date (DD/MM/YYYY): ";
            cin >> date;
            cout << "Enter Time (HH:MM): ";
            cin >> time;
            cout << "Enter Doctor's Name: ";
            cin.ignore();
            getline(cin, doctor);
            sa.bookappointment(patientID, date, time, doctor, pm);
            break;
        }
        case 3: {
            int staffID;
            string name, position, contact;
            cout << "Enter Staff ID: ";
            cin >> staffID;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Position: ";
            getline(cin, position);
            cout << "Enter Contact: ";
            getline(cin, contact);
            ms.addstaff(staffID, name, position, contact);
            ms.viewstaff();
            break;
        }
        case 4: {
            int action;
            cout << "\nRoom Management Menu:";
            cout << "\n1. Add Room";
            cout << "\n2. Allocate Room";
            cout << "\n3. Display Rooms";
            cout << "\n0. Go Back";
            cout << "\nEnter your choice: ";
            cin >> action;

            switch (action) {
               case 1: {
                    int roomNumber;
                    string roomType;
                    cout << "\nAdd Room Details:";
                    cout << "\nEnter Room Number: ";
                    cin >> roomNumber;
                    cout << "Enter Room Type: ";
                    cin.ignore();
                    getline(cin, roomType);
                    mr.addRoom(roomNumber, roomType);
                    cout << "Room added successfully!\n";
                    break;
                }
               case 2: {
                    int roomNumber, patientID;
                    cout << "\nEnter Room Number to Allocate: ";
                    cin >> roomNumber;
                    cout << "Enter Patient ID: ";
                    cin >> patientID;
                    if (mr.allocateRoom(roomNumber, patientID, pm)) {
                    cout << "Room allocated successfully!\n";
                    } else {
                    cout << "Room allocation failed. Room may be occupied or patient not registered.\n";
                    }
                    break;
                }
                case 3:
                    mr.displayRooms();
                    break;
                case 0:
                    cout << "\nGoing back to main menu...\n";
                    break;
                    default:
                    cout << "\nInvalid choice...!\n";
                    break;
                }
                 break;
             }
        case 5: {
            int patientIDForBill;
            cout << "Enter Patient ID for Bill: ";
            cin >> patientIDForBill;

            string serviceName;
            double serviceCost;
            char addMoreServices;

            do {
                cout << "Enter Service Name: ";
                cin >> ws; // To consume any leading whitespace
                getline(cin, serviceName);

                cout << "Enter Service Cost: ";
                cin >> serviceCost;

                gb.addservice(serviceName, serviceCost);

                 
                cout << "Do you want to add another service? (y/n): ";
                cin >> addMoreServices;

            } while (addMoreServices == 'y' || addMoreServices == 'Y');

            gb.createbill(patientIDForBill, pm);

            break;
        }
        case 6: {
            int id;
            cout << "\nEnter Patient ID to Search: ";
            cin >> id;
            pm.searchpatient(id);
            break;
        }
        case 7: {
            int id;
            cout << "\nEnter Patient ID to Generate report: ";
            cin >> id;
            pm.generatereport(id);
            break;
        }
        case 0:
            cout << "\nExiting...!\n";
            break;
        default:
            cout << "\nInvalid choice...!\n";
            break;
        }
    } while (choice != 0);

    return 0;
}