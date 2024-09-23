#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Bottom-up dynamic programming approach
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        vector<int> t(n+1, 0);
        // t[i] = min extra characters from index 0 to i

        for (int i = n - 1; i >= 0; i--) {
            t[i] = 1 + t[i + 1];  // Skip the current character
            for (int j = i; j < n; j++) {
                string current = s.substr(i, j - i + 1);
                if (st.count(current)) {
                    t[i] = min(t[i], t[j + 1]);  // No extra characters needed for the substring
                }
            }
        }
        return t[0];
    }

    // Uncomment the following if you want to test the memoization approach too
    /*
    int solve(int i, string s, unordered_set<string>& st, unordered_map<int, int>& mp, int& n) {
        if (i >= n) {
            return 0;
        }
        if (mp.count(i)) {
            return mp[i];
        }
        int result = 1 + solve(i + 1, s, st, mp, n);
        for (int j = i; j < n; j++) {
            string curr = s.substr(i, j - i + 1);
            if (st.count(curr)) {
                result = min(result, solve(j + 1, s, st, mp, n));
            }
        }
        return mp[i] = result;
    }

    int minExtraCharMemo(string s, vector<string>& dictionary) {
        int n = s.length();
        unordered_map<int, int> mp;
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        return solve(0, s, st, mp, n);
    }
    */
};

int main() {
    Solution sol;

    // Test case 1
    string s1 = "applepenapple";
    vector<string> dictionary1 = {"apple", "pen"};
    cout << "Minimum extra characters for \"" << s1 << "\": " << sol.minExtraChar(s1, dictionary1) << endl;

    // Test case 2
    string s2 = "catsandog";
    vector<string> dictionary2 = {"cats", "dog", "sand", "and", "cat"};
    cout << "Minimum extra characters for \"" << s2 << "\": " << sol.minExtraChar(s2, dictionary2) << endl;

    // Uncomment the following if you want to test the memoization approach
    /*
    cout << "Minimum extra characters (Memoization) for \"" << s1 << "\": " << sol.minExtraCharMemo(s1, dictionary1) << endl;
    cout << "Minimum extra characters (Memoization) for \"" << s2 << "\": " << sol.minExtraCharMemo(s2, dictionary2) << endl;
    */

    return 0;
}
