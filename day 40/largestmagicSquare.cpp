#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     bool isMagicSquare(const vector<vector<int>>& grid, int r, int c, int k) {
        int sum = 0;

        for (int j = 0; j < k; ++j) {
            sum += grid[r][c + j];
        }

        for (int i = 0; i < k; ++i) {
            int row_sum = 0;
            for (int j = 0; j < k; ++j) {
                row_sum += grid[r + i][c + j];
            }
            if (row_sum != sum) return false;
        }

        for (int j = 0; j < k; ++j) {
            int col_sum = 0;
            for (int i = 0; i < k; ++i) {
                col_sum += grid[r + i][c + j];
            }
            if (col_sum != sum) return false;
        }

        int diag1_sum = 0;
        for (int i = 0; i < k; ++i) {
            diag1_sum += grid[r + i][c + i];
        }

        if (diag1_sum != sum) return false;
        int diag2_sum = 0;
        for (int i = 0; i < k; ++i) {
            diag2_sum += grid[r + i][c + k - 1 - i];
        }
        if (diag2_sum != sum) return false;

        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (m == 0 || n == 0) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int max_size = 0;

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int max_k = min(m - i, n - j);  
                for (int k = 1; k <= max_k; ++k) {
                    if (isMagicSquare(grid, i, j, k)) {
                        dp[i][j] = k;
                        max_size = max(max_size, k);
                    }
                }
            }
        }
        
        return max_size;
    }
};
int main(){
     vector<vector<int>> grid = {
        {7, 1, 4, 5, 6},
        {2, 5, 1, 6, 4},
        {1, 5, 4, 3, 2},
        {1, 2, 7, 3, 4}
    };
    
    Solution solution;
    int result = solution.largestMagicSquare(grid);
    cout << "The size of the largest magic square is: " << result << endl;
    return 0;
}
