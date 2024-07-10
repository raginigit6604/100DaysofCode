#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> temp(m + n); // Create size of merged array
        int i = 0;  // Index for nums1
        int j = 0;  // Index for nums2
        int k = 0;  // Index for temp
        
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                temp[k] = nums1[i];
                i++;
            } else {
                temp[k] = nums2[j];
                j++;
            }
            k++;
        }
        
        while (i < n) {
            temp[k] = nums1[i];
            i++;
            k++;
        }
        
        while (j < m) {
            temp[k] = nums2[j];
            j++;
            k++;
        }
        
        // Find the median
        int size = m + n; // Size of temporary or merged array
        if (size % 2 == 0) {
            return (temp[size / 2] + temp[(size / 2) - 1]) / 2.0; // Divide by 2.0 to get float value
        } else {
            return temp[size / 2];
        }
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    {
        vector<int> n1 = {1, 3};
        vector<int> n2 = {2};
        cout << "Median of nums1 and nums2: " << solution.findMedianSortedArrays(n1, n2) << endl; // Expected output: 2.0
    }
    
    
    return 0;
}
