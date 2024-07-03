#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string arr[10] = {".",".","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void solve(string& s, string& output, int i, int n, vector<string>& result) {
        if (i == n) {
            result.push_back(output);
            return;
        }
        int digit = s[i] - '0';
        string temp = arr[digit];
        for (int j = 0; j < temp.size(); j++) {
            output.push_back(temp[j]);
            solve(s, output, i + 1, n, result);
            // backtrack
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digit) {
        vector<string> results;
        if (digit.empty()) return results; // return empty vector if input is empty

        int n = digit.size();
        string output = "";
        solve(digit, output, 0, n, results);
        return results;
    }
};

int main() {
    Solution solution;

    // Test case 1
    string digits1 = "23";
    vector<string> result1 = solution.letterCombinations(digits1);
    cout << "Input: " << digits1 << "\nOutput: ";
    for (const string& comb : result1) {
        cout << comb << " ";
    }
    cout << endl;

    // Test case 3
    string digits3 = "2";
    vector<string> result3 = solution.letterCombinations(digits3);
    cout << "Input: " << digits3 << "\nOutput: ";
    for (const string& comb : result3) {
        cout << comb << " ";
    }
    cout << endl;

    return 0;
}
