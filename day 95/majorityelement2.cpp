#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element1 = INT_MIN, element2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == element1) {
                cnt1++;
            } else if (nums[i] == element2) {
                cnt2++;
            } else if (cnt1 == 0) {
                element1 = nums[i];
                cnt1 = 1;
            } else if (cnt2 == 0) {
                element2 = nums[i];
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

    
        int counter1 = 0, counter2 = 0;
        for (int num : nums) {
            if (num == element1) {
                counter1++;
            } else if (num == element2) {
                counter2++;
            }
        }

        vector<int> result;
        if (counter1 > n / 3) {
            result.push_back(element1);
        }
        if (counter2 > n / 3) {
            result.push_back(element2);
        }

        return result;
    }
};

int main(){
     vector<int> arr= {3,2,3};
     Solution sol;
     vector< int> result;
     result = sol.majorityElement(arr);
     for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
     }
    return 0;
}