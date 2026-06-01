#include<iostream>
using namespace std;

class Knapsack {
private:

    /**
     * TC : O(2^N) [each item can be either included or excluded i.e 2 * 2 * 2 ... N times]
     * SC : O(N) [depth of the recursion tree]
     * Where N is the number of items
     */
    int bruteForceDFS(int i, int currentProfit, int currentCapacity) {
        if(i >= N) return currentProfit;

        int maxProfit = 0;

        // Skip current item
        maxProfit = max(maxProfit, bruteForceDFS(i+1, currentProfit, currentCapacity));
        
        // Include current item
        if(currentCapacity - weights[i] >= 0) {
            currentProfit += values[i];
            currentCapacity -= weights[i];
            maxProfit = max(maxProfit, bruteForceDFS(i+1, currentProfit, currentCapacity));
        }

        return maxProfit;
    }

    int getMaxProfitViaBruteForce() {
        return bruteForceDFS(0, 0, C);
    }

    // O(N * C) time and space complexity
    int dfsWithMemoization(int i, int currentProfit, int currentCapacity, vector<vector<int>> &cache) {
        if(i >= N) return currentProfit;
        if(cache[i][currentCapacity] != -1) return cache[i][currentCapacity];

        int maxProfit = 0;

        // Skip current item
        maxProfit = max(maxProfit, bruteForceDFS(i+1, currentProfit, currentCapacity));
        
        // Include current item
        if(currentCapacity - weights[i] >= 0) {
            currentProfit += values[i];
            currentCapacity -= weights[i];
            maxProfit = max(maxProfit, bruteForceDFS(i+1, currentProfit, currentCapacity));
        }

        cache[i][currentCapacity] = maxProfit;
        return maxProfit;
    }

    int getMaxProfitViaMemoization() {
        vector<vector<int>> cache(N, vector<int>(C + 1, -1));
        return dfsWithMemoization(0, 0, C, cache);
    }

    // O(N*C) Time & Space compleixty 
    int topDownDP() {
        vector<vector<int>> dp(N + 1, vector<int>(C + 1, 0));
        int skip, include;

        for(int i = 1; i <= N; i++) {
            for(int c = 0; c <= C; c++) {
                // Skip current item
                skip = dp[i-1][c];
                
                // Include current item
                include = 0;
                if(c - weights[i-1] >= 0) include = values[i-1] + dp[i-1][c - weights[i-1]];
                dp[i][c] = max(skip, include);
            }
        }

        return dp[N][C];
    }

    int getMaxProfitViaBottomUpDP() {
        return topDownDP();
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
        return topDownDP();
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