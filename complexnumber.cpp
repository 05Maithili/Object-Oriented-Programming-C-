#include <iostream>
using namespace std;

class Complex {
public:
    int real;
    int imag;

    Complex() {
        real = 0;
        imag = 0;
    }

    // Friend function for input
    friend void input(Complex &c);

    void display() const {
        cout << "\nComplex number:\t" << real << "+" << imag << "i" << endl;
    }

    Complex operator+(Complex &a) {
        Complex temp;
        temp.real = real + a.real;
        temp.imag = imag + a.imag;
        return temp;
    }

    Complex operator-(Complex &a) {
        Complex temp;
        temp.real = real - a.real;
        temp.imag = imag - a.imag;
        return temp;
    }

    Complex operator*(Complex &a) {
        Complex temp;
        temp.real = real * a.real - imag * a.imag;
        temp.imag = real * a.imag + imag * a.real;
        return temp;
    }

    Complex operator/(Complex &a) {
        Complex temp;
        int denominator = a.real * a.real + a.imag * a.imag;
        temp.real = (real * a.real + imag * a.imag) / denominator;
        temp.imag = (imag * a.real - real * a.imag) / denominator;
        return temp;
    }
};

// Friend function for input
void input(Complex &c) {
    cout << "\nEnter value of real part:\t";
    cin >> c.real;
    cout << "Enter value of imaginary part:\t";
    cin >> c.imag;
}

int main() {
    Complex obj1, obj2, obj3;
    int choice;

    cout << "\n1. ";
    input(obj1);
    cout << "\n2. ";
    input(obj2);

    do {
        cout << "\nEnter your choice:\t";
        cout << "\n1. Addition";
        cout << "\n2. Subtraction";
        cout << "\n3. Multiplication";
        cout << "\n4. Division";
        cout << "\n5. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nAddition:\t";
                obj3 = obj1 + obj2;
                obj3.display();
                break;
            case 2:
                cout << "\nSubtraction:\t";
                obj3 = obj1 - obj2;
                obj3.display();
                break;
            case 3:
                cout << "\nMultiplication:\t";
                obj3 = obj1 * obj2;
                obj3.display();
                break;
            case 4:
                cout << "\nDivision:\t";
                obj3 = obj1 / obj2;
                obj3.display();
                break;
            case 5:
                cout << "\nExiting...\n";
                break;
            default:
                cout << "\nInvalid choice!";
                cout << "\nYou want to continue? (1/5): ";
                cin >> choice;
                break;
        }
    } while (choice != 5);

    return 0;
}
