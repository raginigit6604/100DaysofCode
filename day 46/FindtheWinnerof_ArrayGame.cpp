#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
         int current_winner = arr[0];
         int count = 0;
        
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > current_winner) {
                current_winner = arr[i];
                count = 1; 
            } else {
                count++; 
            }
            
            if (count == k) {
                return current_winner;
            }
        }
        
        return current_winner;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    Solution s;
    int ans = s.getWinner(arr,k);
    cout<<ans<<endl;
}