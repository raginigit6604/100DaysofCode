#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            int age = stoi(details[i].substr(11,2));
            if(age > 60){
                cnt++;
            }
        }
        return cnt;
    }
};
int main(){
    Solution s;
    vector<string> st= {"7868190130M7522","5303914400F9211","9273338290F4010"};
    cout<< s.countSeniors(st)<<endl;
    return 0;
}