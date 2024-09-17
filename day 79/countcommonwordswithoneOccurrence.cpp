#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        
        unordered_map<string, int> cnt1, cnt2;
        for (const string& word : words1) {
            cnt1[word]++;
        }

        for (const string& word : words2) {
            cnt2[word]++;
        }
        
        int result = 0;
    
        for (const auto& word : cnt1) {
            if (word.second == 1 && cnt2[word.first] == 1) {
                result++;
            }
        }
        
        return result;
    }
};
int main() {
    Solution solution;
    
    // Test case 1
    vector<string> words1 = {"leetcode", "is", "amazing", "as", "is"};
    vector<string> words2 = {"amazing", "leetcode", "is"};
    
    int result = solution.countWords(words1, words2);
    cout << "Number of common words with one occurrence: " << result << endl;  // Output: 2
    
    // Test case 2
    vector<string> words1_test2 = {"b", "bb", "bbb"};
    vector<string> words2_test2 = {"a", "aa", "aaa"};
    
    result = solution.countWords(words1_test2, words2_test2);
    cout << "Number of common words with one occurrence: " << result << endl;  // Output: 0
    
    // Test case 3
    vector<string> words1_test3 = {"a", "ab"};
    vector<string> words2_test3 = {"a", "a", "a", "ab"};
    
    result = solution.countWords(words1_test3, words2_test3);
    cout << "Number of common words with one occurrence: " << result << endl;  // Output: 1

    return 0;
}