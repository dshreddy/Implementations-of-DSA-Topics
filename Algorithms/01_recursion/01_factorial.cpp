#include <iostream>
using namespace std;

int fact(int n) {
    if(n < 0) throw std::invalid_argument("Negative input not allowed");
    else if(n == 0) return 1;
    return n * fact(n - 1);
}

int main() {
    cout<<fact(5)<<endl;
}