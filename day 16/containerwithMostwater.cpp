#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int ans = 0;
        while (left <= right) { // Changed condition to left < right
            ans = max(ans, min(nums[left], nums[right]) * (right - left));
            if (nums[left] < nums[right]) {
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = solution.maxArea(nums);
    cout << "Maximum area of water the container can contain is: " << result << endl;
    return 0;
}
