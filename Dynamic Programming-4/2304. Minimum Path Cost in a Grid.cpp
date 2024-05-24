// class Solution {
// public:
// <-----------RECURSION--------------->
//     int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& cost) {
//         if (i == grid.size() - 1) {
//             return grid[i][j];
//         }
//         int mini = INT_MAX;
//         for (int col = 0; col < grid[0].size(); col++) {
//             mini = min(mini, solve(i + 1, col, grid, cost) + cost[grid[i][j]][col]);
//         }
//         return grid[i][j] + mini;
//     }

//     int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& cost) {
//         int ans = INT_MAX;
//         for (int j = 0; j < grid[0].size(); j++) {
//             ans = min(ans, solve(0, j, grid, cost));
//         }
//         return ans;
//     }
// };

// <---------------MEMOIZATION------------------->
// class Solution {
// public:
//     int solvemem(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&cost, vector<vector<int>>&dp){
//         if(i == grid.size()-1){
//             return dp[i][j] = grid[i][j];
//         }
        
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         int mini = INT_MAX;
        
//         for(int col = 0; col<grid[0].size(); col++){
//             mini = min(mini, solvemem(i+1, col, grid, cost, dp)+cost[grid[i][j]][col]);
//         }
        
//         return dp[i][j]=grid[i][j]+mini;
//     }
    
//     int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& cost) {
//         vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(), -1));
//         int ans = INT_MAX;
//         for(int j = 0; j<grid[0].size(); j++){
//             ans = min(ans,solvemem(0,j, grid, cost, dp));
//         }   
//         return ans;
//     }
// };

// <--------------TABULATION----------------->
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& cost) {
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size()));
        
        for(int i = 0; i<grid[0].size(); i++){
            dp[0][i] = grid[0][i];
        }
        
        for(int i = 1; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                int mini = INT_MAX;
                
                for(int col = 0; col<grid[0].size(); col++){
                    mini = min(mini, dp[i-1][col]+cost[grid[i-1][col]][j]);
                }
                
                dp[i][j]+=mini;
                dp[i][j]+=grid[i][j];
            }
        }
        
        return *min_element(dp.back().begin(), dp.back().end());
    }
};
