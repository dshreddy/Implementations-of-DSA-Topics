#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> cache;

    int maxRob(vector<int>& nums, int index) {
        if(index >= nums.size()) return 0;
        if(index == nums.size()-1) return nums[index];
        if(cache.find(index) != cache.end()) return cache[index];
        // Rob current house
        int rob = nums[index] + maxRob(nums, index+2);
        // Do not rob current house
        int no_rob = maxRob(nums, index+1);
        return cache[index] = max(rob, no_rob);
    }

    int rob(vector<int>& nums) {
        return maxRob(nums, 0);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    cout << sol.rob(nums) << endl; // Output: 4
    return 0;
}
