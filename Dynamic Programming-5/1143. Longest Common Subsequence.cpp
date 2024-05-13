int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // dp[i][j] ==>contains the length of the longest common subsequence for(i,j)
        for (int i=1;i<=n;++i) {
            for (int j=1;j<=m;++j) {
                // If current characters match
                // diagonal me ek add kr do
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                } 
                else {
                    // If current characters do not match
                    // left aur top ka max add kr do
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
