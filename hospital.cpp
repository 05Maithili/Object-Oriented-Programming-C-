#include <iostream>
using namespace std;

class Person {
public:
    int id_no;
    long mobile_no;
    char name[50];

    void infoget() {
        cout << "\nEnter the ID Number:\t";
        cin >> id_no;
        cout << "\nEnter the Name:\t";
        cin.ignore();
        cin.getline(name, 50);
        cout << "\nEnter the Mobile Number:\t";
        cin >> mobile_no;
    }

    void display() {
        cout << "\nID Number:\t" << id_no;
        cout << "\nName:\t" << name;
        cout << "\nMobile Number:\t" << mobile_no;
    }
};

class Doctor : virtual public Person {
public:
    char specialty[50];
    int yearofexp;

    void infoget() {
        Person::infoget();
        cout << "\nEnter the Specialty:\t";
        cin.ignore();
        cin.getline(specialty, 50);
        cout << "\nEnter the Years of Experience:\t";
        cin >> yearofexp;
    }

    void display() {
        Person::display();
        cout << "\nSpecialty:\t" << specialty;
        cout << "\nYears of Experience:\t" << yearofexp;
    }
};

class Nurse : virtual public Person {
public:
    char shifttime[20];
    int patient_no;

    void infoget() {
        Person::infoget();
        cout << "\nEnter the Shift Time (morning/night):\t";
        cin.ignore();
        cin.getline(shifttime, 20);
        cout << "\nEnter the Number of Patients Assigned:\t";
        cin >> patient_no;
    }

    void display() {
        Person::display();
        cout << "\nShift Time:\t" << shifttime;
        cout << "\nNumber of Patients Assigned:\t" << patient_no;
    }
};

class AdminStaff : public Doctor, public Nurse {
public:
    void search(int num, Doctor doc[], Nurse nurse[]) {
        int ch1;
        do {
            cout << "\nEnter your choice:\n1. Search Doctor\n2. Search Nurse\n3. Exit:\t";
            cin >> ch1;
            switch (ch1) {
                case 1: {
                    int search_id;
                    cout << "\nEnter Doctor's ID to search:\t";
                    cin >> search_id;
                    bool found = false;
                    for (int i = 0; i < num; i++) {
                        if (doc[i].id_no == search_id) {
                            cout << "\nDoctor found:\n";
                            doc[i].display();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "\nDoctor not found!";
                    }
                    break;
                }
                case 2: {
                    int search_id;
                    cout << "\nEnter Nurse's ID to search:\t";
                    cin >> search_id;
                    bool found = false;
                    for (int i = 0; i < num; i++) {
                        if (nurse[i].id_no == search_id) {
                            cout << "\nNurse found:\n";
                            nurse[i].display();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "\nNurse not found!";
                    }
                    break;
                }
                case 3:
                    cout << "\nExiting....!";
                    break;
                default:
                    cout << "\nInvalid choice!";
                    break;
            }
        } while (ch1 != 3);
    }
};

int main() {
    Doctor doc[10];
    Nurse nurse[20];
    AdminStaff admin;
    int i, n, ch;
    do {
        cout << "\nEnter your choice:\n1. Doctor information\n2. Nurse information\n3. Search Doctor/Nurse\n4. Exit:\t";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nEnter the number of Doctors:\t";
                cin >> n;
                for (i = 0; i < n; i++) {
                    doc[i].infoget();
                }
                break;
            case 2:
                cout << "\nEnter the number of Nurses:\t";
                cin >> n;
                for (i = 0; i < n; i++) {
                    nurse[i].infoget();
                }
                break;
            case 3:
                admin.search(n, doc, nurse);
                break;
            case 4:
                cout << "\nExiting....!";
                break;
            default:
                cout << "\nInvalid choice!";
                break;
        }
    } while (ch != 4);

    return 0;
}
