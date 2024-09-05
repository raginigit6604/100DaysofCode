#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool solve (const vector<int>& nums, int cuts, long long max) {
        int sol = 0;
        for (auto num : nums) {
            if (num > max) return false;
            else if (sol + num <= max) sol += num;
            else {
                cuts--;
                sol = num;
                if (cuts < 0){ 
                    return false;
                }
            }
        }
        return true;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (auto num : nums) {
            left = max(left, (long long)num);
            right += num;
        }
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (solve(nums, m - 1, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
    int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {7, 2, 5, 10, 8};
    int m1 = 2;
    cout << "Minimum largest sum for Example 1: " << solution.splitArray(nums1, m1) << endl; // Expected Output: 18

    // Example 2
    vector<int> nums2 = {1, 2, 3, 4, 5};
    int m2 = 2;
    cout << "Minimum largest sum for Example 2: " << solution.splitArray(nums2, m2) << endl; // Expected Output: 9

    // Add more test cases as needed

    return 0;
}