#include <iostream>
using namespace std;

template <class T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

template <class T>
void display(const T arr[], int size) {
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    float arr2[] = {64.1f, 25.8f, 25.4f, 12.0f, 11.2f};
    int size = sizeof(arr) / sizeof(arr[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    selectionSort(arr, size);
    display(arr, size);

    selectionSort(arr2, size2);
    display(arr2, size2);

    return 0;
}
