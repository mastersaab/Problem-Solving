WITHOUT BS

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    if(m>n) return kthElement(arr2,arr1,m,n,k);
    for(int i=0;i<m;i++){
        arr1.push_back(arr2[i]);
    }
    sort(arr1.begin(),arr1.end());
    return arr1[k-1];
}

WITH BINARY SEARCH

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
   
   if(n>m)return kthElement(arr2,arr1,m,n,k);

int low=max(0,k-m),high=min(k,n);
   
   while(low<=high)
   {
    int amid=low+(high-low)/2;
    int bmid=k-amid;
    int aleft=(amid==0)?INT_MIN:arr1[amid-1];
    int bleft=(bmid==0)?INT_MIN:arr2[bmid-1];
    int aright=(amid==n)?INT_MAX:arr1[amid];
    int bright=(bmid==m)?INT_MAX:arr2[bmid];
if(aleft<=bright && bleft<=aright)
{

return max(aleft,bleft);
}
  
 else if(aleft>bright)
  high=amid-1;
  else 
    low=amid+1;
   }
   return -1;
 
}
