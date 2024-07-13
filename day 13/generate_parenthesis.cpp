#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void generateParenthesis(int n, int open, int close, string s, vector<string>& result) {
         if (s.length() == 2 * n) {
            result.push_back(s);
            return;
         }
         if (open < n) {
           generateParenthesis(n, open + 1, close, s + '(', result);
         }
         if (close < open) {
            generateParenthesis(n, open, close + 1, s + ')', result);
         }
    }
    vector<string> generateParenthesis(int n) {
       vector<string> result;
       generateParenthesis(n, 0, 0, "", result);  
       return result;
    }
};

int main() {
    int n = 3;  // Example input
    Solution solution;
    vector<string> result = solution.generateParenthesis(n);
    
    cout << "Generated Parentheses for n = " << n << ":\n";
    for (const string& s : result) {
        cout << s << "\n";
    }

    return 0;
}
