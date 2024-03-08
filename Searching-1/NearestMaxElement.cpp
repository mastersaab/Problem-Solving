#include<bits/stdc++.h>
using namespace std;
int max(vector<int>v,int l,int h,int key){
    
    int ans=INT_MIN;
    while(l<=h){
       int mid=(l+h)/2;
       if(v[mid]<=key){
            ans= v[mid];
            l=mid+1;
         }
       else{
        h=mid-1;
        }
    }    
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int key;
    cin>>key;
  //  cout<<key;
    int bs=max(v,0,n-1,key);
    if(bs) cout<<bs;
 return 0;
}
