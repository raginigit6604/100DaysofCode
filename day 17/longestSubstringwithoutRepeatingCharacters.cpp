#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxlength = 0;
        int start = 0;
        if (n == 0) {
            return 0;
        }
        for (int end = 0; end < n; end++) {
            for (int i = start; i < end; i++) {
                if (s[i] == s[end]) {
                    start = i + 1;
                    break;
                }
            }
            maxlength = max(maxlength, end - start + 1);
        }
        return maxlength;
    }
};

int main() {
    Solution solution;
    string test1 = "abcabcbb";
    string test2 = "bbbbb";
    string test3 = "pwwkew";
    cout << "Test 1: " << solution.lengthOfLongestSubstring(test1) << endl; // Expected output: 3
    cout << "Test 2: " << solution.lengthOfLongestSubstring(test2) << endl; // Expected output: 1
    cout << "Test 3: " << solution.lengthOfLongestSubstring(test3) << endl; // Expected output: 3
    
return 0;
}