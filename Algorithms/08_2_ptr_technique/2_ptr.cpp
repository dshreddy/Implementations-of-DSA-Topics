#include<iostream>
using namespace std;

/**
 * TC : O(n)
 */
pair<int, int> target_sum(vector<int> &v, int target) {
    int n = v.size(), p = 0, q = n - 1, sum;
    while(p < q) {
        sum = v[p] + v[q];
        if(sum > target) q--;
        else if(sum < target) p++;
        else return {p, q}
    }
    return {-1, -1}
}

int main() {
    // Given a sorted array and a target sum, find if there exists a pair in the array whose sum is equal to the given target.
    // Assume there is exactly one solution, and you may not use the same element twice.
    vector<int> v = {-1, 0, 1, 2, 3};
    int target = 2;
    pair<int, int> ans = target_sum(v, target);
    if(ans.first != -1) cout << "Pair found at indices: " << ans.first << " and " << ans.second << endl;
    else cout << "No pair found." << endl;
    return 0;
}