#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int idx = -1;
        for(int i=0;i<n;i++){
            if(nums[i] == target){
                idx = i;
            }
        }
        return idx;
    }
};
int main(){
    Solution s;
    vector<int> arr = {-1,0,3,5,9,12};
    int target;
    cin>>target;
    int ans = s.search(arr,target);
    cout<<ans<<endl;
    return 0;
}