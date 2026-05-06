#include<iostream>
using namespace std;

int main() {
    
    // adj_matrx[i][j] = 1 implies that there is a node between nodes/vertices i & j
    // If the graph is un directed then adj_matrx[i][j] = adj_matrx[j][i]
    /*
        0 - 1
        |   |
        2 - 3
        |
        4
    */
    const int nodes = 5;
    int adj_matrx[nodes][nodes] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
}
