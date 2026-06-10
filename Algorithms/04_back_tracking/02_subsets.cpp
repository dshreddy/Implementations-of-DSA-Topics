#include<iostream>
#include<vector>
using namespace std;

// O(2^n)
void getAllSubsets(vector<int> &arr, int i, vector<vector<int>> &allSubsets, vector<int> currentSubset) {
    if(i >= arr.size()) {
        allSubsets.push_back(currentSubset);
        return;
    }

    // Decision to include arr[i]
    currentSubset.push_back(arr[i]);
    getAllSubsets(arr, i+1, allSubsets, currentSubset);
    currentSubset.pop_back(); 

    // Decision to exclude arr[i]
    while(i+1 < arr.size() && arr[i] == arr[i+1]) i++;
    getAllSubsets(arr, i+1, allSubsets, currentSubset);
}

int main() {
    vector<int> arr = {1, 2, 2, 3};
    vector<vector<int>> allSubsets;
    vector<int> subset;

    // getAllSubsets expects a sorted array to handle duplicates properly 
    sort(arr.begin(), arr.end());
    getAllSubsets(arr, 0, allSubsets, subset);

    cout << "All subsets are: " << endl;
    for(const auto &s : allSubsets) {
        cout << "[";
        for(int num : s) {
            cout << num << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}