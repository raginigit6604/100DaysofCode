#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int maxproduct = INT_MIN; 
          // optimized approach T>C = O(n) , S.C = O(1)
          int prefix = 1;
          int suffix = 1;
          for(int i=0;i<n;i++){
            if(prefix == 0){
                prefix = 1;
            }
            if(suffix == 0){
                suffix = 1;
            }
            prefix = prefix * nums[i];
            suffix = suffix * nums[n-i-1];
            maxproduct = max(maxproduct,max(prefix,suffix));
          }

        // // time complexity O(n^2), S.C = O(1)
        // for(int i=0;i<n;i++){
        //     int product = 1;
        //     for(int j=i;j<n;j++){
        //         product *= nums[j];
        //         maxproduct = max(maxproduct,product);
        //     }
        // }

           
        //Brute Force Aprroach  T.C = O(n^3), S.C = O(1) 
        // for(int i=0;i<n;i++){ 
        //     for(int j=i;j<n;j++){
        //           int product = 1;
        //         for(int k = i;k<j;k++){
        //             product *= nums[k];
        //         }
        //         maxproduct = max(maxproduct,product);
        //     }
        // }
        return maxproduct;
    }
};
int main(){
    Solution s;
    vector<int> arr = {2,3,-2,4};
    int ans  = s.maxProduct(arr);
    cout<<ans<<endl;
    return 0;
}