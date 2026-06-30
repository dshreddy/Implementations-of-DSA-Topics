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

/**
 * TC : O(log(n)), because the code in the while loop is performed at most twice for each jump length.
 * The idea is to make jumps and slow the speed when we get closer to the target element.
 * Example : 
 * v = {-1, 0, 1, 2, 3}, x = -1
 * 
 * index = 0, n = 5
 * Iteration 1 : step = 2, index = 0, v[index+step] = 1 > -1, so we don't move index
 * Iteration 2 : step = 1, index = 0, v[index+step] = 0 > -1, so we don't move index
 */
int binary_search_version2(vector<int> &v, int x) {
    int index = 0, n = v.size();
    for(int step = n/2; step >= 1; step /= 2) {
        while(index+step < n && v[index+step] <= x) index += step;
    }
    return v[index] == x ? index : -1;
}

int main() {
    vector<int> v = {-1, 0, 1, 2, 3};
    cout << binary_search(v, -1) << endl;
    cout << binary_search(v, 2) << endl;
    cout << binary_search(v, 10) << endl;
}