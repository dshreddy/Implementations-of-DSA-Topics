#include<iostream>
#include<vector>
using namespace std;

// ======================== STL ========================
void printPermutationsUsingSTL(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    do {
        for (int num : nums) cout << num << "\t";
        cout << endl;
    } while (next_permutation(nums.begin(), nums.end()));
}

// ======================== STL Implementation ========================
/**
 * @brief Generates the next lexicographically greater permutation of a sequence
 * @param nums Reference to the vector of integers
 * @return true if a next permutation exists, false otherwise
 * 
 * The algorithm assumes the input array as a single number and generates the next greater number. 
 * If such arrangement is not possible, it returns false, indicating that the input is the highest possible permutation.
 * 
 * Example: 
 * 
 * nextPermutation({1, 2, 3, 4, 5}) => Output: {1, 2, 3, 5, 4}
 * 
 * nextPermutation({1, 2, 3, 5, 4}) => Output: {1, 2, 4, 3, 5}
 * 
 * Next highest possible number we can get from the numbers set {1, 2, 3, 4, 5} 
 * 
 * for 12345 is 12354
 * 
 * for 12354 is 12435
 * 
 * 12345 < 12354 < 12435
 */
bool nextPermutation(vector<int> &nums) {

    int n = nums.size(), pivot = -1;

    // Find the 1st element from right which is less than it's previous element
    for(int i = n-2; i >= 0; i--) {
        if(nums[i] < nums[i+1]) {
            pivot = i;
            break;
        }
    }

    // No pivot implies nums is in decreasing order, Ex: nums = {4,3,2,1}
    if(pivot == -1) {
        reverse(nums.begin(), nums.end());
        return false;
    }

    // Find the first element which is greater than the pivot element from right
    int index = -1;
    for(int i = n-1; i > pivot; i--) {
        if(nums[i] > nums[pivot]) {
            index = i;
            break;
        }
    }

    swap(nums[pivot], nums[index]);
    reverse(nums.begin() + pivot + 1, nums.end());
    return true;
}

// ======================== Brute Force ========================
/**
 * TC : O(n^2 * n!)
 * The algorithm works as follows :
 * 1. Take all possible permutations from the arr[i+1, n-1]
 * 2. Insert nums[i] in all those permutations at all possible positions 
 * Example : 
 * [1,2,3,4]
 * {{4}} => {{3,4}, {4,3}} => {{2,3,4}, {3,2,4}, {3,4,2}, {2,4,3}, {4,2,3}, {4,3,2}} => ...
 */
vector<vector<int>> getAllPermutationsBruteForce(vector<int> &nums, int i) {

    if(i == nums.size()-1) return {{nums[nums.size()-1]}};

    vector<vector<int>> previousPermutations = getAllPermutationsBruteForce(nums, i+1);
    int p = previousPermutations.size();

    vector<vector<int>> nextPermutations = {};
    for(int j = 0; j < p; j++) {
        for(int k = 0; k < p+1; k++) {
            vector<int> nextPermutation = previousPermutations[j];
            nextPermutation.push_back(nums[i]);
            swap(nextPermutation[k], nextPermutation[p]);
            nextPermutations.push_back(nextPermutation);
        }
    }

    return nextPermutations;
}

vector<vector<int>> getAllPermutationsBruteForceIterative(vector<int> &nums) {

    int n = nums.size();
    vector<vector<int>> previousPermutations = {{nums[0]}};

    for(int i = 1; i < n; i++) {

        vector<vector<int>> nextPermutations = {};
        int p = previousPermutations.size();
        
        for(int j = 0; j < p; j++) {

            vector<int> previousPermutation = previousPermutations[j];

            for(int k = 0; k < p+1; k++) {
                vector<int> newPermutation = previousPermutation;
                newPermutation.push_back(nums[i]);
                swap(newPermutation[k], newPermutation[p]);
                nextPermutations.push_back(newPermutation);
            }
        }
        
        previousPermutations = nextPermutations;
    }

    return previousPermutations;
}



int main() {
    vector<int> nums = {1, 2, 3};
    // printPermutationsUsingSTL(nums);

    do {
        for(auto n: nums) cout<<n<<"\t";
        cout<<"\n";
    } while(nextPermutation(nums));

    cout << "\n\n";

    vector<vector<int>> permutations = getAllPermutationsBruteForce(nums, 0);
    for(auto &p : permutations) {
        for(auto n: p) cout << n << "\t";
        cout << "\n";
    }

    return 0;
}