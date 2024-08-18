#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> count(n,1);
        // to check left to right
        for(int i=1;i<n;i++){
           if(ratings[i] > ratings[i-1]){
            count[i] = max(count[i],count[i-1]+1);
           }
        }
       // to check right to left
        for(int i=n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                count[i] = max(count[i],count[i+1]+1);
            }
        }

        int result = 0;
        for(int i=0;i<n;i++){
            result += count[i];
        }
        return result;
    }
};
int main(){
    int t;
    cin>>t;
    vector<int> arr(t);
    for(int i=0;i<t;i++){
        cin>>arr[i];
    }
    Solution s;
    int result = s.candy(arr);
    cout<<result<<endl;
    return 0;
}