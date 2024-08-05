#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n-1;i++){
            if(nums[i] == nums[i+1]){
                return true;
            }
        }
        return false;
    }
};
int main(){
    vector<int> arr = {1,2,3,1};
     Solution s;
     bool result = s.containsDuplicate(arr);
     if(result){
        cout<<"True"<<endl;
     }
     else{
        cout<<"False"<<endl;
     }
    return 0;
}