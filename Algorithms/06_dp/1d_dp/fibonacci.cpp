#include<iostream>
using namespace std;

/**
 * TC : O(2^n)
 * SC : O(n) (due to recursive stack)
 */
int recursion(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return recursion(n-1) + recursion(n-2);
}

/**
 * TC : O(n)
 * SC : O(n) (due to memoization table and recursive stack)
 * Also known as top-down approach
 */
int recursion_with_memoization(int n, unordered_map<int,int> &cache) {
    if(n == 0 || n == 1) return n;
    else if(cache.find(n) != cache.end()) return cache[n];
    else return cache[n] = recursion_with_memoization(n-1, cache) + recursion_with_memoization(n-2, cache);
}

/**
 * TC : O(n)
 * SC : O(n)
 * Also known as bottom-up approach
 */
int dp (int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++) dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

int main() {
    /**
     * Fibonacci number is the sum of the two preceding ones, usually starting with 0 and 1. That is,
     * F(0) = 0, F(1) = 1
     * F(n) = F(n-1) + F(n-2), for n > 1.
    */
    int n = 10;
    cout << recursion(n) << endl;

    unordered_map<int,int> cache;
    cout << recursion_with_memoization(n, cache) << endl;
    cout << dp(n) << endl;

    return 0;
}