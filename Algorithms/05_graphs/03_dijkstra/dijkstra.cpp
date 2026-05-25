#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
    unordered_map<char, vector<pair<char,int>>> adj_list = {
        {'A', { {'B',10}, {'C',3} } },
        {'B', { {'D',2} } },
        {'C', { {'B',4}, {'D',8}, {'E',2} } },
        {'D', { {'E',5} } }
    };

    /**
     * Dijkstra's algorithm 
     * Time complexity: O(E log V) where E is the number of edges and V is the number of vertices [O(E log E ) ~ O(E log V^2 ) ~ O(E log V)]
     * Space complexity: O(V) for the distance map and for the priority queue
     */
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> minHeap;
    unordered_map<char, int> distanceMap;
    minHeap.push({0, 'A'});

    char u, v;
    int distance, weight;
    while(!minHeap.empty()) {

        auto p = minHeap.top();
        minHeap.pop();

        u = p.second;
        distance = p.first;

        if(distanceMap.find(u) != distanceMap.end()) continue;

        distanceMap[u] = distance;

        for(auto p: adj_list[u]) {

            v = p.first;
            weight = p.second;
            
            if(distanceMap.find(v) != distanceMap.end()) continue;
            minHeap.push({distance + weight, v});
        }
    }

    for(auto p: distanceMap) {
        cout << "Distance from A to " << p.first << " is " << p.second << endl;
    }

    return 0;
}