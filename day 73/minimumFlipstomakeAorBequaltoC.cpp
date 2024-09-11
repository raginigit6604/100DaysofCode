#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip = 0;
        while(a != 0 || b != 0 || c != 0){
            if((c & 1) == 1){
                if((a & 1) == 0 && (b & 1) == 0){
                     flip++;
                }
            }
            else{
                if((a & 1) == 1){
                    flip++;
                } 
                if((b & 1) == 1){
                    flip++;
                }
            }
            a >>= 1; // rightshift
            b >>= 1;
            c >>= 1;
        }
        return flip;
    }
};
int main(){
    int a= 2,b=6,c=5;
    Solution s;
    int ans = s.minFlips(a,b,c);
    cout<<ans<<endl;
    return 0;
}