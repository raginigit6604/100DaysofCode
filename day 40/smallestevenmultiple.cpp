#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestEvenMultiple(int n) {
        int result; 
        if(n%2 == 0){
            result = n;
        }
        if(n%2 != 0){
            result = n*2;
        }
        return result;
    }
};
int main(){
    Solution s;
    int n;
    cin>>n;
    int ans = s.smallestEvenMultiple(n);
    cout<<ans<<endl;
    return 0;
}