//------ RECURSION------
    /*
    int numRollsToTarget(int n, int k, int target) {
        if(target == 0 && n == 0) return 1;
        if(target == 0 || n == 0) return 0; 
        int ways = 0;
        for(int num = 1; num <= k ; num++){
            if(target - num >= 0){
                ways = (ways + numRollsToTarget(n - 1,k , target - num))%int(MOD);
            }
        }
        return ways; 
    }
    */
    // -------TOP DOWN-------
    /*
     int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        if(target == 0 && n == 0) return 1;
        if(target == 0 || n == 0) return 0; 
        if(dp[n][target] != -1) return dp[n][target];
        int ways = 0;
        for(int num = 1; num <= k ; num++){
            if(target - num >= 0){
                ways = (ways + numRollsToTarget(n - 1,k, target - num)) % int(MOD);
            }
        }
        return dp[n][target] = ways;
    }
    */
    //-------BOTTOM UP(TABULATION)-------
    /*
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for(int number = 1 ; number <= n ; number++){
            for(int currtarget = 1 ; currtarget <= target ; currtarget++){
                int ways = 0;
                for(int num = 1; num <= k ; num++){
                    if(currtarget - num >= 0){
                        ways = (ways + dp[number - 1][currtarget - num]) % int(MOD);
                    }
                }
                dp[number][currtarget] = ways;
            }
        }
        return dp[n][target];
    }
    */
    // -------SPACE OPTIMISED-------
    int numRollsToTarget(int n, int k, int target) {
        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);
        prev[0] = 1;
        for(int number = 1 ; number <= n ; number++){
            for(int currtarget = 1 ; currtarget <= target ; currtarget++){
                int ways = 0;
                for(int num = 1; num <= k ; num++){
                    if(currtarget - num >= 0){
                        ways = (ways + prev[currtarget - num]) % int(MOD);
                    }
                }
                curr[currtarget] = ways;
            }
            prev=curr;
        }
        return curr[target];
    }
