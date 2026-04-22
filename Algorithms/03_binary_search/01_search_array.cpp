#include<iostream>
using namespace std;

/**
 * v = sorted array of integers
 * x = an integer 
 * Returns index of x in v if present, else -1
 * TC : O(log(n))
 */
int binary_search(vector<int> &v, int x) {
    int start = 0, end = v.size()-1, mid;
    while(start <= end) {
        mid = (start+end)/2;
        if(v[mid] == x) return mid;
        else if(v[mid] > x) end = mid-1;
        else start = mid+1;
    }
    return -1;
}

int main() {
    vector<int> v = {-1, 0, 1, 2, 3};
    cout << binary_search(v, -1) << endl;
    cout << binary_search(v, 2) << endl;
    cout << binary_search(v, 10) << endl;
}