#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int prev = 0;
        int curr = 0;
        long long result = 0;
        for(int i = 0; i < n; i++){
            int curr = target[i];
            if(abs(curr) > abs(prev)){
                result += abs(curr - prev);
            }
            prev = curr;
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> target = {1, 2, 3, 2, 1}; // Example input
    int result = sol.minNumberOperations(target);
    cout << "Minimum number of operations: " << result << endl;
    return 0;
}
