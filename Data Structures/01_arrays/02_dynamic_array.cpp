#include <iostream>
using namespace std;

class DynamicArray {
private:
    int size = 0, capacity = 2;
    int *arr = new int[2];

    void scale() {
        int newCapacity = 2 * capacity;
        int *newArr = new int[newCapacity];

        for(int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:

    ~DynamicArray() {
        delete[] arr;
    }

    // O(n)
    void insert(int i, int n) {
        if(size == capacity) scale();
        if (i < 0 || i > size) return;

        for(int j = size - 1; j >= i; j--) {
            arr[j + 1] = arr[j];
        }
        arr[i] = n;
        size++;
    }

    // O(n)
    void remove(int i) {
        if (i < 0 || i >= size) return;

        for(int j = i; j < size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        size--;
    }

    // O(n)
    void print() {
        for(int i = 0; i < size; i++) cout << arr[i] << "\t";
        cout<<"\n";
    }
};

int main() {
    DynamicArray da;

    da.insert(0, 1);
    da.insert(1, 2);
    da.insert(2, 3);
    da.insert(3, 4);
    da.insert(4, 5);
    
    da.print();

    da.remove(2);
    da.print();

    return 0;
}