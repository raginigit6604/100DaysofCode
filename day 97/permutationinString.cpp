#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if (n1 > n2) return false;
        
        // Frequency count for characters in s1
        vector<int> freqS1(26, 0);
        for (char c : s1) freqS1[c - 'a']++;
        
        // Sliding window frequency count for s2
        vector<int> freqS2(26, 0);
        for (int i = 0; i < n2; i++) {
            freqS2[s2[i] - 'a']++;
            
            // Shrink window if size exceeds n1
            if (i >= n1) freqS2[s2[i - n1] - 'a']--;
            
            // Compare frequencies
            if (freqS1 == freqS2) return true;
        }
        
        return false;
    }
};

int main() {
    Solution solution;
    
    string s1 = "ab";
    string s2 = "eidbaooo";
    
    // Call the checkInclusion function
    bool result = solution.checkInclusion(s1, s2);
    
    if(result) {
        cout << "Yes, '" << s1 << "' is a permutation of a substring in '" << s2 << "'." << endl;
    } else {
        cout << "No, '" << s1 << "' is not a permutation of any substring in '" << s2 << "'." << endl;
    }

    return 0;
}
