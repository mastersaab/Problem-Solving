#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m,tar;
  cin>>n>>m>>tar;
  vector<long long> A(n),B(m);
  vector<long long> A1(n+1);
  vector<long long> B1(m+1);
  for(int i=0;i<n;i++)
  {
   cin>>A[i];
  }
   for(int i=0;i<m;i++)
  {
   cin>>B[i];
  }
 

  int j=0,k=0;
  for(int i=1;i<n+1;i++)
  {
    A1[i]=A[i-1]+A1[i-1];
    
    if(A1[i]<=tar)
       j=i;
  }
  for(int i=1;i<m+1;i++)
  {
    B1[i]=B[i-1]+B1[i-1];
    
    if(B1[i]<=tar)
      k=i;
  }
 int ans=0; 
for(int i=0;i<=j;i++)
{ 
    if(A1[i]+B1[k]>tar){
       k--;
      continue;
  }
    ans=max(ans,i+k);
}
 cout<<ans;
  return 0;
}
