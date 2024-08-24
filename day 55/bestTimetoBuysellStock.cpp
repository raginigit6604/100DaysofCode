#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int ans = 0;
        int n = prices.size();
        
        for (int i = 0; i < n; i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            int diff = prices[i] - minPrice;
            ans = max(ans, diff);
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    Solution s;
    int ans = s.maxProfit(arr);
    cout << ans << endl;
    return 0;
}
