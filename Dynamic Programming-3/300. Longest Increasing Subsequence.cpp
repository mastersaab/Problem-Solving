class Solution {
public:
    // RECURSION
    // int solve(int index,vector<int>& nums, int prev) {
    //     if(index==nums.size())
    //         return 0;
    //     int take = 0;
    //     if(nums[index]>prev)
    //         take=1+solve(index+1,nums,nums[index]);
    //     int nottake=solve(index+1,nums,prev);
    //     int ans=max(take,nottake);
    //     return ans;
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int prev=INT_MIN;
    //     return solve(0, nums, prev);
    // }

    // MEMOIZATION
    //  int solve(int index,vector<int>& nums, int prev,vector<std::vector<int>>& dp) {
    //     if (index == nums.size())
    //         return 0;
    //     if (dp[index][prev + 1] != -1)
    //         return dp[index][prev + 1];
    //     int take=0;
    //     if(prev==-1||nums[index]>nums[prev])
    //         take=1+solve(index+1,nums,index,dp);
    //     int nottake=solve(index+1,nums,prev,dp); 
    //     return dp[index][prev+1]=max(take,nottake);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int prev =INT_MIN;
    //     int n = nums.size();
    //     vector<vector<int>> dp(n,vector<int>(n,-1));
    //     return solve(0, nums, -1, dp);
    // }

    // TABULATION(bottom up)
    // int lengthOfLIS(vector<int>& nums) {
    //     int ans=1;
    //     int n=nums.size();
    //     vector<int>dp(n,1); // Initialize dp array with 1's
    //     for(int i=1;i<n;i++) {
    //         int max_lis_just_before=0;
    //         for(int j=0;j<i;j++) {
    //             if(nums[i]>nums[j])
    //                 max_lis_just_before=max(max_lis_just_before,dp[j]);
    //         }
    //         dp[i]=max_lis_just_before+1;
    //         ans=max(ans,dp[i]);
    //     }
    //     return ans;
    // }
    
    // BINARY SEARCH + TABULATION( n*logn)
    int helper(vector<int>& ar, int start, int end, int tar) {
        int ans=-1;
        while(start<=end) {
            int mid=start+(end-start)/2;
            if(ar[mid]==tar) {
                ans=mid;
                break;
            }
            else if(ar[mid]<tar) {
                start=mid+1;
            }
            else{
                ans=mid;
                end=mid-1;
            }
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ar;
        ar.push_back(nums[0]);
        int n=nums.size();
        for(int i=1;i<n;i++) {
            if(ar.back()<nums[i])
                ar.push_back(nums[i]);
            else {
                int ans=helper(ar,0,ar.size()-1,nums[i]);
                ar[ans]=nums[i];
            }
        }
        return ar.size();
    }
};
