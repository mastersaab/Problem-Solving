// class Solution {
// public:
// // <------------RECURSION-------------->
//    int solve(int ind,int target,vector<int> &nums){
//         if(target==0) return 0;
//         if(target<0) return INT_MIN;
//         if(ind==0){
//             if(nums[0]==target) return 1;
//             return INT_MIN;
//         }

//         int take=1+solve(ind-1,target-nums[ind],nums);
//         int notTake=0+solve(ind-1,target,nums);
        
//         return max(take,notTake);
//     }
//     int lengthOfLongestSubsequence(vector<int>& nums, int target) {
//         int n=nums.size();
//         int ans=solve(n-1,target,nums);
//         return ans>0 ? ans:-1;
//     }
// };

// <---------------MEMOIZATION--------------->
// class Solution {
// public:
//    int solveMem(int ind,int target,vector<int> &nums,vector<vector<int>> &dp){
//         if (target==0) return 0;
//         if(target<0) return INT_MIN;
//         if(ind==0){
//             if(nums[0]==target) return 1;
//             return INT_MIN;
//         }
//         if(dp[ind][target]!=-1) return dp[ind][target];
//         int take=1+solveMem(ind-1,target-nums[ind],nums,dp);
//         int notTake=0+solveMem(ind-1,target,nums,dp);
//         return dp[ind][target]=max(take,notTake);
//     }
//     int lengthOfLongestSubsequence(vector<int>& nums, int target) {
//         int n=nums.size();
//         vector<vector<int>> dp(n,vector<int>(target+1,-1));
//         int ans=solveMem(n-1,target,nums,dp);
//         return ans>0 ? ans:-1;
//     }
// };

// <----------------TABULATION------------------->
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, INT_MIN));

        // Initialize base cases
        for (int i = 0; i < n; ++i) {
            dp[i][0] = 0; // If the target is 0, the length of the subsequence is 0
        }
        if (nums[0] <= target) {
            dp[0][nums[0]] = 1; // If the first element is equal to the target
        }

        // Fill the dp table
        for (int i = 1; i < n; ++i) {
            for (int t = 0; t <= target; ++t) {
                int notTake = dp[i - 1][t]; // Not taking the current element
                int take = INT_MIN;
                if (t >= nums[i]) {
                    take = 1 + dp[i - 1][t - nums[i]]; // Taking the current element
                }
                dp[i][t] = max(take, notTake);
            }
        }

        // The answer is the value at dp[n-1][target]
        return dp[n - 1][target] > 0 ? dp[n - 1][target] : -1;
    }
};
