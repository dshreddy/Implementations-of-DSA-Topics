#include<iostream>
#include<vector>
#include<set>
using namespace std;

/**
 * Time Complexity: O(4^(m*n)) in the worst case, where m and n are the dimensions of the matrix. This is because in the worst case, we may explore all possible paths from the top-left corner to the bottom-right corner.
 * Space Complexity: O(m*n) in the worst case, due to the recursion stack and the visited matrix. In the worst case, we may explore all cells in the matrix, leading to a recursion depth of m*n and a visited matrix of size m*n.
 * 
 *                                                  (0,0)
 *               /                            /              \        \ 
 *            (1,0)                        (0,1)           (0,-1)   (-1,0)
 *       /   /     \     \          /     /    \     \
 *   (2,0) (1,1) (1,-1) (0,0)     (1,1) (0,2) (0,0) (-1,1)
 */
int dfs(vector<vector<int>> &matrix, set<pair<int,int>> &path, int m, int n, int i, int j) {

    if(min(i, j) < 0 || i >= m || j >= n || matrix[i][j] == 0 || path.count({i, j})) return 0;
    if(i == (m-1) && j == (n-1)) return 1;

    path.insert({i, j});
    int paths = 0;

    paths += dfs(matrix, path, m, n, i+1, j);
    paths += dfs(matrix, path, m, n, i, j+1);
    paths += dfs(matrix, path, m, n, i, j-1);
    paths += dfs(matrix, path, m, n, i-1, j);

    path.erase({i, j});
    return paths;
}

int main() {
    /*
        Given a 2D matrix of 0s and 1s, count the unique paths from the top-left corner to the bottom-right corner.
        A single path may only move along cells containing 1s, and you can only move up, down, right, left.
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
