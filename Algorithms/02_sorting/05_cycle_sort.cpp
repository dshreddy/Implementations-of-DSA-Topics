#include<iostream>
using namespace std;

void cycleSort(vector<int> &nums) {
    int n = nums.size(), final_index;
    for(int i = 0; i < n; i++) {
        if(nums[i] == i+1) continue;
        else {
            final_index = nums[i]-1;
            // left side is always sorted (invariant) [arr[0], arr[1], arr[2], ... , arr[i-1]] 
            // Swapping left is not possible, as the element at final_index is already in its correct position 
            if(final_index < i) swap(nums[final_index], nums[i]);
            else {
                swap(nums[final_index], nums[i]);
                // Decrementing i to check the current index again, as the swapped element might also be out of place
                i--; 
            }
        }
    }
}

int main() {
    /*
        Given an array of size n, containing n unique intergers in the range [1, n]
        Sort the array in-place with O(1) extra space and O(n) time complexity.
    */
    vector<int> v = {5,3,2,4,1};
    cycleSort(v);

    for(int i : v) cout << i << "\t";
    cout<<endl;

    return 0;
}