#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int solve(string s, int n) {
        int close = 0;
        int open = 0;
        int ans = 0;

        // Check for left to right
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            } else if (s[i] == ')') {
                close++;
            }
            if (close > open) {
                open = 0;
                close = 0;
            } else if (open == close) {
                ans = max(ans, open + close);
            }
        }

        // Check for right to left
        open = 0;
        close = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') {
                open++;
            } else if (s[i] == ')') {
                close++;
            }
            if (open > close) {
                open = 0;
                close = 0;
            } else if (open == close) {
                ans = max(ans, open + close);
            }
        }

        return ans;
    }

    int longestValidParentheses(string s) {
        int n = s.length();
        return solve(s, n);
    }
};

int main() {
    Solution solution;
    string s = "())";
    int result = solution.longestValidParentheses(s);
    cout << "Longest valid parentheses length: " << result << endl;
    return 0;
}
