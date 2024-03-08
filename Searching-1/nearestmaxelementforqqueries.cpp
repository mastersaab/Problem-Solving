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
    vector<int>v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    int m;
    cin>>m;
    vector<int>v2(m);
    for(int i=0;i<m;i++){
        cin>>v2[i];
    }
    vector<int>v3(m);
    for(int i=0;i<m;i++){
       int bs=max(v1,0,n-1,v2[i]);
       v3[i]=bs;
    }
    for(int i=0;i<m;i++){
        cout<<v3[i]<<" 4";
    }
 return 0;
}
