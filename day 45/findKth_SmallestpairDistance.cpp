#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) {
            return -1;
        }

        // Find the maximum element to determine the range of distances
        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> vec(maxElement + 1, 0);

        // Calculate the frequency of each distance
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int d = abs(nums[i] - nums[j]);
                vec[d]++;
            }
        }

        // Find the kth smallest distance
        for (int d = 0; d < maxElement + 1; ++d) {
            k -= vec[d];
            if (k <= 0) {
                return d;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 1};
    int k = 1;

    cout << "The " << k << "th smallest pair distance is: " << sol.smallestDistancePair(nums, k) << endl;

    return 0;
}
