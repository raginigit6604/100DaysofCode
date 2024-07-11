// Here we find the maximum sum of subarray.
// Subarray is a continuous part of array.
// Kadanes Algorithm is used to find the maximum sum of subarray.
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maxSubArray(vector<int>& nums){
        int n = nums.size();
        int maxsum=INT_MIN;
        int currentsum = 0;
        for(int i=0;i<n;i++){
            currentsum += nums[i];
            if(currentsum>maxsum){
                maxsum = currentsum;
            }
            if(currentsum<0){
                currentsum = 0;
            }
        }
        return maxsum;
    }
int main(){
  int n;
  cin>>n;
   vector<int> arr;
   for(int i=0;i<n;i++){
     int num;
     cin>>num;
    arr.push_back(num);
   }
  int max_sum = maxSubArray(arr);
  cout<<max_sum<<endl;
   
return 0;
}