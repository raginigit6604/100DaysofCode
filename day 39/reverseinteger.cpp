#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
       
        long rem = 0;
        while(x){
            rem = rem * 10 + x % 10; // here we find remainder and add to remainder
            x = x/10;
        }
          if(rem < INT_MIN || rem > INT_MAX){
            return 0;
        }
       return int(rem);
    }
};
int main(){
    Solution s;
    int n;
    cin>>n;
    cout<<s.reverse(n)<<endl;
    return 0;
}