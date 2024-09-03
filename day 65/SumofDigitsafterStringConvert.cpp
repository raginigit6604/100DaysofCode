#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getLucky(string s, int k) {
        int n = s.length();
        string ans = "";
        for(int i=0;i<n;i++){
            ans += to_string(int(s[i]) - 96);
        }
        int temp = 0;
        while(k != 0){
            for(int i = 0;i<ans.size();i++){
                temp += int(ans[i]) - '0';
            }

            ans = to_string(temp);
            temp = 0;
            k--;
        }
         int res = stoi(ans);
         return res;
    }
};
int main(){
    string s= "iiii";
    int k = 1;
    Solution sol;
    cout<<sol.getLucky(s,k)<<endl;
    return 0;
}