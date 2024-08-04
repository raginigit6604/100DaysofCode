#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(const string& str, int left, int right) {
        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) {
            return s;
        }

        int start = 0;
        int max_len = 1;

        for (int i = 0; i < n; ++i) {
            int l1 = i, r1 = i;
            while (l1 >= 0 && r1 < n && s[l1] == s[r1]) {
                if (r1 - l1 + 1 > max_len) {
                    start = l1;
                    max_len = r1 - l1 + 1;
                }
                l1--;
                r1++;
            }

            // Check for even-length palindromes
            int l2 = i, r2 = i + 1;
            while (l2 >= 0 && r2 < n && s[l2] == s[r2]) {
                if (r2 - l2 + 1 > max_len) {
                    start = l2;
                    max_len = r2 - l2 + 1;
                }
                l2--;
                r2++;
            }
        }

        return s.substr(start, max_len);
    }
};
int main(){
    string s = "babad";
    Solution st;
    cout<<st.longestPalindrome(s);
    return 0;
}