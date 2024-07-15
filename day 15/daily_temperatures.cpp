#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int idx = s.top();
                s.pop();
                ans[idx] = i - idx;
            }
            s.push(i);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = sol.dailyTemperatures(temperatures);
    
    cout << "Daily temperatures wait times: ";
    for(int days : result) {
        cout << days << " ";
    }
    cout << endl;

    return 0;
}
