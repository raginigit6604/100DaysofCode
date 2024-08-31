#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<string,int> mp;
    int n;
    int  dp[301];
    bool solve(string s,int i){
        if(i>=n){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        string temp="";
        bool ans = false;
        for(int k=i;k<n;k++){
            temp+=s[k];
            if(mp.count(temp)){
                int t=solve(s,k+1);
                ans=ans|t;
            }
        }

        return dp[i]= ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        mp.clear();
        n=s.size();
        for(auto word:wordDict){
            mp[word]++;
        }
        return solve(s,0);
    }
};
int main() {
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    
    if (sol.wordBreak(s, wordDict)) {
        cout << "The string can be segmented into a space-separated sequence of dictionary words." << endl;
    } else {
        cout << "The string cannot be segmented into a space-separated sequence of dictionary words." << endl;
    }

    return 0;
}