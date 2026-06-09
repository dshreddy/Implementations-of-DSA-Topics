#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>> &visited, int i, int j) {
        if(min(i, j) < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || visited[i][j]) {
            return;
        }

        visited[i][j] = 1;

        dfs(grid, visited, i+1, j);
        dfs(grid, visited, i, j+1);
        dfs(grid, visited, i, j-1);
        dfs(grid, visited, i-1, j);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), Islands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, i, j);
                    Islands++;
                }
            } 
        }

        return Islands;
    }
};

int main() {
    /*
        Given a 2D matrix of 0s and 1s, count the unique paths from the top-left corner to the bottom-right corner.
        A single path may only move along cells containing 1s, and you can only move up, down, right, left.
    */
    vector<vector<char>> matrix = {
        {'1', '0', '1', '1'},
        {'1', '1', '1', '0'},
        {'0', '1', '1', '1'},
        {'1', '0', '0', '1'}
    };
    int m = matrix.size(), n = matrix[0].size();
    Solution solution;
    cout << "Number of islands: " << solution.numIslands(matrix) << endl;
}
