#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int currentTime = 0;
        double totalWaitTime = 0;
        
        for(int i = 0; i < n; i++) {
            int arrivalTime = customers[i][0];
            int cookingTime = customers[i][1];
            
            if (currentTime < arrivalTime) {
                currentTime = arrivalTime;
            }
            
            int waitTime = currentTime + cookingTime - arrivalTime;
            totalWaitTime += waitTime;
            currentTime += cookingTime;
        }
        
        return totalWaitTime / n;
    }
};

int main() {
    Solution solution;
    
    vector<vector<int>> customers = {
        {1, 2},
        {2, 5},
        {4, 3}
    };
    
    double result = solution.averageWaitingTime(customers);
    
    cout << "Average Waiting Time: " << result << endl;
    
    return 0;
}
