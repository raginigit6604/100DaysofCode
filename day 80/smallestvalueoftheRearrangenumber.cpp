#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    long long smallestNumber(long long num) {
        // Handle the special case where the number is zero
        if (num == 0) return 0;

        bool isNegative = num < 0;
        num = abs(num);

        vector<int> digitCount(10, 0); // Create a digit count array

        // Count the occurrences of each digit
        while (num > 0) {
            digitCount[num % 10]++;
            num /= 10;
        }

        string result;

        if (isNegative) {
            // Construct the smallest negative number
            for (int i = 9; i >= 0; --i) {
                while (digitCount[i] > 0) {
                    result += to_string(i);
                    digitCount[i]--;
                }
            }
            return -stoll(result);
        } else {
            // Construct the smallest positive number
            bool leadingZero = true;
            for (int i = 1; i < 10; i++) {
                if (digitCount[i] > 0) {
                    result += to_string(i);
                    digitCount[i]--;
                    leadingZero = false;
                    break;
                }
            }
            if (leadingZero) {
                result += "0";
            }
            for (int i = 0; i < 10; ++i) {
                while (digitCount[i] > 0) {
                    result += to_string(i);
                    digitCount[i]--;
                }
            }
        }
        return stoll(result);
    }
};

int main() {
    Solution sol;

    long long num1 = 310;       // Example 1: 103
    long long num2 = -420;      // Example 2: -420
    long long num3 = 10200;     // Example 3: 1002
    long long num4 = -1000;     // Example 4: -1000

    cout << "Smallest number for " << num1 << " is: " << sol.smallestNumber(num1) << endl;
    cout << "Smallest number for " << num2 << " is: " << sol.smallestNumber(num2) << endl;
    cout << "Smallest number for " << num3 << " is: " << sol.smallestNumber(num3) << endl;
    cout << "Smallest number for " << num4 << " is: " << sol.smallestNumber(num4) << endl;

    return 0;
}
