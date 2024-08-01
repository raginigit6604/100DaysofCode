#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1])
            return nums[i];
        }
        return -1;
    }
};
int main(){
    vector<int> arr = {1,3,4,2,2};
    Solution s;
    cout<<s.findDuplicate(arr)<<endl;
    return 0;

}