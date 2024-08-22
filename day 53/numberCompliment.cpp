#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int findComplement(int num) {
        int num_bits = (int)(log2(num)+1); // to find bits
         for(int i=0;i<num_bits;i++){
             num = num ^ (1<<i);
         }
        return num;
    }
};
int main(){
    int n;
    cin>>n;
    Solution s;
    int ans = s.findComplement(n);
    cout<<"Ans is : "<<ans<<endl;
    return 0;
}