#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int n1 = num1.size();
        int n2 = num2.size();
        int totalsize = n1 + n2;  // Maximum possible size of the product
        vector<int> num(totalsize, 0);

        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                num[i + j] += num[i + j + 1] / 10;
                num[i + j + 1] %= 10;
            }
        }

        // Skip leading zeros
        int i = 0;
        while (i < num.size() && num[i] == 0) {
            i++;
        }

        string ans = "";
        while (i < num.size()) {
            ans.push_back(num[i++] + '0');
        }

        return ans;
    }
};

int main() {
    Solution solution;
    string num1 = "123";
    string num2 = "456";
    string result = solution.multiply(num1, num2);
    cout << "The product of " << num1 << " and " << num2 << " is: " << result << endl;
    return 0;
}
