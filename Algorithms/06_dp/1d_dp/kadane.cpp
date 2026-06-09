#include<iostream>
using namespace std;

/**
 * TC : O(n)
 * SC : O(n)
 * Explaination : 
 * - Let's say  v = {-2,1,-3,4,-1,2,1,-5,4}
 * - Subarray with max sum ending at index 0 = {-2}
 * - Subarray with max sum ending at index 1 = sub array with max sum in { {-2, 1}, {1} }
 * - Subarray with max sum ending at index 2 = sub array with max sum in { {-2,1,-3}, {1,-3}, {-3}}
 * -                                         = sub array with max sum in { {Subarray with max sum ending at index 1} + {-3}, {-3}}
 * - At each index, I have 2 decisions 
 *     - Add the current element to the subarray with max sum ending at previous index
 *     - Start a new subarray with the current element as the only element in the subarray
 * - So, at each index, I will take the maximum of these 2 decisions
 */
int top_down(vector<int>& v) {
    int n = v.size();
    vector<int> dp(n, 0);
    dp[0] = v[0];
    for(int i = 1; i < n; i++) dp[i] = max(v[i]+dp[i-1], v[i]);
    int max_sum = dp[0];
    for(int i = 1; i < n; i++) max_sum = max(max_sum, dp[i]);
    return max_sum;
}

int main() {
    /*
    Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
    */
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
}