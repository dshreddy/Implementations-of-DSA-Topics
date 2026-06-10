#include<iostream>
using namespace std;

void topologicalSort(unordered_map<int, vector<int>> &graph) {

    unordered_map<int, int> inDegree;
    for (auto &node : graph) {
        if(!inDegree.count(node.first)) inDegree[node.first] = 0;
        for (auto &neighbor : node.second) inDegree[neighbor]++;
    }

    queue<int> q;
    for(auto p: inDegree) if(p.second == 0) q.push(p.first);

    cout << "Topological Sort: ";
    while (!q.empty()) {

        int current = q.front();
        q.pop();

        cout << current << "\t";

        for (auto &neighbor : graph[current]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) q.push(neighbor);
        }
    }
    cout<<endl;
}

int main(){
    unordered_map<int, vector<int>> graph;
    graph[0] = {1, 2};
    graph[1] = {3};
    graph[2] = {3}; 
    topologicalSort(graph);
    return 0;
}