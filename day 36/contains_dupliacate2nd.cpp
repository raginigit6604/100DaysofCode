#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(mp.count(nums[i])){
                if(abs(i - mp[nums[i]]) <= k){
                    return true;
                }
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};
int main(){
    vector<int> arr = {1,2,3,1};
     int k;
     Solution s;
     bool result = s.containsNearbyDuplicate(arr,k);
     if(result){
        cout<<"True"<<endl;
     }
     else{
        cout<<"False"<<endl;
     }
    return 0;
}