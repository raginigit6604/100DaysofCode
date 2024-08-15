#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
   
       unordered_set<int> st(nums.begin(),nums.end());
        priority_queue<int> pq(st.begin(),st.end());
        if(pq.size()<3){
          return pq.top();
        }
        int k=3;
        while(k-1){
          pq.pop();
          k--;
        }
         return pq.top();
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution s;
    int ans = s.thirdMax(arr);
    cout<<ans<<endl;
}