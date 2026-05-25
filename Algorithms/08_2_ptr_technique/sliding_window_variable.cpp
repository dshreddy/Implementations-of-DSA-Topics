#include<iostream>
using namespace std;

/**
 * TC : O(n)
 * SC : O(1)
 */
bool sliding_window_variable(vector<int>& v) {

    int q = 0, n = v.size(), maxSubArray = 0;

    for(int p = 0; p < n; p++) {
        while(q < n && arr[q] == arr[q+1]) q++;
        maxSubArray = max(maxSubArray, q-p+1);
    }

    return maxSubArray;
}

int main() {
    /*
    Given an integer array nums find the length of the longest subarray that contains same element at every position. 
    */
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout << sliding_window_variable(v) << endl;
}