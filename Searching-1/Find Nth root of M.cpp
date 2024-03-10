class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    if(n==0) return 0;
	    int l=1;
	    int h=m;
	    int ans=-1;
	    while(l<=h){
	        int mid=l+(h-l)/2;
	        if(pow(mid,n)==m) {
	            return mid;
	        }
	        else if(pow(mid,n)<m)  l=mid+1;
	        else h=mid-1;
	    }
	    return -1;
	}  
	
};
