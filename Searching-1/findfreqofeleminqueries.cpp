#include<bits/stdc++.h>
using namespace std;
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
       int candidate=v2[i];
       int freq=0;
       int left=-1;
       int right=-2;
       int l=0;
       int h=n-1;
       // left occurance
       while(l<=h){
              int mid=(l+h)/2;
              if(v1[mid]==candidate){
                 left=mid;
                 h=mid-1;
              }
              else if(v1[mid]<candidate) l=mid+1;
              else h=mid-1;
       }
       // right ocuurance
        l=0;
        h=n-1;
       while(l<=h){
              int mid=(l+h)/2;
              if(v1[mid]==candidate){
                 right=mid;
                 l=mid+1;
              }
              else if(v1[mid]<candidate) l=mid+1;
              else h=mid-1;
       }
       freq=right-left+1;
       v3[i]=freq;
    }
    for(int i=0;i<m;i++){
           cout<<v3[i]<<" ";
      }
    return 0;
}
