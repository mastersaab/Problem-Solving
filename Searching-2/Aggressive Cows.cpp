class Solution {
public:
    bool isPossible(vector<int> &stalls,int k,int mid){
        int cowcount=1;
        int lastpos=stalls[0];
        for(int i=0;i<stalls.size();i++){
            if(stalls[i]-lastpos>=mid){
                cowcount++;
                if(cowcount==k) return true;
                lastpos=stalls[i];
            }
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int s=0;
        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,stalls[i]);
        }
        int e=maxi;
        int ans=-1;
       
        while(s<=e){
         int mid=s+(e-s)/2;
         if(isPossible(stalls,k,mid)){
             ans=mid;
             s=mid+1;
         }
         else e=mid-1;
        }
        return ans;
    }
};
