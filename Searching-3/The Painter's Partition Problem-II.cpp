class Solution
{
  public:
    bool canPaintInTime(int arr[],int n,int k,long long mid){
        long long time=0;
        int painters=1;
        for(int i=0;i<n;i++){
            if(time+arr[i]<=mid) time+=arr[i];
            else{
                painters++;
                if(painters>k||arr[i]>mid) return false;
                time=arr[i];
            }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
        }
        long long l=maxi;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        long long h=sum;
        long long ans=-1;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(canPaintInTime(arr,n,k,mid)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
