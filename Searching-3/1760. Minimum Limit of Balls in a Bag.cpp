class Solution {
public:
    bool isPossible(vector<int>& nums,int maxoperations,int mid){
        for(int i=0;i<nums.size();i++){
            maxoperations-=(nums[i]/mid);
            if(nums[i]%mid==0) maxoperations++;
        }
        if(maxoperations>=0) return true;
        else return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1,h=INT_MAX;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isPossible(nums,maxOperations,mid)){
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
