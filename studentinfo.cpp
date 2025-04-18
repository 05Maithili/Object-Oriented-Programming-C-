#include<iostream>
using namespace std;

int n;

class student {
public:
    int rollno;
    string name, prn;

    void accept1();
    void display1();
};

void student::accept1() {
    cout << "Enter the name and PRN number: ";
    cin >> name >> prn;
    cout << "Enter the roll number: ";
    cin >> rollno;
}

void student::display1() {
    cout << "Roll No: " << rollno << "\tName: " << name << "\tPRN: " << prn << endl;
}

class test : virtual public student {
public:
    string sub[5];
    int cia1[5], cia2[5], ese1[5];

    void accept2();
    void display2();
};

void test::accept2() {
    cout << "Enter the subject names: ";
    for (int i = 0; i < 5; i++) {
        cin >> sub[i];
    }

    cout << "Enter CIA1 marks (out of 20): ";
    for (int i = 0; i < 5; i++) {
        cin >> cia1[i];
    }

    cout << "Enter CIA2 marks (out of 20): ";
    for (int i = 0; i < 5; i++) {
        cin >> cia2[i];
    }

    cout << "Enter ESE1 marks (out of 60): ";
    for (int i = 0; i < 5; i++) {
        cin >> ese1[i];
    }
}

void test::display2() {
    for (int i = 0; i < 5; i++) {
        cout << sub[i] << "\t" << cia1[i] << "\t" << cia2[i] << "\t" << ese1[i] << "\n";
    }
}

class sport : virtual public student {
public:
    int sportMarks;

    void accept3();
    void display3();
};

void sport::accept3() {
    cout << "Enter the sports marks: ";
    cin >> sportMarks;
}

void sport::display3() {
    cout << "Sports Marks: " << sportMarks << endl;
}

class result : public test, public sport {
public:
    int subtotal[5];
    int overall = 0;
    float percentage;

    void calculateTotal();
    void calculatePercentage();
    void displayAll();
};

void result::calculateTotal() {
    overall = 0;
    for (int i = 0; i < 5; i++) {
        subtotal[i] = cia1[i] + cia2[i] + ese1[i];
        overall += subtotal[i];
    }
    overall += sportMarks;
}

void result::calculatePercentage() {
    percentage = (static_cast<float>(overall) / 530) * 100;
}

void result::displayAll() {
    cout << "\nName: " << name << "\nRoll No: " << rollno << "\nPRN: " << prn << endl;
    cout << "Subjects\tCIA1\tCIA2\tESE1\tTotal\n";
    for (int i = 0; i < 5; i++) {
        cout << sub[i] << "\t\t" << cia1[i] << "\t" << cia2[i] << "\t" << ese1[i] << "\t" << subtotal[i] << "\n";
    }
    cout << "Sports\t\t0\t0\t" << sportMarks << "\t" << sportMarks << endl;
    cout << "Total Percentage: " << percentage << "%" << endl;
}

int main() {
    cout << "Enter the number of records: ";
    cin >> n;

    result a[10];

    for (int i = 0; i < n; i++) {
        a[i].accept1();
        a[i].accept2();
        a[i].accept3();
        a[i].calculateTotal();
        a[i].calculatePercentage();
        a[i].displayAll();
    }

    return 0;
}
