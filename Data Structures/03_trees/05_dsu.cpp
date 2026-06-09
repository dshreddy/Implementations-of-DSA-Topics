#include<iostream>
using namespace std;

class DSU{
private:
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;

public:
    DSU(int v) {
        for(int i = 1; i <= v; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // O(1) [find by path compression]
    int find(int p) {
        if(p != parent[p]) parent[p] = find(parent[p]);
        return parent[p];
    }

    // O(1) [union by rank]
    bool Union(int u, int v) {
        int p1 = find(u), p2 = find(v);
        if(p1 == p2) return false;

        if(rank[p1] < rank[p2]) parent[p1] = p2;
        else if (rank[p1] > rank[p2]) parent[p2] = p1;
        else {
            parent[p1] = p2;
            rank[p2]++;
        }
        return true;
    }
};

// https://leetcode.com/problems/redundant-connection/
// O(m)
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int m = edges.size(), n = m-1;
    DSU dsu = DSU(n);
    for(auto &edge: edges) {
        int u = edge[0], v = edge[1];
        if(!dsu.Union(u, v)) return edge;
    }
    return {-1,-1};
}

int main() {

}