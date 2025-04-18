#include <iostream>
using namespace std;

template <class T>
void bubble_sort(T a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (a[j + 1] < a[j]) {
                T temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    cout << "Sorted array is: ";
    for (int j = 0; j < size; j++) {
        cout << a[j] << " ";
    }
    cout << endl;
}

int main() {
    char a[] = {'b', 'a', 'c', 'd'};
    int b[]={1,3,4,0};
    int size = 4;
    bubble_sort(a, size);
    bubble_sort(b, size);
    return 0;
}
