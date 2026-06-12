#include<iostream>
using namespace std;

// https://leetcode.com/problems/range-sum-query-2d-immutable/
class NumMatrix {
public:
    vector<vector<int>> prefix;

    NumMatrix(vector<vector<int>>& matrix) {

        int m = matrix.size(), n = matrix[0].size();
        prefix.resize(m+1, vector<int>(n+1, 0));

        int rowSum;

        for(int i = 0; i < m; i++) {
            rowSum = 0;
            for(int j = 0; j < n; j++) {
                rowSum += matrix[i][j];
                prefix[i+1][j+1] = rowSum + prefix[i][j+1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        row1++;
        col1++;
        row2++;
        col2++;

        int a = prefix[row2][col2];
        int b = prefix[row2][col1-1];
        int c = prefix[row1-1][col2];
        int d = prefix[row1-1][col1-1];

        return a-b-c+d;
    }
};

int main() {
}