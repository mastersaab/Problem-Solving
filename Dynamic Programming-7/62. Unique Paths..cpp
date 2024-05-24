// class Solution {
// public:
// <-----------RECURSION-------------->
//     int solve(int m, int n, int i, int j){
//             if(i>m-1 || j>n-1 || i<0 || j<0){
//                 return 0;
//             }
//             if(i==m-1 && j==n-1) return 1;
//             int ans =0;
//             int right = solve(m,n,i,j+1);
//             int down = solve(m,n,i+1,j);
//             return ans = right+down;
//     }
//     int uniquePaths(int m, int n) {
//         return solve(m,n,0,0);
//     }
// };

// class Solution {
// public:
// // <-----------MEMOIZATION-------------->
//     int solve(int m, int n, int i, int j, vector<vector<int>> &dp){
//         if(i>m-1 || j>n-1 || i<0 || j<0){
//             return 0;
//         }
//         if(i==m-1 && j==n-1) return 1;
        
//         if(dp[i][j]!= -1) return dp[i][j];

//         int right = solve(m,n,i,j+1,dp);
//         int down = solve(m,n,i+1,j,dp);
//         return dp[i][j] = right+down;
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
//         return solve(m,n,0,0,dp);
//     }
// };

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2D DP table initialized with 0
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Base case: there is only one way to reach any cell in the first row or first column
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = 1;
        }

        // Fill the DP table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // The number of unique paths to the bottom-right corner
        return dp[m - 1][n - 1];
    }
};

