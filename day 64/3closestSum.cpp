#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());  
        int closestSum = INT_MAX; 
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;  // to skip duplicates
            }
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                if (closestSum == INT_MAX || abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                if (currentSum == target) {
                    return currentSum;  
                } else if (currentSum < target) {
                    left++; 
                } else {
                    right--;  
                }
            }
        }
        
        return closestSum;
    }
};
int main(){
    vector<int> arr = {-1,2,1,-4};
    int target = 1;
    Solution s;
    cout<<s.threeSumClosest(arr,target)<<endl;
    return 0;
}