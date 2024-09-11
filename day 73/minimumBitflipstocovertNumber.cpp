#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR the start and goal to find the differing bits
        int result = start ^ goal;
        
        // Count the number of 1's in the XOR result (which represent the differing bits)
        int flip = 0;
        
        while (result > 0) {
            // Increment flip count for each 1-bit in xorResult
            flip += result & 1;
            // Right shift xorResult to check the next bit
            result >>= 1;
        }
        
        return flip;
    }
};
int main(){
    int a= 10,b=7;
    Solution s;
    int ans = s.minBitFlips(a,b);
    cout<<ans<<endl;
    return 0;
}
