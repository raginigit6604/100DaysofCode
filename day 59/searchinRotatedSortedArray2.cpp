#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low + high) / 2;
            if(arr[mid] == target){
                return true;
            }else if(arr[low]==arr[high]){
                if(arr[low]==target) return true;
                low++,high--;
            }
            else if(arr[low] <= arr[mid]){
                if(arr[low]<=target && arr[mid]>=target){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else{
                if(arr[mid]<=target && arr[high]>=target){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};
int main(){
     Solution solution;
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    if (solution.search(nums, target)) {
        cout << "Target " << target << " found in the array." << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }
    return 0;
}