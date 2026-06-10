#include<iostream>
using namespace std;

class Knapsack {
private:

    /**
     * TC : O(2^(N+C)) [Let's say there is an item "it" with weight 1, then the height of tree will be C (we can choose "it" C times)]
     * SC : O(N+C) [depth of the recursion tree]
     * Where C is the capacity of the knapsack
     */
    int bruteForceDFS(int i, int currentCapacity) {
        if(i >= N) return 0;

        // Skip current item
        int skip = bruteForceDFS(i+1, currentCapacity);
        
        // Include current item
        int include = 0;
        if(currentCapacity - weights[i] >= 0) {;
            include = values[i] + bruteForceDFS(i, currentCapacity-weights[i]);
        }

        return max(skip, include);
    }

    int getMaxProfitViaBruteForce() {
        return bruteForceDFS(0, C);
    }

    // O(N * C) time and space complexity
    int topDownDP(int i, int currentCapacity, vector<vector<int>> &cache) {
        if(i >= N) return 0;

        if(cache[i][currentCapacity] == -1) {

            // Skip current item
            int skip = topDownDP(i+1, currentCapacity, cache);
            
            // Include current item
            int include = 0;
            if(currentCapacity - weights[i] >= 0) {
                include = values[i] + topDownDP(i, currentCapacity - weights[i], cache);
            }

            cache[i][currentCapacity] = max(skip, include);
        }

        return cache[i][currentCapacity];
    }

    int getMaxProfitViaTopDownDP() {
        vector<vector<int>> cache(N, vector<int>(C + 1, -1));
        return topDownDP(0, C, cache);
    }

    // O(N*C) Time & Space compleixty 
    int bottomUpDP() {
        vector<vector<int>> dp(N + 1, vector<int>(C + 1, 0));
        int skip, include;

        for(int i = 1; i <= N; i++) {
            for(int c = 0; c <= C; c++) {
                // Skip current item
                skip = dp[i-1][c];
                
                // Include current item
                include = 0;
                if(c - weights[i-1] >= 0) include = values[i-1] + dp[i][c - weights[i-1]];
                dp[i][c] = max(skip, include);
            }
        }

        return dp[N][C];
    }

    int getMaxProfitViaBottomUpDP() {
        return bottomUpDP();
    }

public:

    int N, C;
    int *weights, *values;

    Knapsack(int N, int C, int weights[], int values[]) {
        this->N = N;
        this->C = C;
        this->weights = weights;
        this->values = values;
    }

    int getMaxProfit() {
        return getMaxProfitViaBottomUpDP();
    }
};

/**
 * Given a list of N items and a knapsack with capacity C,
 * Each item has a weight and a value, determine the maximum value that can be put in the knapsack.
 */
int main() {
    int N = 4, C = 8;
    int weights[] = {5, 2, 3, 1};
    int values[] = {4, 4, 7, 1};

    Knapsack k = Knapsack(N, C, weights, values);
    cout << k.getMaxProfit() << endl;
    return 0;
}