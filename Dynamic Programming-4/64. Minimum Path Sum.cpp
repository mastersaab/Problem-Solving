// class Solution {
// public:
// <------------RECURSION-------------->
//       int solve(int i, int j, vector<vector<int>>& grid) {
//         if (i == 0 && j == 0) {
//             return grid[i][j];
//         }
//         if (i < 0 || j < 0) {
//             return 1e9; // Large value to represent an invalid path
//         }
//         return grid[i][j] + min(solve(i-1, j, grid), solve(i, j-1, grid));
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();
//         return solve(n-1, m-1, grid);
//     }
// };

// <----------------MEMOIZATION------------------->
// class Solution {
// public:
//     int solveMem(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
//         if(i==0 && j==0){return grid[i][j];}
//         if(i<0 || j<0){return 1e9;}
//         if(dp[i][j]!=-1){return dp[i][j];}
//         return dp[i][j]=min(grid[i][j]+solveMem(i-1, j, grid, dp), grid[i][j]+solveMem(i, j-1, grid, dp));
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n=grid.size(), m=grid[0].size();
//         vector<vector<int>>dp(n, vector<int>(m, -1));
//         return solveMem(n-1, m-1, grid, dp);
//     }
// };

// <---------------TABULATION-------------->
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int n=grid.size(), m=grid[0].size();
//         vector<vector<int>>dp(n, vector<int>(m, 0));
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(i==0 && j==0){dp[i][j]=grid[i][j];}
//                 else{
//                     int u=1e9, l=1e9;
//                     if(i>0){u=dp[i-1][j];}
//                     if(j>0){l=dp[i][j-1];}
//                     dp[i][j]+=grid[i][j];
//                     dp[i][j]+=min(u, l);
//                 }
//             }
//         }
//         return dp[n-1][m-1];
//     }
// };

// <---------------SPACE OPTIMISATION--------------------->
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<int>dp(m, 0);
        for(int i=0; i<n; i++){
            vector<int>temp(m, 0);
            for(int j=0; j<m; j++){
                if(i==0 && j==0){temp[j]=grid[i][j];}
                else{
                    int u=1e9, l=1e9;
                    if(i>0){u=dp[j];}
                    if(j>0){l=temp[j-1];}
                    temp[j]+=grid[i][j];
                    temp[j]+=min(u, l);
                }
            }
            dp=temp;
        }
        return dp[m-1];
    }
};
