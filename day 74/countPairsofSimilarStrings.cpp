#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for(int i = 0;i < n; i++){
             set<char> s(words[i].begin(),words[i].end());
             string s1(s.begin(),s.end());
             words[i] = s1;
        }
        for(int i = 0;i < n - 1;i++){
            for(int j = i+1; j < n;j++){
                if(words[i] == words[j]){
                    count++;
                }
            }
        }
        return count;
    }
};

int main(){
    vector<string> words = {"abc", "bca", "dcb", "xyz", "yzx", "zyx"};
    Solution sol;
    int result = sol.similarPairs(words);
    cout << "Number of similar pairs: " << result << endl;

    return 0;
}