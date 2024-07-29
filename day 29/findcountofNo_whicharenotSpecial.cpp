#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int N=sqrt(r)+1;
        vector<int> prime(N+1,1);
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i*i<=N;i++){
            if(prime[i]){
                for(int j=2*i;j<N;j+=i){
                    prime[j]=0;
                }
            }
        }

        vector<int> v;
        for(int i=2;i<N;i++){
            if(prime[i])
                v.push_back(i);
        }
        int cnt=0;
        for(int i=0;i<v.size();i++){
            if(v[i]*v[i]>=l && v[i]*v[i]<=r){
                cnt++; // here we cnt  special numbers
            }
        }
        return (r-l+1)-cnt; // we return non special numbers
    }
};
int main(){
    int l,r;
    cin>>l>>r;
    Solution s;
    int ans = s.nonSpecialCount(l,r);
    cout<<ans<<endl;
    return 0;
}