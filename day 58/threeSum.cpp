#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int target = -nums[i]; // a+b+c = 0 so, b+c = -a
            int left = i+1;
            int right = n-1;
            while(left < right){
                if(nums[left] + nums[right] == target){
                    vector<int> temp = {nums[i],nums[left],nums[right]};
                    if(st.count(temp) == 0){
                        ans.push_back(temp);
                        st.insert({nums[i],nums[left],nums[right]});

                    }
                    left++;
                    right--;
                }
                else if(nums[left] + nums[right] < target){
                    left++;
                }
                else if(nums[left] + nums[right] > target){
                    right--;
                }
            }
        }
        return ans;
    }
};
int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);

    cout << "Unique triplets that sum up to 0 are:" << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}