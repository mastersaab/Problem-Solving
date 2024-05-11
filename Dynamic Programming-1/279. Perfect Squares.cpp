// -----RECURSION-----
/*
    int numSquares(int n) {
    if (n == 0) return 0;
    int result = INT_MAX;
    for (int i = 1; i * i <= n; i++) {
        result = min(result, 1 + numSquares(n - i * i));
    }
    return result;
    }
*/

// -----MEMOIZATION-------
/*   int solve(int n, vector<int>&dp) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        int result = INT_MAX;
        for (int i = 1; i*i <= n; i++) {
            result = min(result, 1 + solve(n - i*i, dp));
        }
        return dp[n] = result;
    }
   int numSquares(int n) {
        vector<int>dp(n+1, -1);
        return solve(n,dp); 
    }
*/
// -----TABULATION------
    int numSquares(int n) {
        vector<int>dp(n+1, 0);
        for (int num = 1; num < n+1; num++) {
            int result = INT_MAX;
            for (int i = 1; i*i <= num; i++) {
                result= min(result, 1 +dp[num - i*i]); 
            }
            dp[num] =result;
        }
        return dp[n];
    }

// ------SPACE OPTIMISATION---------
