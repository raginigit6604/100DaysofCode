#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int M = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> temp;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                temp.push_back(sum);
            }
        }
        sort(temp.begin(),temp.end());
        int result = 0;
        for(int i=left -1;i<=right - 1;i++){  // for indexing 0
            result = (result + temp[i]) % M;
        }
        return result;
    }
};
int main(){
    int n = 4;
    vector<int> arr = {1,2,3,4};
    int l = 1,r = 5;
    Solution s;
    cout<<s.rangeSum(arr,n,l,r)<<endl;
    return 0;
}