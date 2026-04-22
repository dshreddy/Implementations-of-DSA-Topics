#include <iostream>
using namespace std;

// O(1)
// Insert n into arr at the next open position.
// Length is the number of 'real' values in arr, and capacity
// is the size (aka memory allocated for the fixed size array).
void insertEnd(int arr[], int n, int length, int capacity) {
    if (length < capacity) {
        arr[length] = n;
    }
}

// O(1)
// Remove from the last position in the array if the array
// is not empty (i.e. length is non-zero).
void removeEnd(int arr[], int length) {
    if (length > 0) {
        arr[length - 1] = 0;
    }
}

// O(n)
// Insert n into index i after shifting elements to the right.
// Assuming i is a valid index and arr is not full.
void insertMiddle(int arr[], int i, int n, int length) {
    for (int index = length - 1; index >= i; index--) {
        arr[index + 1] = arr[index];
    }   
    arr[i] = n;
}

// O(n)
// Remove value at index i before shifting elements to the left.
// Assuming i is a valid index.
void removeMiddle(int arr[], int i, int length) {
    for (int index = i + 1; index < length; index++) {
        arr[index - 1] = arr[index];
    }
}

// O(n)
void printArr(int arr[], int capacity) {
    for (int i = 0; i < capacity; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() {
    cout<<"Hello\n";
    return 0;
}