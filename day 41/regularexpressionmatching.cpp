#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool solve(string s, string p, vector<vector<int>>& memo, int i, int j) {
        if (j == p.size()) {
            return i == s.size();
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        bool first_char_matched = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
        
        bool result = false;
        if (j + 1 < p.size() && p[j + 1] == '*') {
            result = (solve(s, p, memo, i, j + 2) || 
                      (first_char_matched && solve(s, p, memo, i + 1, j)));
        } else {
            result = first_char_matched && solve(s, p, memo, i + 1, j + 1);
        }
        
        memo[i][j] = result;
        return result;
    }
    
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(s, p, memo, 0, 0);
    }
};

int main() {
    Solution solution;
    string s, p;

    // Test case 1
    s = "aab";
    p = "c*a*b";
    cout << "Test case 1: " << (solution.isMatch(s, p) ? "Match" : "No Match") << endl;

    // Test case 2
    s = "aa";
    p = "a*";
    cout << "Test case 2: " << (solution.isMatch(s, p) ? "Match" : "No Match") << endl;

    // Test case 3
    s = "mississippi";
    p = "mis*is*p*.";
    cout << "Test case 3: " << (solution.isMatch(s, p) ? "Match" : "No Match") << endl;

    return 0;
}
