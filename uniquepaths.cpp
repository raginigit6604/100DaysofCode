#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int t[101][101]; // Memoization table

    // Helper function to calculate the number of unique paths
    int solve(int m, int n, int i, int j) {
        // Out of bounds
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }
        // Reached the bottom-right corner
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        // If already computed, return the stored value
        if (t[i][j] != -1) {
            return t[i][j];
        }

        // Calculate the number of unique paths by moving right and down
        int right = solve(m, n, i, j + 1);
        int bottom = solve(m, n, i + 1, j);

        // Store the result in the memoization table
        return t[i][j] = right + bottom;
    }

    // Main function to calculate the number of unique paths
    int uniquePaths(int m, int n) {
        // Initialize the memoization table with -1
        memset(t, -1, sizeof(t));
        // Start the recursion from the top-left corner
        return solve(m, n, 0, 0);
    }
};

// Main function to test the uniquePaths function
int main() {
    Solution sol;
    int m = 3, n = 7; // Example grid dimensions
    cout << "Number of unique paths from top-left to bottom-right: " << sol.uniquePaths(m, n) << endl;
    return 0;
}
