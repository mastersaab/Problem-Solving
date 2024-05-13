int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // TABULATION

        // int n=dungeon.size();
        // int m=dungeon[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,0));
        // // dp[i][j] shows min health required to reach cell (i,j)
        // if(dungeon[n-1][m-1]<0) dp[n-1][m-1]=-dungeon[n-1][m-1]+1;
        // if(dungeon[n-1][m-1]>=0) dp[n-1][m-1]=1;
        // // Fill the last column
        // for (int i=n-2;i>=0;i--) {
        //     dp[i][m-1]=max(1,dp[i+1][m-1]-dungeon[i][m-1]);
        // }
        // // Fill the last row
        // for (int j=m-2;j>=0;j--) {
        //     dp[n-1][j]=max(1,dp[n-1][j+1]-dungeon[n-1][j]);
        // }
        // for(int i=n-2;i>=0;i--){
        //     for(int j=m-2;j>=0;j--){ 
        //          if(dungeon[i][j]<=0) dp[i][j]=-dungeon[i][j]+min(dp[i+1][j],dp[i][j+1]);
        //          if(dungeon[i][j]>0) dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]);   
        //     }
        // }
        // return dp[0][0];
        
        // IN 1D DP (SPACE OPTIMISATION OF TABULATION)

        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<int>dp(m+1,INT_MAX); // Initialize cache with INT_MAX
        dp[m-1]=1; // Set the minimum health required for the princess cell
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                //right aur below se min health nikalo
                int bottomPathCost =dp[j];
                int rightPathCost = dp[j+1];
                //curr cell ke liye min health nikalo
                int minPowerReq=min(bottomPathCost,rightPathCost)-dungeon[i][j];
                // If minPowerReq agr neg then 1 kr do nhi t0 min powereq
                dp[j]=max(1, minPowerReq);
            }
        }
        return dp[0]; // Return the minimum health required to reach the starting cell
    }
