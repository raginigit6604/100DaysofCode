#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto it: mp){
            pq.push({-it.second,it.first}); // we take it.second in first because we have to priority frequency
            if(pq.size()>k){
                pq.pop();
            }
          }
          for(int i=0;i<k;i++){
              ans.push_back(pq.top().second);
              pq.pop();
          }
   return ans;
    }
};
int main(){
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution s;
    vector<int> result = s.topKFrequent(nums,k);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}