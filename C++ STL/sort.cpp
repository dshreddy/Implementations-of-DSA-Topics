#include <iostream>
using namespace std;

bool customComparator(int a, int b) {
    return a > b; // For descending order
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array in increasing order
    sort(arr, arr + n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> vec = {5, 2, 9, 1, 5, 6};
    // Sort the vector in decreasing order
    sort(vec.begin(), vec.end(), customComparator);
    cout << "Sorted vector (decreasing): ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}