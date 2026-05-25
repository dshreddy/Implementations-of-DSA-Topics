#include<iostream>
using namespace std;

/**
 * TC : O(n)
 * SC : O(k)
 */
bool sliding_window_fixed(vector<int>& v, int k) {

    int p = 0, q = 0, n = v.size();
    unordered_map<int,int> freq;

    for(int q; q < n; q++) {
        if(q-p+1 > k) {
            freq[v[p]]--;
            p++;
        } 
        freq[v[q]]++;
        if(freq[v[q]] > 1) return true;
    }
    return false;
}

int main() {
    /*
    Given an integer array nums and an integer k, 
    return true if there are two distinct elements in a window of size k that are equal, and 
           false otherwise.
    */
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    int k = 3;
    cout << sliding_window_fixed(v, k) << endl;
}