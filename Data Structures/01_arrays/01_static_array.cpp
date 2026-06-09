#include <iostream>
using namespace std;

class StaticArray {
private:
    int *arr;
    int size = 0, capacity;

public:
    StaticArray(int capacity) {
        this->capacity = capacity;
        this->arr = new int[capacity];
    }

    ~StaticArray() {
        delete[] arr;
    }

    // O(n)
    void insert(int i, int n) {
        if (i < 0 || i > size || size == capacity) return;

        for (int index = size - 1; index >= i; index--) {
            arr[index + 1] = arr[index];
        }   
        arr[i] = n;
        size++;
    }

    // O(n)
    void remove(int i) {
        if (i < 0 || i >= size) return;

        for (int index = i + 1; index < size; index++) {
            arr[index - 1] = arr[index];
        }
        size--;
    }

    // O(n)
    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
};

int main() {
    class StaticArray arr(5);
    arr.insert(0, 1);
    arr.insert(1, 2);
    arr.insert(2, 3);
    arr.insert(3, 4);
    arr.insert(4, 5);
    arr.print();
    arr.remove(2);
    arr.print();
    return 0;
}