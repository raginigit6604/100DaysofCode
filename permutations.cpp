#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Using Recursion concept
    void permutation(vector<int>& num, int i, vector<vector<int>>& result) { // i is iterator
        int n = num.size();
        if (i == n) {
            result.push_back(num);
            return;
        }
        for (int j = i; j < n; j++) {
            swap(num[i], num[j]);
            permutation(num, i + 1, result);
            swap(num[j], num[i]);  // swap for backtracking 
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permutation(nums, 0, result);
        return result;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> permutations1 = sol.permute(nums1);
    
    cout << "Permutations of [1, 2, 3]:" << endl;
    for (const auto& perm : permutations1) {
        cout << "[";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;
    
    // Example 2
    vector<int> nums2 = {0, 1};
    vector<vector<int>> permutations2 = sol.permute(nums2);
    
    cout << "Permutations of [0, 1]:" << endl;
    for (const auto& perm : permutations2) {
        cout << "[";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;
    
    // Example 3
    vector<int> nums3 = {1};
    vector<vector<int>> permutations3 = sol.permute(nums3);
    
    cout << "Permutations of [1]:" << endl;
    for (const auto& perm : permutations3) {
        cout << "[";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;
    
    return 0;
}
