#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> tempArray = arr;
        sort(tempArray.begin(),tempArray.end());
        unordered_map<int,int> mp;
        int rank = 1;
        vector<int> result;
        for(int num : tempArray){
            if(mp.find(num) == mp.end()){
                mp[num] = rank;
                rank++;
            }
        }
        for(int num: arr){
            result.push_back(mp[num]);
        }
        return result;
    }
};
int main(){
    vector<int> arr = {40,30,10,20};
    Solution s;
    vector<int> result = s.arrayRankTransform(arr);
    for(int i=0;i<arr.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}