#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> rowMin(m, INT_MAX);
        vector<int> colMax(n, INT_MIN);
        
        // Find the minimum in each row
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowMin[i] = min(rowMin[i], matrix[i][j]);
            }
        }
        
        // Find the maximum in each column
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }
        
        // Find the lucky numbers
        vector<int> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    result.push_back(matrix[i][j]);
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> matrix1 = {{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
    vector<vector<int>> matrix2 = {{1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}};
    vector<vector<int>> matrix3 = {{7, 8}, {1, 2}};
    
    vector<int> result1 = sol.luckyNumbers(matrix1);
    vector<int> result2 = sol.luckyNumbers(matrix2);
    vector<int> result3 = sol.luckyNumbers(matrix3);
    
    cout << "Lucky numbers in matrix1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Lucky numbers in matrix2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Lucky numbers in matrix3: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
