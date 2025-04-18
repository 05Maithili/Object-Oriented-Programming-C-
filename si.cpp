#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Maximum number of entries
#define MAX_ENTRIES 100

// Base class: Student
class Student {
protected:
    string name;
    int rollNo;
    string subject;

public:
    virtual void input() = 0;          // Pure virtual function for input
    virtual void display() = 0;        // Pure virtual function for display
        
};

// Derived class: Record
class Record : public Student {
private:
    string subjectCode;
    float internalMarks;
    float universityMarks;

public:
    void input() override {
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Subject: ";
        cin.ignore();
        getline(cin, subject);
        cout << "Enter Subject Code: ";
        getline(cin, subjectCode);
        cout << "Enter Internal Marks: ";
        cin >> internalMarks;
        cout << "Enter University Marks: ";
        cin >> universityMarks;
    }

    void display() override {
        cout << setw(15) << name
             << setw(10) << rollNo
             << setw(15) << subject
             << setw(15) << subjectCode
             << setw(10) << internalMarks
             << setw(10) << universityMarks << endl;
    }

    int getRollNo() {
        return rollNo;
    }

    void editMarks() {
        cout << "Enter New Internal Marks: ";
        cin >> internalMarks;
        cout << "Enter New University Marks: ";
        cin >> universityMarks;
    }
};

// Function prototypes
void buildMasterTable(Record records[], int &count);
void listTable(Record records[], int count);
void insertEntry(Record records[], int &count);
void deleteEntry(Record records[], int &count);
void editEntry(Record records[], int count);
void searchRecord(Record records[], int count);

int main() {
    Record records[MAX_ENTRIES];
    int count = 0; // Current count of records
    int choice;

    do {
        cout << "\nMenu:";
        cout << "\n1. Build Master Table";
        cout << "\n2. List Table";
        cout << "\n3. Insert New Entry";
        cout << "\n4. Delete Entry";
        cout << "\n5. Edit Entry";
        cout << "\n6. Search for Record";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                buildMasterTable(records, count);
                break;
            case 2:
                listTable(records, count);
                break;
            case 3:
                insertEntry(records, count);
                break;
            case 4:
                deleteEntry(records, count);
                break;
            case 5:
                editEntry(records, count);
                break;
            case 6:
                searchRecord(records, count);
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}

void buildMasterTable(Record records[], int &count) {
    cout << "Enter number of records to add: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (count < MAX_ENTRIES) {
            cout << "\nEntering details for Record " << (count + 1) << ":\n";
            records[count].input();
            count++;
        } else {
            cout << "Master table is full!" << endl;
            break;
        }
    }
}

void listTable(Record records[], int count) {
    if (count == 0) {
        cout << "No records available to display." << endl;
        return;
    }
    cout << "\nMaster Table:\n";
    cout << setw(15) << "Name" 
         << setw(10) << "Roll No" 
         << setw(15) << "Subject" 
         << setw(15) << "Sub Code" 
         << setw(10) << "Internal" 
         << setw(10) << "University" << endl;

    for (int i = 0; i < count; i++) {
        records[i].display();
    }
}

void insertEntry(Record records[], int &count) {
    if (count < MAX_ENTRIES) {
        cout << "\nInserting a new record:\n";
        records[count].input();
        count++;
    } else {
        cout << "Master table is full!" << endl;
    }
}

void deleteEntry(Record records[], int &count) {
    if (count == 0) {
        cout << "No records to delete." << endl;
        return;
    }
    cout << "Enter Roll Number to delete: ";
    int roll;
    cin >> roll;
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (records[i].getRollNo() == roll) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Record not found." << endl;
    } else {
        for (int i = index; i < count - 1; i++) {
            records[i] = records[i + 1];
        }
        count--;
        cout << "Record deleted successfully." << endl;
    }
}

void editEntry(Record records[], int count) {
    if (count == 0) {
        cout << "No records to edit." << endl;
        return;
    }
    cout << "Enter Roll Number to edit: ";
    int roll;
    cin >> roll;
    for (int i = 0; i < count; i++) {
        if (records[i].getRollNo() == roll) {
            cout << "Editing marks for Roll Number " << roll << ":\n";
            records[i].editMarks();
            cout << "Marks updated successfully." << endl;
            return;
        }
    }
    cout << "Record not found." << endl;
}

void searchRecord(Record records[], int count) {
    if (count == 0) {
        cout << "No records to search." << endl;
        return;
    }
    cout << "Enter Roll Number to search: ";
    int roll;
    cin >> roll;
    for (int i = 0; i < count; i++) {
        if (records[i].getRollNo() == roll) {
            cout << "Record found:\n";
            records[i].display();
            return;
        }
    }
    cout << "Record not found." << endl;
}