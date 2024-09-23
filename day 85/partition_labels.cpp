#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> end_character(26, 0);
        
        // Step 1: Record the last occurrence of each character
        for (int i = 0; i < n; i++) {
            end_character[s[i] - 'a'] = i;
        }
        
        vector<int> result;
        int start = 0, end = 0;
        
        // Step 2: Greedily partition the string
        for (int i = 0; i < n; i++) {
            end = max(end, end_character[s[i] - 'a']);  // Expand the end boundary
            if (i == end) {  // When we reach the end of a partition
                result.push_back(i - start + 1);  // Add partition length to result
                start = i + 1;  // Start a new partition
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    string s1 = "ababcbacadefegdehijhklij";
    vector<int> result1 = sol.partitionLabels(s1);
    cout << "Partitions for '" << s1 << "' are: ";
    for (int len : result1) {
        cout << len << " ";
    }
    cout << endl;

    // Example 2
    string s2 = "eccbbbbdec";
    vector<int> result2 = sol.partitionLabels(s2);
    cout << "Partitions for '" << s2 << "' are: ";
    for (int len : result2) {
        cout << len << " ";
    }
    cout << endl;

    return 0;
}
