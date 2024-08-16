#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minimum = arrays[0].front();
        int maximum = arrays[0].back();
        int result = 0;
  
        for (int i = 1; i < arrays.size(); i++) {

            int current_min = arrays[i].front();
            int current_max = arrays[i].back();
            result = max({result, abs(current_min - maximum), abs(current_max - minimum)});
            maximum = max(maximum, current_max);
            minimum = min(minimum, current_min);
        }
        
        return result;
    }
};
int main(){
    vector<vector<int>> arrays = {
        {1, 3, 5},
        {4, 6, 8},
        {7, 9, 10}
    };
    
    Solution sol;
    int result = sol.maxDistance(arrays);
    
    cout << "Maximum Distance: " << result << endl;
    
    return 0;
}