//------RECURSION-------
/*
    int count(vector<vector<int>>&questions, int n){
        if(n>=questions.size()) return 0;
        int result=0;
        int solve=questions[n][0]+count(questions, n+1+questions[n][1]);  // bheja fry
        int skip=count(questions, n+1);                               // not bheja fry
        return result=max(solve,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        return count(questions, 0);
    }
*/
// -------MEMOIZATION--------
/*   long long count(vector<vector<int>>&questions, int n, vector<long long>&dp){
        if(n>questions.size()) return 0;
        if(dp[n]!=-1) return dp[n];
        long long result=0;
        long long solve=questions[n-1][0]+count(questions, n+1+questions[n-1][1], dp);
        long long skip=count(questions, n+1, dp);
        result=max(solve, skip);
        return dp[n]=result;
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n+1, -1);
        count(questions, 1, dp);
        return dp[1];
    }
*/
// --------TABULATION------------
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n+1);
        for(int i=n;i>=1;i--){
            long long solve=questions[i-1][0];
            if((i+1+questions[i-1][1])<dp.size()){
             solve+=dp[i+1+questions[i-1][1]];
            }    
            long long skip=0;
            if(i+1<dp.size()){
             skip+=dp[i+1];
            }
            dp[i]=max(solve , skip);
        }
        return dp[1];
    }
/*
    long long mostPoints(vector<vector<int>>& questions) {
            int n = questions.size();
            long long prev = 0, curr = 0;
            for (int i = n; i >= 1; i--) {
                long long solve = questions[i-1][0];
                if (i + 1 + questions[i-1][1] <= n) {
                    solve += prev;
                }
                long long skip = curr;
                prev = curr;
                curr = max(solve, skip);
            }
            return curr;
        }
*/
// In the provided input, the questions are [[3,2],[4,3],[4,4],[2,5]], which means for the first question
// we get 3 points but have to wait 2 days before we can answer the next question. The current implementation
// doesn’t correctly handle this waiting period.
