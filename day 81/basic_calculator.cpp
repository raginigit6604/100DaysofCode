#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        long long int sum = 0;
        int sign = 1;
        stack<pair<int, int>> st;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                long long int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;  // adjust because the for-loop will increment it
                sum += num * sign;
                sign = 1;  // reset sign after processing a number
            } 
            else if (s[i] == '(') {
                st.push({sum, sign});
                sum = 0;
                sign = 1;  // reset for inner expression
            } 
            else if (s[i] == ')') {
                sum = st.top().first + (st.top().second * sum);  // apply the saved sign
                st.pop();
            } 
            else if (s[i] == '-') {
                sign = -1 * sign;
            }
        }
        return sum;
    }
};

int main() {
    Solution solver;
    string expression;

    // Get input from the user
    cout << "Enter a mathematical expression: ";
    getline(cin, expression);

    // Call the calculate function
    int result = solver.calculate(expression);

    // Output the result
    cout << "The result of the expression is: " << result << endl;

    return 0;
}
