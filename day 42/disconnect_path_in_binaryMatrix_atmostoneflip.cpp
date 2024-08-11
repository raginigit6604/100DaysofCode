#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Forward checking
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0 || grid[i][j] == 0) continue;
                if ((i == 0 || grid[i-1][j] == 0) && (j == 0 || grid[i][j-1] == 0)) {
                    grid[i][j] = 0;
                }
            }
        }

        // Backwards checking
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == m-1 && j == n-1 || grid[i][j] == 0) continue;
                if ((i == m-1 || grid[i+1][j] == 0) && (j == n-1 || grid[i][j+1] == 0)) {
                    grid[i][j] = 0;
                }
            }
        }

        // Diagonal counting
        vector<int> diagonal(m+n-1, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) diagonal[i+j]++;
            }
        }

        // Final count check
        for (int i = 1; i < m+n-2; i++) {
            if (diagonal[i] < 2) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    cout << boolalpha << sol.isPossibleToCutPath(grid) << endl;
    return 0;
}
