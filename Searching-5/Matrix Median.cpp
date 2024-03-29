WITHOUT BINARY SEARCH
int findMedian(vector<vector<int> > &A) {           //easy peasy
    vector<int>v;
    for(const auto& row: A){
        v.insert(v.end(),row.begin(),row.end());
    }
    sort(v.begin(),v.end());
    int n=v.size();
    if(n%2 !=0){ return v[n/2];}                              //for odd no. elements
    else if(n%2==0){ int mid= v[n/2]+v[n-1/2]; return mid/2;}  //for even no. of elements
    
}


USING BINARY SEARCH
int countElementsLessThanMid(vector<int>&v, int x) {
    int lo=0, hi=v.size()-1;
    int cnt=0;
    while(lo<=hi) {
        int mid=lo+(hi-lo)/2; 
        if(v[mid] < x){        // Checking for next highest element
            cnt = (mid+1); // 0th-based indexing
            lo=mid+1;
        } else {
            hi=mid-1;
        }
    }
    return cnt;
}

// This is Binary search on search space of length = (max-min)
// So it takes O(log(max-min)) 

int Solution::findMedian(vector<vector<int>> &A) {
    int n=A.size(),m=A[0].size();
    int lo = INT_MAX, hi = INT_MIN;
    for(int i=0;i<n;i++){
        lo = min(lo, A[i][0]);
        hi = max(hi, A[i][m-1]);
    }
    int ans;
    while(lo<=hi) {
        int mid=lo+(hi-lo)/2;
        int count=0;
        // Every single row is sorted SO make use of that via Binary search
        for(int i=0;i<n;i++)
            count += countElementsLessThanMid(A[i], mid);
        if(count<=(n*m/2)){
            ans=mid;
            lo=mid+1;
        } else {
            hi=mid-1;
        }
    }
    return ans;        
}
