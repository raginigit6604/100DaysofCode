#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; // t = testcase
	cin>>t;
	while(t--){
         int n,m;
		 cin>>n>>m;
		 int a[n];
		 int b[m];
		 long long ans = 0;
		 for(int i=0;i<n;i++){
			 cin>>a[i];
		 }
		 for(int j=0;j<m;j++){
			 cin>>b[j];
		 }
		 int i=0,j=0;
		 long long sum1 = 0,sum2 = 0;
		 while(i<n && j<m){
          if(a[i] < b[j]){
			  sum1 += a[i];
			  i++;
		  }
		  else if(a[i]>b[j]){
			  sum2 += b[j];
			  j++;
		  }
		  else if(a[i] == b[j]){
			  if(sum1>sum2){
				  ans += sum1;
			  }
			  else{
				  ans += sum2;
			  }
			  //for common element
			  ans += a[i];
			  i++;
			  j++;
			  sum1 = 0;
			  sum2 = 0;
		  }
		 }
		 //if ith elements are remaining after jth vanished
      while(i<n){
		  sum1 += a[i];
		  i++;
	  }
	  //if jth element are remaining after ith vanished
	  while(j<m){
		  sum2 += b[j];
		  j++;
	  }
	  ans+= max(sum1,sum2);
	  cout<<ans<<endl;
	}
	return 0;
}