#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> mp;

        // Track prefixes in arr1
        for (int num : arr1) {
            string str = to_string(num);
            for (int len = 1; len <= str.length(); ++len) {
                mp[str.substr(0, len)]++;
            }
        }

        int maxPrefix = 0;

        // Compare with prefixes in arr2
        for (int num : arr2) {
            string str = to_string(num);
            for (int len = 1; len <= str.length(); ++len) {
                if (mp.count(str.substr(0, len))) {
                    maxPrefix = max(maxPrefix, len);
                } else {
                    break;
                }
            }
        }

        return maxPrefix;
    }
};

int main() {
    Solution solution;
    
    // Input arrays
    vector<int> arr1 = {1, 10, 100};
    vector<int> arr2 = {1000};
    
    int result = solution.longestCommonPrefix(arr1, arr2);
    
    // Output the result
    cout << "The length of the longest common prefix is: " << result << endl;

    return 0;
}
