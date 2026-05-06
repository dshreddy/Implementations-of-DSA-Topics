#include<iostream>
using namespace std;

/*
    A min heap is a complete binary tree wwith the fllowing properties:
    1. Order property: The value of each node is less than or equal to the values of its children.
    2. Structure property: The tree is complete, meaning all levels are fully filled except possibly the last level, which is filled from left to right.
*/
class MinHeap{
private:
    vector<int> _storage;
    int size = 0;

    int parent(int i) {
        return (i-1)/2;
    }

    int left(int i) {
        return 2*i + 1;
    }

    int right(int i) {
        return 2*i + 2;
    }

    // O(log n)
    void percolateUp(int index) {
        if(index < 0 || index >= size) return;

        int p = parent(index);

        if(p >= 0 && p < size && (_storage[index] < _storage[p])) {
            swap(_storage[index], _storage[p]);
            percolateUp(p);
        }
    }

    // O(log n)
    void percolateDown(int index) {
        if(index < 0 || index >= size) return;

        int l = left(index), r = right(index), minIndex = index;

        if(l >= 0 && l < size && (_storage[l] < _storage[minIndex])) minIndex = l;
        if(r >= 0 && r < size && (_storage[r] < _storage[minIndex])) minIndex = r;

        
        if(minIndex != index) {
            swap(_storage[index], _storage[minIndex]);
            percolateDown(minIndex);
        }
    }

    // ** TC : O(n) **
    void heapify() {
        for(int i = size/2 - 1; i >= 0; i--) {
            percolateDown(i);
        }
    }
    
public:
    MinHeap() {}

    MinHeap(vector<int> arr) {
        _storage = arr;
        size = arr.size();
        heapify();
    }

    bool empty() {
        return size == 0;
    }

    // O(1)
    int top() {
        if(!empty()) return _storage[0];
        else throw std::runtime_error("Heap is Empty\n");
    }

    // O(log n)
    void push(int n) {
        _storage.push_back(n);
        size++;
        percolateUp(size-1);
    }

    // O(log n)
    void pop() {
        swap(_storage[0], _storage[size-1]);
        _storage.pop_back();
        size--;
        percolateDown(0);
    }
};

int main() {

    MinHeap h;
    h.push(0);
    h.push(1);
    h.push(-1);
    h.push(2);
    h.push(-2);
    h.push(3);
    h.push(-3);

    while(!h.empty()) {
        cout << h.top() << " ";
        h.pop();
    }
    cout << endl;
}
