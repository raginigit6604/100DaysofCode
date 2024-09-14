#include <iostream>
#include <vector>
#include <algorithm> // for max_element
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end()); // Find the maximum element in the array
        int result = 0, currentLength = 0;

        // Traverse the array to find the longest subarray consisting of the maximum element
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxNum) {
                currentLength++; // Increase we length if current element equals the maximum
                result = max(result, currentLength); 
            } else {
                currentLength = 0; // we reset the length if current element is not the maximum
            }
        }
        
        return result;
    }
};

int main() {
    // Test input: nums = [1, 2, 3, 3, 2, 2]
    vector<int> nums = {1, 2, 3, 3, 2, 2};
    
    // Create an object of Solution class
    Solution sol;
    
    // Call longestSubarray function and store the result
    int result = sol.longestSubarray(nums);
    
    // Output the result
    cout << "The longest subarray with the maximum element is: " << result << endl;

    return 0;
}
