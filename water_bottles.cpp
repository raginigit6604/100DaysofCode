#include <iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrunkBottles = numBottles;
        int remaining = numBottles;

        while (remaining >= numExchange) {
            int newBottles = remaining / numExchange;
            totalDrunkBottles += newBottles;
            remaining = newBottles + (remaining % numExchange);
        }

        return totalDrunkBottles;
    }
};

int main() {
    Solution solution;
    int numBottles, numExchange;

    cout << "Enter the number of water bottles: ";
    cin >> numBottles;
    cout << "Enter the number of empty bottles needed to exchange for a full bottle: ";
    cin >> numExchange;

    int result = solution.numWaterBottles(numBottles, numExchange);
    cout << "Maximum number of water bottles you can drink: " << result << endl;

    return 0;
}
