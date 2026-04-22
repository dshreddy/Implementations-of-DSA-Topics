#include <iostream>
using namespace std;

int main()
{
    queue<int> stlQ;
    stlQ.push(1);
    stlQ.push(2);
    stlQ.push(3);
    // {1, 2, 3}
    cout << stlQ.front() << "\n"; // 1
    stlQ.pop();
     // {2, 3}
    cout << stlQ.front() << "\n"; // 2
    stlQ.pop();
     // {3}
    cout << stlQ.front() << "\n"; // 3
    stlQ.pop();
    // {}
}