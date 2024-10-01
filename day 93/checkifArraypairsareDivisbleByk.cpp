#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> frequency(k, 0);  // Frequency array to track remainders
        
        // Calculate the remainder frequencies
        for (int num : arr) {
            int remainder = ((num % k) + k) % k;  // Handle negative numbers too
            frequency[remainder]++;
        }

        if (frequency[0] % 2 != 0) {
            return false;
        }
        
        // Check if frequencies of remainder i and (k - i) match
        for (int i = 1; i <= k / 2; i++) {
            if (frequency[i] != frequency[k - i]) {
                return false;
            }
        }
        
        return true;  // If all conditions are satisfied, return true
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> arr1 = {9, 7, 5, 3};
    int k1 = 6;
    if (sol.canArrange(arr1, k1)) {
        cout << "Pairs can be arranged such that their sums are divisible by " << k1 << endl;
    } else {
        cout << "Pairs cannot be arranged to be divisible by " << k1 << endl;
    }
    
    // Test case 2
    vector<int> arr2 = {2, 2, 2, 2};
    int k2 = 4;
    if (sol.canArrange(arr2, k2)) {
        cout << "Pairs can be arranged such that their sums are divisible by " << k2 << endl;
    } else {
        cout << "Pairs cannot be arranged to be divisible by " << k2 << endl;
    }
    
    return 0;
}
