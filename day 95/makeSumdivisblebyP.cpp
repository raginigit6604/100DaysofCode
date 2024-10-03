#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        
        int remainder = sum % p;
        if(remainder == 0){
            return 0;
        }

        int ans = nums.size();
        unordered_map<int,int>mp;
        sum=0;

        for(int i=0;i<n;i++){
            sum += nums[i];
            int remainder2 = sum % p;

            if(remainder2 == remainder)
                ans = min(ans,i+1);

            if(mp.find(remainder2-remainder) != mp.end()){
                ans=min(ans,i-mp[remainder2-remainder]);
            }

            if(mp.find(p+remainder2-remainder) != mp.end()){
                ans=min(ans,i-mp[p + remainder2 - remainder]);
            }
            mp[remainder2] = i;
        }
        if(ans >= nums.size()){
            return -1;
        }
        return ans;
        
    }
};
int main(){
     vector<int> arr= {3,1,4,2};
     int p = 6;
     Solution sol;
     int result = sol.minSubarray(arr,p);
        cout<<result<<endl;
    return 0;
}