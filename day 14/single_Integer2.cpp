#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
            if (count == 1) {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums1 = {2, 2, 3, 2};
    vector<int> nums2 = {0, 1, 0, 1, 0, 1, 99};
    
  cout << "The single number in the first test case is: " << solution.singleNumber(nums1) << endl; // Output: 3
   cout << "The single number in the second test case is: " << solution.singleNumber(nums2) << endl; // Output: 99
    
    return 0;
}
