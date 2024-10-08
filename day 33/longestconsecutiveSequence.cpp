#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// brute force approach
    int longestConsecutive(vector<int>& nums) {
       int n = nums.size();
       unordered_map<int,int> mp;
       for(int i=0;i<n;i++){
          mp[nums[i]]++;
       } 
       int len = 0;
       for(int i=0;i<n;i++){
        int start = nums[i];
        int cnt = 0;
        while(mp.count(start)){
            cnt++;
            start += 1;
        }
        if(cnt > len){
            len = cnt;
        }
       }
       return len;
    }
};
int main(){
   Solution s;
   vector<int> nums = {100,4,200,1,3,2};
   int result = s.longestConsecutive(nums);
   cout<<result<<endl;
    return 0;
}