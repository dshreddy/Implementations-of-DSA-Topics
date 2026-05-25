#include<iostream>
using namespace std;

struct customComparator {
    bool operator()(const int& a, const int& b) {
        return a > b; // Min-heap
    }
};

int main()
{
    priority_queue<int> pq; // Default is max-heap
    pq.push(10);
    pq.push(20);
    pq.push(5);
    cout<<"Top element: "<<pq.top()<<endl; // Output: 20
    pq.pop();
    cout<<"Top element after pop: "<<pq.top()<<endl; // Output: 10

    priority_queue<int, vector<int>, greater<int>> min_pq; // Min-heap
    min_pq.push(10);
    min_pq.push(20);
    min_pq.push(5);
    cout<<"Top element of min-heap: "<<min_pq.top()<<endl; // Output: 5
    min_pq.pop();   
    cout<<"Top element of min-heap after pop: "<<min_pq.top()<<endl; // Output: 10
    
    priority_queue<int, vector<int>, customComparator> custom_pq; // Custom comparator for min-heap
    custom_pq.push(10);
    custom_pq.push(20);
    custom_pq.push(5);
    cout<<"Top element of custom min-heap: "<<custom_pq.top()<<endl;
    custom_pq.pop();
    cout<<"Top element of custom min-heap after pop: "<<custom_pq.top()<<endl;

    return 0;
}