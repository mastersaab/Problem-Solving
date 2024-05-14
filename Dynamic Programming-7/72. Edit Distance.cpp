/* ------RECURSION--------
    int minoperationtoconvert(string s1, string s2,int i , int j,){
        if(i<0 && j<0) return 0;
        if(j<0) return i+1;
        if(i<0) return j+1;
        if(s1[i]==s2[j]){
           return minoperationtoconvert(s1,s2,i-1,j-1);
        }
        else
        {
            int opreplace=minoperationtoconvert(s1,s2,i-1,j-1);
            int opadd    =minoperationtoconvert(s1,s2,i  ,j-1);
            int opremove =minoperationtoconvert(s1,s2,i-1,j);
            return min(opreplace,min(opadd,opremove))+1;
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        return minoperationtoconvert(word1,word2,n-1,m-1);
    }
    */
    /*-------MEMOIZATION----------
    int minoperationtoconvert(string s1, string s2,int i , int j,vector<vector<int>>& dp){
        if(i<0 && j<0) return 0;
        if(j<0) return i+1;
        if(i<0) return j+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
           return dp[i][j]=minoperationtoconvert(s1,s2,i-1,j-1,dp);
        }
        else
        {
            int opreplace=minoperationtoconvert(s1,s2,i-1,j-1,dp);
            int opadd    =minoperationtoconvert(s1,s2,i  ,j-1,dp);
            int opremove =minoperationtoconvert(s1,s2,i-1,j  ,dp);
            return dp[i][j]= min(opreplace,min(opadd,opremove))+1;
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return minoperationtoconvert(word1,word2,n-1,m-1,dp);
    }
    */
    /*--------TABULATION--------
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int opreplace=dp[i-1][j-1]+1;
                    int opadd    =dp[i][j-1]+1;
                    int opremove =dp[i-1][j]+1;
                    dp[i][j]=min(opreplace,min(opadd,opremove));
                }
            }
        }
        return dp[n][m];
    }
    */
    // --------SPACE OPTIMISATION---------
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        for(int j=0;j<=m;j++) prev[j]=j;
        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j]=prev[j-1];
                }
                else{
                    int opreplace=prev[j-1]+1;
                    int opadd    =curr[j-1]+1;
                    int opremove =prev[j]+1;
                    curr[j]=min(opreplace,min(opadd,opremove));
                }
            }
            prev=curr;
        }
        return prev[m];
    }
