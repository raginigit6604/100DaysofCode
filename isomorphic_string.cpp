//Two strings s and t are isomorphic if the characters in s can be replaced to get t.
//All occurrences of a character must be replaced with another character while preserving ,
//the order of characters. No two characters may map to the same character, but a character may map to itself.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        int s_map[256] = {0};
        int t_map[256] = {0};

        for (int i = 0; i < s.length(); ++i) {
            if (s_map[s[i]] != t_map[t[i]]) {
                return false;
            }

            s_map[s[i]] = i + 1;
            t_map[t[i]] = i + 1;
        }

        return true;
    }
};

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    Solution solution;
    bool result = solution.isIsomorphic(s, t);

    if (result) {
        cout << "The strings are isomorphic." << endl;
    } else {
        cout << "The strings are not isomorphic." << endl;
    }

    return 0;
}
