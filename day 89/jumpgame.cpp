#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
   // Smart approach
   bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_reach = 0;
        for(int i=0;i<n;i++){
            if(i > max_reach) {
               return false;
            }
            max_reach = max(max_reach, i + nums[i]);
        }
        return true;
   }

   // Uncomment and use any of the other methods (bottom-up or memoization) as needed.
   // Bottom-up approach
   /*
   bool canJump(vector<int>& nums) {
       int n = nums.size();
       vector<bool> t(n, false);
       t[0] = true;
       for(int i=1; i<n; i++) {
           for(int j=i-1; j>=0; j--) {
               if(t[j] && j + nums[j] >= i) {
                   t[i] = true;
                   break;
               }
           }
       }
       return t[n-1];
   }
   */

   // Memoization approach
   /*
   int t[10001]; // we take 10001 because max constraint is 10^4
   bool solve(vector<int>& nums, int n, int index) {
       if(index == n - 1) {
           return true;
       }
       if(t[index] != -1) {
           return t[index];
       }
       for(int i = 1; i <= nums[index]; i++) {
           if(solve(nums, n, index + i)) {
               return t[index] = true;
           }
       }
       return t[index] = false;
   }
   
   bool canJump(vector<int>& nums) {
       int n = nums.size();
       memset(t, -1, sizeof(t));
       return solve(nums, n, 0); // here 0 is starting index
   }
   */
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test Case 1: " << (sol.canJump(nums1) ? "Can Jump" : "Cannot Jump") << endl;

    // Test case 2
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Test Case 2: " << (sol.canJump(nums2) ? "Can Jump" : "Cannot Jump") << endl;

    // Test case 3
    vector<int> nums3 = {0};
    cout << "Test Case 3: " << (sol.canJump(nums3) ? "Can Jump" : "Cannot Jump") << endl;

    return 0;
}
