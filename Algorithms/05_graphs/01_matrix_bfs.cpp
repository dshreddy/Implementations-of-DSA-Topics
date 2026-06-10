#include<iostream>
#include<vector>
#include<set>
using namespace std;

int bfs(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();

    int visited[m][n];
    int distance[m][n];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            visited[i][j] = 0;
            distance[i][j] = -1;
        }
    }

    queue<pair<int,int>> q;

    if(matrix[0][0] == 1) {
        q.push({0,0});
        visited[0][0] = 1;
        distance[0][0] = 1;
    }

    while(!q.empty()) {
        int l = q.size();
        for(int i = 0; i < l; i++) {
            auto u = q.front();
            q.pop();

            vector<pair<int,int>> nbs = {
                {u.first+1, u.second}, 
                {u.first-1, u.second}, 
                {u.first, u.second+1},
                {u.first, u.second-1}
            };

            for(auto &v : nbs) {
                if(
                    min(v.first, v.second) < 0 || v.first >= m || v.second >= n || 
                    matrix[v.first][v.second] == 0 || 
                    visited[v.first][v.second]
                ) {
                    continue;
                }
                q.push({v.first, v.second});
                visited[v.first][v.second] = 1;
                distance[v.first][v.second] = distance[u.first][u.second] + 1;
            }
        }
    }

    return distance[m-1][n-1];
}

int main() {
    /*
        Given a 2D matrix of 0s and 1s, return the shortest distance from the top-left corner to the bottom-right corner.
        A single path may only move along cells containing 1s, and you can only move up, down, right, left.
    */
    vector<vector<int>> matrix = {
        {1, 0, 1, 1},
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 0, 1}
    };
    int result = bfs(matrix);
    cout << "Shortest distance: " << result << endl;
}
