#include<iostream>
#include<set>
using namespace std;

int main() {
    set<int> s;
    s.insert(5);
    s.insert(2);
    s.insert(8);
    s.insert(1);
    s.insert(3);

    cout << "Elements in the set: ";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Check if an element exists
    int element = 3;
    if (s.find(element) != s.end()) {
        cout << element << " is found in the set." << endl;
    } else {
        cout << element << " is not found in the set." << endl;
    }

    // Remove an element
    s.erase(2);
    cout << "Elements in the set after removing 2: ";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // O(log n), returns an iterator to the first element that is not less than (i.e., greater or equal to) 4
    auto it = s.lower_bound(4);
    if (it != s.end()) {
        cout << "Lower bound of 4 is: " << *it << endl;
    } else {
        cout << "Lower bound of 4 does not exist." << endl;
    }
    return 0;
}