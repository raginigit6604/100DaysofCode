#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                if ((s[i] == ')' && top == '(') ||
                    (s[i] == '}' && top == '{') ||
                    (s[i] == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution solution;
    
    // Test cases
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([)]";
    string test5 = "{[]}";

    cout << "Test case 1: " << (solution.isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test case 2: " << (solution.isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test case 3: " << (solution.isValid(test3) ? "Valid" : "Invalid") << endl;
    cout << "Test case 4: " << (solution.isValid(test4) ? "Valid" : "Invalid") << endl;
    cout << "Test case 5: " << (solution.isValid(test5) ? "Valid" : "Invalid") << endl;

    return 0;
}
