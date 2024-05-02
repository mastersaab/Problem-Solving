RECURSION
int robbing(vector<int>nums,int index){
        if(index==0) return nums[index];
        if(index<0) return 0;
        int pick=nums[index]+robbing(nums,index-2);
        int notpick=robbing(nums,index-1);
        return max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        return robbing(nums,nums.size()-1);
    }

MEMOIZATION
 int robbing(vector<int>nums,int index,vector<int>&dp){
        if(index==0) return nums[index];
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];
        int pick=nums[index]+robbing(nums,index-2,dp);
        int notpick=robbing(nums,index-1,dp);
        dp[index]= max(pick,notpick);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return robbing(nums,nums.size()-1,dp);
    }

TABULATION
int robbing(vector<int>&nums,int index,vector<int>&dp){
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int pick=nums[i];
            if(i>1)
             pick+=dp[i-2];
            int notpick=dp[i-1];
            dp[i]= max(pick,notpick);
        }
        return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        return robbing(nums,nums.size()-1,dp);
    }
