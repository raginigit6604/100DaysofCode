#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int mask = 0, maximumLength = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') mask ^= (1 << 0);
            else if (s[i] == 'e') mask ^= (1 << 1);
            else if (s[i] == 'i') mask ^= (1 << 2);
            else if (s[i] == 'o') mask ^= (1 << 3);
            else if (s[i] == 'u') mask ^= (1 << 4);
            
            if (mp.find(mask) != mp.end()) {
                maximumLength = max(maximumLength, i  - mp[mask]);
            } else {
                mp[mask] = i;
            }
        }
        return maximumLength;
    }
};
int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "eleetminicoworoep";
    cout << "Test case 1: Input: " << s1 << endl;
    cout << "Output: " << solution.findTheLongestSubstring(s1) << endl;

    // Test case 2
    string s2 = "leetcodeisgreat";
    cout << "Test case 2: Input: " << s2 << endl;
    cout << "Output: " << solution.findTheLongestSubstring(s2) << endl;
    
    // Test case 3
    string s3 = "bcbcbc";
    cout << "Test case 3: Input: " << s3 << endl;
    cout << "Output: " << solution.findTheLongestSubstring(s3) << endl;
    
    return 0;
}