#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i] >= target){
                return i;
            }
        }
        return n;
    }
};
int main(){
    vector<int> arr = {1,3,5,6};
    int target = 5;
    Solution s;
    int result = s.searchInsert(arr,target);
    cout<<result<<endl;
    return 0;
}