#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string str) {
        int n = str.size();
        vector<int> result;

        // Loop through the string to check for operators
        for (int i = 0; i < n; i++) {
            if (str[i] == '+' || str[i] == '-' || str[i] == '*') {
                // Recursively solve left and right parts of the expression
                vector<int> left_result = diffWaysToCompute(str.substr(0, i));
                vector<int> right_result = diffWaysToCompute(str.substr(i + 1));

                // Combine results based on the operator
                for (int left : left_result) {
                    for (int right : right_result) {
                        if (str[i] == '+') {
                            result.push_back(left + right);
                        } else if (str[i] == '-') {
                            result.push_back(left - right);
                        } else if (str[i] == '*') {
                            result.push_back(left * right);
                        }
                    }
                }
            }
        }

        // If no operators found, the string is just a number
        if (result.empty()) {
            result.push_back(stoi(str));
        }

        return result;
    }
};

int main() {
    Solution solver;
    string expression;

    // Get the input expression from the user
    cout << "Enter a mathematical expression: ";
    cin >> expression;

    // Call the function to compute all possible results
    vector<int> results = solver.diffWaysToCompute(expression);

    // Output the possible results
    cout << "Possible results: ";
    for (int result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}
