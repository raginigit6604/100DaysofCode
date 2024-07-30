#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // here we make min heap
        int n = nums.size();
        int ans = 0;
        priority_queue<int,vector<int>,greater<int>> pq; 
            for(int i=0;i<n;i++){
                pq.push(nums[i]);
               if(pq.size() > k){
                pq.pop();
             }
         }
         return pq.top();
          // alternate method
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // int ans = nums[n-k];
        // return ans;
    }
};
int main(){
    vector<int> arr = {3,2,1,5,6,4};
    int k;
    cin>>k;
    Solution s;
    cout<< s.findKthLargest(arr,k);
    return 0;
}