#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        int i = 0, j = 0;

        while (i < m && j < n) {
            int value = min(rowSum[i], colSum[j]);
            result[i][j] = value;
            rowSum[i] -= value;
            colSum[j] -= value;

            if (rowSum[i] == 0) {
                i++;
            }
            if (colSum[j] == 0) {
                j++;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> rowSum = {3, 8};
    vector<int> colSum = {4, 7};

    // Restore matrix
    vector<vector<int>> result = solution.restoreMatrix(rowSum, colSum);

    // Output the result matrix
    cout << "Restored Matrix:" << endl;
    for (const auto& row : result) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
