#include<iostream>
using namespace std;

// https://leetcode.com/problems/range-sum-query-immutable/
class NumArray {
public:
    vector<int> prefix;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n+1, 0);
        for(int i = 0; i < n; i++) prefix[i+1] = nums[i] + prefix[i];
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1] - prefix[left];
    }
};

int main() {
}