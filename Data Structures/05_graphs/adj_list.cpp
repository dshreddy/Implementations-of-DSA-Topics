#include<iostream>
using namespace std;

void dfs_visit(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, int node) {
    if(visited[node]) return;
    visited[node] = true;

    for(int nb : adj[node]) dfs_visit(adj, visited, nb);
}

void dfs(unordered_map<int, vector<int>> &adj) {

    unordered_map<int, bool> visited;

    for(auto &p : adj) {
        int node = p.first;
        if(!visited[node]) {
            dfs_visit(adj, visited, node);
        }
    }

    cout << "\n";
}

void bfs(unordered_map<int, vector<int>> &adj, int start) {

    if(adj.find(start) == adj.end()) return;

    unordered_map<int, int> distance;
    unordered_map<int, bool> visited;
    queue<int> q;

    q.push(start);
    visited[start] = true;
    distance[start] = 0;

    while(!q.empty()) {

        int l = q.size();

        for(int i = 0; i < l; i++) {

            int node = q.front();
            q.pop();

            for(int nb : adj[node]) {
                if(!visited[nb]) {

                    q.push(nb);
                    visited[nb] = true;
                    distance[nb] = distance[node] + 1;
                }
            }
        }
    }
    for(const auto &p : distance) {
        cout << "Distance between " << start << " and " << p.first << " is " << p.second << "\n";
    }
    cout << "\n";
}

int main() {
    
    unordered_map<int, vector<int>> adj_list;
    /*
        0 - 1
        |   |
        2 - 3
        |
        4
    */
    adj_list[0] = {1, 2};
    adj_list[1] = {0, 2, 3};
    adj_list[2] = {0, 1, 3, 4};
    adj_list[3] = {1, 2};
    adj_list[4] = {2};

    cout << "DFS Traversal: ";
    dfs(adj_list);  
    cout<<"\n";
    
    cout << "BFS Traversal: \n";
    bfs(adj_list, 0);
    bfs(adj_list, 4);
}
