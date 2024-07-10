#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        if(n <= 0) {
            return 0;
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(logs[i] == "../") {
                if(count > 0) {
                    count--;
                }
            } else if(logs[i] == "./") {
                continue;
            } else {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<string> logs1 = {"d1/", "d2/", "../", "d21/", "./"};
    cout << "Output for logs1: " << solution.minOperations(logs1) << endl; // Expected output: 2
    
    // Test case 2
    vector<string> logs2 = {"d1/", "d2/", "./", "d3/", "../", "d31/"};
    cout << "Output for logs2: " << solution.minOperations(logs2) << endl; // Expected output: 3
    
    // Test case 3
    vector<string> logs3 = {"d1/", "../", "../", "../"};
    cout << "Output for logs3: " << solution.minOperations(logs3) << endl; // Expected output: 0
    
    return 0;
}
