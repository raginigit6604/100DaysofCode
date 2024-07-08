#include <iostream>
using namespace std;
class Solution {
public:
    int findWinnerindex(int n, int k) {
        if (n == 1) {
            return 0;
        }
        int index = findWinnerindex(n - 1, k);
        index = (index + k) % n;
        return index;
    }

    int findTheWinner(int n, int k) {
        int resultindex = findWinnerindex(n, k);
        return resultindex + 1;
    }
};

int main() {
    Solution solution;
    int n = 5; // Number of people
    int k = 2; // Step rate
    int winner = solution.findTheWinner(n, k);
    cout << "The winner is: " << winner <<endl;
    return 0;
}
