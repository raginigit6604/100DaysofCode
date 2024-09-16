#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
         int n = timePoints.size();
         vector<int> minutes(n);
         for(int i = 0;i<n;i++){
            string time = timePoints[i];
            string hoursubstring = time.substr(0,2); // for hour 
            string minutesubstring = time.substr(3); // for minutes

            int hourInteger = stoi(hoursubstring);
            int minInteger = stoi(minutesubstring);

            minutes[i] = hourInteger * 60 + minInteger;
         }
         sort(minutes.begin(),minutes.end());
         int result = INT_MAX;
         for(int i = 1; i<n;i++){
            result = min(result,minutes[i] - minutes[i-1]);
         }
         return min(result,(24 * 60 - minutes[n-1]) + minutes[0]);
    }
};
int main() {
    // Create a Solution object
    Solution solution;

    // Test case 1
    vector<string> timePoints1 = {"23:59", "00:00"};
    cout << "Minimum Time Difference: " << solution.findMinDifference(timePoints1) << " minutes" << endl;

    // Test case 2
    vector<string> timePoints2 = {"00:00", "12:30", "23:59", "05:15"};
    cout << "Minimum Time Difference: " << solution.findMinDifference(timePoints2) << " minutes" << endl;

    return 0;
}