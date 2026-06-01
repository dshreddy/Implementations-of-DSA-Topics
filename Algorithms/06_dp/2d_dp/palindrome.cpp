#include<iostream>
using namespace std;


/**
 * TC : O(n^2)
 * SC : O(1)
 */
int longestPalindromicSubstring(string s) {

    int n = s.size();

    int l, r, even, odd, lps = 0;
    for(int i = 0; i < n; i++) {

        l = i;
        r = i;
        while(l >= 0 && r < n && s[l] == s[r]) {
            lps = max(lps, r-l+1);
            l--;
            r++;
        }

        l = i;
        r = i+1;
        while(l >= 0 && r < n && s[l] == s[r]) {
            lps = max(lps, r-l+1);
            l--;
            r++;
        }
    }

    return lps;
}

/**
 * Given a string S, return the length of the longest palindromic substring within S.
 */
int main() {
    
    string s = "abaab";
    cout << longestPalindromicSubstring(s) << endl;
}