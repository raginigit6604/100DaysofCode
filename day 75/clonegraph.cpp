#include <iostream>
#include <vector>

using namespace std;

// Solution class with xorQueries function
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = arr.size();
        // Precompute the XOR prefix array
        vector<int> pre_sum(n);
        pre_sum[0] = arr[0];

        // Fill the prefix XOR array
        for (int i = 1; i < n; i++) {
            pre_sum[i] = pre_sum[i - 1] ^ arr[i];
        }

        // Process each query
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            if (start == 0) {
                ans.push_back(pre_sum[end]);
            } else {
                ans.push_back(pre_sum[start - 1] ^ pre_sum[end]);
            }
        }
        return ans;
    }
};

// Main function to test the xorQueries function
int main() {
    // Example input
    vector<int> arr = {1, 3, 4, 8};
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};

    // Create an instance of the solution class
    Solution solution;

    // Get the result by calling the xorQueries function
    vector<int> result = solution.xorQueries(arr, queries);

    // Output the result
    cout << "XOR Queries Result: ";
    for (int res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
