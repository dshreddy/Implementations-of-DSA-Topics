#include<iostream>
using namespace std;

/**
 * TC: O(2 ^ (l1+l2)) 
 * SC : O(l1+l2)
 * where l1 = length of s1 & l2 = length of l2
 * */
int bruteForce(const string &s1, int i, const string &s2, int j) {
    if(i == s1.size() || j == s2.size()) return 0;

    if(s1[i] == s2[j]) return 1 + bruteForce(s1, i+1, s2, j+1);
    else return max(bruteForce(s1, i+1, s2, j), bruteForce(s1, i, s2, j+1));
}

/**
 * TC : O(l1 * l2)
 * SC : O(l1 * l2)
 */
int topDownDP(const string &s1, int i, const string &s2, int j, vector<vector<int>> &cache) {

    if(i == s1.size() || j == s2.size()) return 0;

    if(cache[i][j] == -1) {
        if(s1[i] == s2[j]) cache[i][j] = 1 + topDownDP(s1, i+1, s2, j+1, cache);
        else cache[i][j] = max(topDownDP(s1, i+1, s2, j, cache), topDownDP(s1, i, s2, j+1, cache));
    }

    return cache[i][j];
}

/**
 * TC : O(l1 * l2)
 * SC : O(l1 * l2)
 */
int bottomUpDP(const string &s1, const string &s2) {

    int l1 = s1.size(), l2 = s2.size();
    vector<vector<int>> cache(l1+1, vector<int>(l2+1, 0));

    for(int i = 1; i <= l1; i++) {
        for(int j = 1; j <= l2; j++) {
            if(s1[i-1] == s2[j-1]) cache[i][j] = 1 + cache[i-1][j-1];
            else cache[i][j] = max(cache[i-1][j], cache[i][j-1]);
        }
    }

    return cache[l1][l2];
}

/**
 * Given two strings, s1 & s2 find the Longest Common Subsequence of s1 and s2.
 */
int main() {
    string s1 = "adcb";
    string s2 = "abc";
    cout<<bruteForce(s1, 0, s2, 0)<<endl;
    cout<<bottomUpDP(s1, s2)<<endl;

    int l1 = s1.size(), l2 = s2.size();
    vector<vector<int>> cache(l1+1, vector<int>(l2+1, -1));
    cout<<topDownDP(s1, 0, s2, 0, cache)<<endl;
}