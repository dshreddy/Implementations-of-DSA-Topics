#include<iostream>
using namespace std;

int getBit(int n, int pos) {
    return (n & (1 << pos)) != 0;
}

int setBit(int n, int pos) {
    return n | (1 << pos);
}

int countBits(int n) {
    int count = 0;
    while(n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    int n = 23;
    // 23 in binary is 11101
    cout << "Get bit at position 3 in " << n << ": " << getBit(n, 3) << endl;
    cout << "Value of " << n << " after setting bit at position 3: " << setBit(n, 3) << endl;
    cout << "Number of set bits in " << n << " is " << countBits(n) << endl;
    return 0;
}
