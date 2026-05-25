#include<iostream>
#include<set>
using namespace std;

/**
 * Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph.
 * Time complexity: O(E log V) where E is the number of edges and V is the number of vertices.
 * Space complexity: O(E) for the visited set and O(E) for the priority queue
*/
int main() {

    /**
     *             E <---
     *             ^      2  
     *             2       \
     *             |        \
     * A --- 3 --> C -- 8 -> D
     *  \          |        ^
     *   \         4       2
     *    10       V     /
     *      -----> B ----
     *  
     */
    unordered_map<char, vector<pair<char,int>>> adj_list = {
        {'A', { {'B',10}, {'C',3} } },
        {'B', { {'D',2} } },
        {'C', { {'B',4}, {'D',8}, {'E',2} } },
        {'D', { {'E',5} } }
    };

    priority_queue<
        pair<int, pair<char, char>>, 
        vector<pair<int, pair<char, char>>>, 
        greater<pair<int, pair<char, char>>>
    > minHeap;
    set<char> visited;
    vector< pair<int, pair<char, char>> > mstEdges;

    // Initialise the heap
    visited.insert('A');
    for(auto edge: adj_list['A']) minHeap.push({edge.second, {'A', edge.first}});

    while(!minHeap.empty()) {

        auto p = minHeap.top();
        minHeap.pop();

        char v = p.second.second;
        if(visited.find(v) != visited.end()) continue;

        visited.insert(v);
        mstEdges.push_back(p);

        for(auto edge: adj_list[v]) {
            if(visited.find(edge.first) != visited.end()) continue;
            minHeap.push({edge.second, {v, edge.first}});
        }
    }
    
    cout<<"Minimum Spanning Tree: \n";
    for(auto mstEdge: mstEdges) cout<<mstEdge.first<<"\t"<<mstEdge.second.first<<"\t"<<mstEdge.second.second<<endl;
    cout<<endl;
}