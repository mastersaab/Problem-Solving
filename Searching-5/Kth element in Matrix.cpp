int kthSmallest(vector<vector<int>>& matrix, int k) {
      int n=matrix.size();
      int m=matrix[0].size();
      int low=matrix[0][0];
      int high=matrix[n-1][m-1];
     
      while(low<high)
      { int count=0;
        int mid=low+(high-low)/2;
        for(int i=0;i<n;i++)
          count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
         if(count<k)
               low=mid+1;
         else 
               high=mid;
           
        
      }  
      return low;
    }
