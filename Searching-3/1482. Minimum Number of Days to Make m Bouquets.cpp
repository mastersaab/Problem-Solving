class Solution {
public: 
    bool isPossible(vector<int>& bloomDay,int day,int m,int k){
        long long cnt=0;
        long long noofb=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day) cnt++;
            else{
                noofb+=(cnt/k);
                cnt=0;
            }
        }
        noofb+=(cnt/k);
        if(noofb>=m) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size();
        if (val > n) return -1; 
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            maxi=max(maxi,bloomDay[i]);
            mini=min(mini,bloomDay[i]);
        }
        int l=mini;
        int h=maxi;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isPossible(bloomDay,mid,m,k)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;      
        }
};
