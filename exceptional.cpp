#include<iostream>
using namespace std;

class television
{
    int mn, pz, sz;
public:
    friend ostream& operator<< (ostream &vout,television &t);
    friend istream& operator>> (istream &vin, television &t);
};

istream& operator>>(istream &vin, television &t)
{
    cout << "Enter the model number, size, and price: ";
    vin >> t.mn >> t.sz >> t.pz;

    try {
        
        if (t.mn > 9999 || t.sz > 70 || t.sz < 12 || t.pz < 0 || t.pz > 5000) {
            throw "Invalid input!";
        }
    }
    catch (const char* e) {
    
        cout << "Exception caught: " << e << endl;
        t.mn = 0;  
        t.sz = 0;
        t.pz = 0;
    }

    return vin; 
}
ostream& operator<<(ostream &vout, television &t)
{
    vout << "Model number: " << t.mn << endl;
    vout << "Size: " << t.sz << " inches" << endl;
    vout << "Price: $" << t.pz << endl;
    return vout; 
}

int main()
{
    television tv;
    cin >> tv;  
    cout << tv; 
    return 0;
}