#include <iostream>
#include <vector>
#include <algorithm> // For sort function

using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end()); // Sort the skills to form valid pairs
        long long total_sum = 0; // Use long long to avoid overflow
        int left = 0, right = n - 1; // Two pointers: one from the start and one from the end

        int target = skill[left] + skill[right]; // Target sum for every team

        while (left < right) {
            int currentSum = skill[left] + skill[right];

            // If the current pair doesn't match the target sum, return -1
            if (currentSum != target) {
                return -1;
            }

            // Add the product of the current pair to the total sum
            total_sum += (long long)skill[left] * skill[right]; // Cast to long long to prevent overflow

            // Move the pointers
            left++;
            right--;
        }

        return total_sum; // Return the total chemistry sum
    }
};

int main() {
    // Test Case 1
    vector<int> skill1 = {3, 6, 2, 8};  // Sorted: {2, 3, 6, 8}
    Solution solution;
    long long result1 = solution.dividePlayers(skill1);
    if (result1 != -1) {
        cout << "Total chemistry sum: " << result1 << endl;
    } else {
        cout << "Impossible to divide players into teams." << endl;
    }

    // Test Case 2
    vector<int> skill2 = {1, 2, 2, 1};  // Sorted: {1, 1, 2, 2}
    long long result2 = solution.dividePlayers(skill2);
    if (result2 != -1) {
        cout << "Total chemistry sum: " << result2 << endl;
    } else {
        cout << "Impossible to divide players into teams." << endl;
    }

    // Test Case 3 (Invalid Case)
    vector<int> skill3 = {5, 3, 9, 2};  // Sorted: {2, 3, 5, 9}
    long long result3 = solution.dividePlayers(skill3);
    if (result3 != -1) {
        cout << "Total chemistry sum: " << result3 << endl;
    } else {
        cout << "Impossible to divide players into teams." << endl;
    }

    return 0;
}
