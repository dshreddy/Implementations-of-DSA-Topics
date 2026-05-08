#include<iostream>
#include<vector>
using namespace std;

void dfs_visit(vector<vector<int>> &adj, vector<int> &visited, int node) {

    int n = adj.size();
    if(visited[node] || node < 0 || node >= n) return;
    cout << node << "\t";
    visited[node] = 1;

    for(int nb = 0; nb < n; nb++) {
        if(adj[node][nb]) {
            dfs_visit(adj, visited, nb);
        }
    }
}

void dfs(vector<vector<int>> &adj) {

    int n = adj.size();
    vector<int> visited(n, 0);

    for(int node = 0; node < n; node++) {
        if(!visited[node]) {
            dfs_visit(adj, visited, node);
        }
    }

    cout << "\n";
}

void bfs(vector<vector<int>> &adj, int start) {

    int n = adj.size();
    if(start < 0 || start >= n) return;

    vector<int> distance(n, -1);
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;
    distance[start] = 0;

    while(!q.empty()) {

        int l = q.size();

        for(int i = 0; i < l; i++) {

            int node = q.front();
            q.pop();

            for(int nb = 0; nb < n; nb++) {
                if(adj[node][nb] && !visited[nb]) {

                    q.push(nb);
                    visited[nb] = true;
                    distance[nb] = distance[node] + 1;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) cout<<"Distance between "<<start<<" and "<<i<<" is "<<distance[i]<<"\n";
    cout<<"\n";
}

int main() {

    /*
        0 -- 1
        |    |
        2 -- 3
        |    
        4 
    */
    vector<vector<int>> adj = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    dfs(adj);
    cout<<"\n";
    bfs(adj, 0);
    bfs(adj, 4);
}
