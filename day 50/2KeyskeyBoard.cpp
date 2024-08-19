#include<iostream>
using namespace std;
class Solution {
public:
    int minSteps(int n) {
        if(n==1){
             return 0;
        }     
        int ans = 0;
        int i = 2;
        while(i <= n)
        {
            if(n%i == 0)
            {
                ans += i;
                n = n/i;
            }
            else i++;
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    Solution s;
    int result = s.minSteps(n);
    cout<<result<<endl;
}