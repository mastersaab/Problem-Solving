// -----RECURSIVE-----
    /*
    int solve(int n, vector<vector<int>>& mat, int r, int c) {
    // Base case: 
    if (c >= n) return 0;
    int take = mat[r][c] + max(solve(n, mat, 1, c + 2), solve(n, mat, 0, c + 2));
    int nottake1 = solve(n, mat, 1, c + 1); //phli  row
    int nottake2 = solve(n, mat, 0, c + 1);  //dusri row
    // Return the maximum value among the three possibilities
    return max(take, max(nottake1, nottake2));
    }
    */
    
    // ------MEMOIZED--------
    /*
    int solve(int n, vector<vector<int>>& mat, int r, int c, vector<vector<int>>& dp) {
    if (c >= n) return 0;
    if (dp[r][c] != -1) return dp[r][c];
    int take = mat[r][c] + max(solve(n, mat, 1, c + 2, dp), solve(n, mat, 0, c + 2, dp));
    int nottake1 = solve(n, mat, 1, c + 1, dp);
    int nottake2 = solve(n, mat, 0, c + 1, dp);
    return dp[r][c] = max(take, max(nottake1,nottake2));
    }
    */
    
    int maxSum(int N, vector<vector<int>> mat)
    {    
        //  return max(solve(N,mat,0,0),solve(N,mat,1,0));  //recursion call
        
        // vector<vector<int>>dp(3,vector<int>(N+1,-1));
        // return max(solve(N,mat,0,0,dp),solve(N,mat,1,0,dp));  //memoization call
      
        //------TABULATION-------
        /*
        vector<int>dp(N+1,0);
        dp[0]=0;
        dp[1] = max(mat[0][0],mat[1][0]);
        for(int index=2;index<=N;index++)
        {
            dp[index] = max(max(mat[0][index-1],mat[1][index-1])+dp[index-2] , dp[index-1]);
        }
        return dp[N] ;
        */
        
        // --------SPACE OPTIMISATION-------
        int prev1=0;
        int curr1= max(mat[0][0],mat[1][0]);
        for(int i=2;i<=N;i++)
        {
            int curr2= max(max(mat[0][i-1],mat[1][i-1])+prev1,curr1);
            prev1=curr1;
            curr1=curr2;
        }
        return curr1;
    }
