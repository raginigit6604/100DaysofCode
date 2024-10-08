#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true;
        bool dec = true;
        
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                dec = false;
            }
            if (nums[i] < nums[i - 1]) {
                inc = false;
            }
        }
        
        return inc || dec;
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
    cout<<s.isMonotonic(arr)<<endl;
    return 0;
}