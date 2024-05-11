int countFriendsPairings(int n){
        // --------RECURSION--------
        /*
        if (n == 1){
            return 1;
        }
        if (n == 2){
            return 2;
        }
        return ((countFriendsPairings(n - 1)) + (n - 1) * ((countFriendsPairings(n - 2))));  
        */
        
        // -------MEMOIZATION--------
        /*
        long long int MM = 1000000007;
        vector<int>dp(n+3,-1);
        if(n==1){
            return dp[n]=1;
        }
        if(n==2){
            return dp[n] = 2;
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        dp[n] = ((countFriendsPairings(n-1))%MM+ (n-1)*((countFriendsPairings(n-2))%MM))%MM;
        return dp[n];
        */
        
        // -------TABULATION------- 
        /*
        long long int dp[n+1];
        long long int MM = 1000000007;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<n+1; i++){
            dp[i] = (dp[i-1]%MM + (i-1)*(dp[i-2]%MM))%MM;
        }
        return dp[n];
        */
        // ------SPACE OPTIMISATION
        long long int MM = 1000000007;
        if(n==1)return 1;
        if(n==2)return 2;
        long long int prev1=1;
        long long int prev2=2;
        long long int curr;
        for(int i=3;i<=n;i++){
           curr=(prev2+(i-1)*prev1)%MM;
           prev1=prev2;
           prev2=curr;
        }
        return curr;
    }
