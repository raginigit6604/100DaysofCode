#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(auto j: coins){
                if(i-j>=0 && dp[i-j]!=INT_MAX){
                    dp[i] = min(dp[i],dp[i-j]+1);
                }
            }
        }
        return dp[amount]==INT_MAX ? -1 : dp[amount];
    }
};
int main(){
    Solution s;
    vector<int> arr = {1,2,5};
    int amount = 11;
    int ans = s.coinChange(arr,amount);
    cout<<ans<<endl;
    return 0;
}