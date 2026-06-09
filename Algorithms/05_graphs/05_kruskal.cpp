#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;

class DSU {
private:
    unordered_map<char, char> parent;
    unordered_map<char, int> rankMap;

public:

    char findByPathCompression(char p) {
        if(parent.find(p) == parent.end())
            parent[p] = p;

        if(p != parent[p])
            parent[p] = findByPathCompression(parent[p]);

        return parent[p];
    }

    bool unionByRank(char c1, char c2) {
        char p1 = findByPathCompression(c1);
        char p2 = findByPathCompression(c2);

        if(p1 == p2)
            return false;

        if(rankMap.find(p1) == rankMap.end())
            rankMap[p1] = 0;

        if(rankMap.find(p2) == rankMap.end())
            rankMap[p2] = 0;

        if(rankMap[p1] < rankMap[p2]) {
            parent[p1] = p2;
        }
        else if(rankMap[p1] > rankMap[p2]) {
            parent[p2] = p1;
        }
        else {
            parent[p1] = p2;
            rankMap[p2]++;
        }

        return true;
    }
};

int main() {

    unordered_map<char, vector<pair<char,int>>> adj_list = {
        {'A', { {'B',10}, {'C',3} } },
        {'B', { {'D',2} } },
        {'C', { {'B',4}, {'D',8}, {'E',2} } },
        {'D', { {'E',5} } }
    };

    priority_queue<
        pair<int, pair<char,char>>,
        vector<pair<int, pair<char,char>>>,
        greater<pair<int, pair<char,char>>>
    > minHeap;

    for(auto& [node, neighbours] : adj_list) {
        for(auto& [neighbour, weight] : neighbours) {
            minHeap.push({weight, {node, neighbour}});
        }
    }

    DSU dsu;

    vector<pair<char,char>> mst_edges;

    while(!minHeap.empty()) {

        auto [weight, edge] = minHeap.top();
        minHeap.pop();

        char u = edge.first;
        char v = edge.second;

        if(dsu.unionByRank(u, v)) {
            mst_edges.push_back({u, v});
        }
    }

    cout << "Edges in the Minimum Spanning Tree:\n";

    for(auto& [u, v] : mst_edges) {
        cout << u << " - " << v << endl;
    }
}