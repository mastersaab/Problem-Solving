RECURSION
 int jumps(vector<int>&nums,int curr,int dest){
        if(curr>=dest) return 0;
        int mini=INT_MAX;
        for(int i=1;i<=nums[curr];i++){
            int jump=jumps(nums,curr+i,dest);
            if(jump!=INT_MAX)
             mini=min(mini,1+jump);
        }
        return mini;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        return jumps(nums,0,n-1);
    }
MEMOIZATION
int jumps(vector<int>&nums,int curr,int dest,vector<int>&dp){
        if(curr>=dest) return 0;
        int mini=INT_MAX;
        if(dp[curr]!=-1) return dp[curr];
        for(int i=1;i<=nums[curr];i++){
            int jump=jumps(nums,curr+i,dest,dp);
            if(jump!=INT_MAX)
             mini=min(mini,1+jump);
        }
        dp[curr]= mini;
        return dp[curr];
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return jumps(nums,0,n-1,dp);
    }
TABULATION
 int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX); // Initialize dp with INT_MAX
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (i <= j + nums[j]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }
