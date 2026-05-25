#include<iostream>
#include<vector>
#include<set>
using namespace std;

/**
 * Time Complexity: O(2^(m*n)) for brute-force, 
 * Space Complexity: O(m+n) for brute-force
 */
int brute_force(vector<vector<int>> &matrix, int i, int j) {
    if(i == matrix.size() || j = matrix[0].size()) return 0;
    if(i == matrix.size()-1 && j = matrix[0].size()-1) return 1;
    return brute_force(matrix, i-1, j) + brute_force(matrix, i, j+1);
}

/**
 * Time Complexity: O(m*n) 
 * Space Complexity: O(m*n) 
 */
int memoization(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &cache) {
    if(i == matrix.size() || j = matrix[0].size()) return 0;
    if(i == matrix.size()-1 && j = matrix[0].size()-1) return 1;
    if(cache[i][j] != -1) return cache[i][j];
    return cache[i][j] = memoization(matrix, i-1, j, cache) + memoization(matrix, i, j+1, cache);
}

int main() {
    /*
        Given a 2D matrix of 0s and 1s, count the unique paths from the top-left corner to the bottom-right corner.
        A single path may only move along cells containing 1s, and you can only move down or right.
    */
    vector<vector<int>> matrix = {
        {1, 0, 1, 1},
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 0, 1}
    };
    int m = matrix.size(), n = matrix[0].size();
    set<pair<int,int>> path;

    int result = dfs(matrix, path, m, n, 0, 0);
    cout << "Number of unique paths: " << result << endl;
}
