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
    int getSize() {
        return size;
    }

    void push(int val) {
        if(size >= capacity) {
            scale();
        }
        arr[size++] = val;
    }

    void print() {
        for(int i = 0; i < size; i++) cout << arr[i] << "\t";
        cout<<"\n";
    }

    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray da;

    da.push(10);
    da.push(20);
    da.push(30);

    da.print();

    return 0;
}