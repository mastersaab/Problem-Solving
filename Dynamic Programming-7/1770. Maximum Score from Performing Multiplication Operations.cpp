// class Solution {
// public:
// <-----------RECURSION------------>
//     int solve(int i, int j, vector<int> &nums, int n, vector<int> &multipliers, int m, int index){
//         if (index >= m) return 0;
//         int left = nums[i] * multipliers[index] + solve(i + 1, j, nums, n, multipliers, m, index + 1);
//         int right = nums[j] * multipliers[index] + solve(i, j - 1, nums, n, multipliers, m, index + 1);
//         return max(left, right);
//     }

//     int maximumScore(vector<int> &nums, vector<int> &multipliers){
//         int n = nums.size();
//         int m = multipliers.size();
//         return solve(0, n - 1, nums, n, multipliers, m, 0);
//     }
// };

// <------------------MEMOIZATION---------------------->
// class Solution
// {
//     public:
//         int solve(int i, int j, vector<int> &nums, int n, vector<int> &multipliers, int m, int index, vector< vector< int>> &dp)
//         {
//             if (index >= m) return 0;
//             if (dp[index][i] != INT_MIN) return dp[index][i];
//             int left = nums[i] *multipliers[index] + solve(i + 1, j, nums, n, multipliers, m, index + 1, dp);
//             int right = nums[j] *multipliers[index] + solve(i, j - 1, nums, n, multipliers, m, index + 1, dp);
//             return dp[index][i] = max(left, right);
//         }
//     int maximumScore(vector<int> &nums, vector<int> &multipliers)
//     {
//         int n = nums.size();
//         int m = multipliers.size();
//         vector<vector < int>> dp(m, vector<int> (m, INT_MIN));
//         return solve(0, n - 1, nums, n, multipliers, m, 0, dp);
//     }
// };

// <-------------------TABULATION---------------->
class Solution{
public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers){
        int n = nums.size();
        int m = multipliers.size();
        
        // dp[i][j] will store the maximum score we can get using the first i multipliers and considering j elements from the start of nums
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

        // Fill the dp array from the bottom up
        for (int index = m - 1; index >= 0; --index){
            for (int i = index; i >= 0; --i){
                int j = n - 1 - (index - i);
                dp[index][i] = max(
                    nums[i] * multipliers[index] + dp[index + 1][i + 1],
                    nums[j] * multipliers[index] + dp[index + 1][i]
                );
            }
        }
        return dp[0][0];
    }
};
