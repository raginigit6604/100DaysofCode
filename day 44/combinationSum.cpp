#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int>& curr, int idx, vector<vector<int>>& result) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            result.push_back(curr);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            solve(candidates, target - candidates[i], curr, i, result); // Note: Change i+1 to i to allow for reuse of the same element
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        solve(candidates, target, curr, 0, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    
    vector<vector<int>> result = sol.combinationSum(candidates, target);
    
    // Print the result
    cout << "Combinations that sum up to " << target << " are:" << endl;
    for (const auto& combination : result) {
        cout << "[ ";
        for (const auto& num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
