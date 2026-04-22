#include <iostream>
using namespace std;

class Stack{
private:
    vector<int> _stack;
    
public:
    void push(int n) {
        _stack.push_back(n);
    }  

    void pop() {
        if (!_stack.empty()) _stack.pop_back();
        else throw std::out_of_range("Stack is empty");
    }

    int top() {
        if (!_stack.empty()) return _stack.back();
        else throw std::out_of_range("Stack is empty");
    }
};

int main() {
    
    stack<int> stlStack;
    stlStack.push(1);
    stlStack.push(2);
    stlStack.push(3);
    cout<<stlStack.top()<<"\n"; // 3
    stlStack.pop();
    cout<<stlStack.top()<<"\n"; // 2
    
    Stack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    cout<<myStack.top()<<"\n"; // 3
    myStack.pop();
    cout<<myStack.top()<<"\n"; // 2
    
    return 0;
}