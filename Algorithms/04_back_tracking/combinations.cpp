#include<iostream>
#include<vector>
using namespace std;

// O(k * C(n, k)) - where C(n, k) is the number of combinations of n things taken k at a time
void getAllCombinations(int n, int k, int i, vector<int> currentCombination, vector<vector<int>> &allCombinations) {
    if(currentCombination.size() == k) {
        allCombinations.push_back(currentCombination);
        return;
    }
    if(i > n) return;

    for(int j = i; j <= n; j++) {
        currentCombination.push_back(j);
        getAllCombinations(n, k, j+1, currentCombination, allCombinations);
        currentCombination.pop_back();
    } 
}

int main() {
    int n = 4, k = 2;
    vector<vector<int>> allCombinations;
    getAllCombinations(n, k, 1, {}, allCombinations);

    cout << "All combinations of " << n << " things taken " << k << " at a time:" << endl;
    for(const auto &combination : allCombinations) {
        for(int num : combination) {
            cout << num << "\t";
        }        
        cout << "\n";
    }
    return 0;
}