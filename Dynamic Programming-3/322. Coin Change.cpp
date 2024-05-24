class Solution {
public:
//    <--------RECURSION--------->

    // int solve(vector<int> &coins, int cur, int amount) {
    //     if (cur >= coins.size() || amount <= 0)
    //         if(amount == 0) return 0;
    //         else return INT_MAX-1;   
        
    //     int res = -1;
    //     if (coins[cur] > amount) {
    //         int doNotTakeCoin = 0 + solve(coins, cur + 1, amount - 0);
    //         res = doNotTakeCoin;
    //     }
    //     else {
    //         int takeCoin = 1 + solve(coins, cur + 0, amount - coins[cur]);
    //         int doNotTakeCoin = 0 + solve(coins, cur + 1, amount - 0);
    //         res = min(takeCoin, doNotTakeCoin);
    //     }
    //     return res;
    // }

    // <---------MEMOIZATION----------->

//     int solve(vector<int> &coins, int cur, int amount, vector<vector<int>> &dp) {
//     if (amount == 0) return 0; // Base case: no amount left to change
//     if (cur >= coins.size() || amount < 0) return INT_MAX - 1; // Base case: no more coins or negative amount

//     if (dp[cur][amount] != -1) return dp[cur][amount];

//     int takeCoin = INT_MAX - 1;
//     if (coins[cur] <= amount) {
//         takeCoin = 1 + solve(coins, cur, amount - coins[cur], dp); // Take the current coin
//     }
//     int doNotTakeCoin = solve(coins, cur + 1, amount, dp); // Do not take the current coin

//     dp[cur][amount] = min(takeCoin, doNotTakeCoin);
//     return dp[cur][amount];
// }

//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount + 1, -1)); // Initialize dp array with dimensions [n][amount+1]
//         int res = solve(coins, 0, amount, dp);
//         if (res == INT_MAX - 1) return -1; // If no solution found
//         return res;
//     }
// <-------TABULATION--------->
int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1));
        for(int i=0; i<n+1; i++){
            for(int j=0; j<amount+1; j++){
                // if no coins present, then we need to take infinite coins to fulfill the amount
                // if amount is 0, then we need to take 0 coins to fulfill the amount
                if(j==0) dp[i][j] = 0;
                if(i==0) dp[i][j] = INT_MAX-1;
            }
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<amount+1; j++){
                // if the present coin is smaller than the amount, we can either take it or decide not to take it
                // else if the coin is larger than the amount, we can't take it
                if(coins[i-1] <= j){
                    // choose minimum number of coisn required
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        // if the answer is infinte only, that means, we could not find a way to take coins to fulfill the amount
        return dp[n][amount] == (INT_MAX-1)? -1 : dp[n][amount];
    }
};
