#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSteps(int prefix, long long n) {
        long long current = prefix;
        long long next = prefix + 1;
        int steps = 0;
        
        while (current <= n) {
            steps += min(n + 1, next) - current;
            current *= 10;
            next *= 10;
        }
        
        return steps;
    }
    
    int findKthNumber(int n, int k) {
        int current = 1; 
        k--;  // Since we already start from the first number (1), we decrement k
        
        while (k > 0) {
            int steps = countSteps(current, n);
            
            if (steps <= k) {
                // Skip the current range if k is greater than or equal to steps
                current++;
                k -= steps; 
            } else {
                // Dive deeper into the tree if the k-th number is within the current range
                current *= 10;
                k--; 
            }
        }
        
        return current;
    }
};

int main(){
    int n, k;
    cin >> n;
    cin >> k;
    Solution sol;
    cout << sol.findKthNumber(n, k) << endl;
    return 0;
}
