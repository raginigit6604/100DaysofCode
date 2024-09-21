#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        
        // Loop through the prices array
        for(int i = 0; i < n - 1; i++) {
            // If price increases the next day, add the profit
            if(prices[i] < prices[i+1]) {
                profit += prices[i+1] - prices[i];
            }
        }
        
        return profit;
    }
};

int main() {
    // Example test case
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    
    // Create an instance of the Solution class
    Solution sol;
    
    // Call the maxProfit function
    int result = sol.maxProfit(prices);
    
    // Output the result
    cout << "Maximum Profit: " << result << endl;
    
    return 0;
}
