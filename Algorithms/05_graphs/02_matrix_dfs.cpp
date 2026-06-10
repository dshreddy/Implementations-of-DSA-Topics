#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void dfs_visit(vector<vector<char>>& grid, vector<vector<bool>> &visited, int i, int j) {
        if(min(i, j) < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || visited[i][j]) {
            return;
        }

        visited[i][j] = 1;

        dfs_visit(grid, visited, i+1, j);
        dfs_visit(grid, visited, i, j+1);
        dfs_visit(grid, visited, i, j-1);
        dfs_visit(grid, visited, i-1, j);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), Islands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    dfs_visit(grid, visited, i, j);
                    Islands++;
                }
            } 
        }

        return Islands;
    }
};

int main() {
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
