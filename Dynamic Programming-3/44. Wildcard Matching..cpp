// class Solution {
// private:
// // <----------RECURSION------------->
//     bool helper(int i,int j,string &s,string &p){
//         if(i==0 || j==0){
//             while(j>0 && p[j-1]=='*') j--;
//             return j==0 && i==0;
//         }
//         if(s[i-1]==p[j-1] || p[j-1]=='?') return  helper(i-1,j-1,s,p);
        
//         if(p[j-1]=='*'){
//             return helper(i-1,j,s,p) || helper(i,j-1,s,p);
//         }
//         return false;
//     }
// public:
//     bool isMatch(string s, string p) {
//         int n = s.size(),m=p.size();
//         return helper(n,m,s,p);
//     }
// };

// <---------MEMOIZATION------------->
// class Solution {
// private:
//     bool helper(int i,int j,string &s,string &p,vector<vector<int>> &dp){
//         if(i==0 || j==0){
//             while(j>0 && p[j-1]=='*') j--;
//             return j==0 && i==0;
//         }
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(s[i-1]==p[j-1] || p[j-1]=='?') return dp[i][j] = helper(i-1,j-1,s,p,dp);
        
//         if(p[j-1]=='*'){
//             return dp[i][j] = helper(i-1,j,s,p,dp) || helper(i,j-1,s,p,dp);
//         }
//         return dp[i][j] = false;
//     }
// public:
//     bool isMatch(string s, string p) {
//         int n = s.size(),m=p.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//         return helper(n,m,s,p,dp);
//     }
// };

// <-----------TABULATION---------->
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(),m=p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        
        dp[0][0] = true;

        for(int i=1; i<=m; i++){
            bool f = true;
            for(int ii=1; ii<=i; ii++)
                if(p[ii-1] != '*') f=false;
            
            dp[0][i] = f;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j] = dp[i-1][j-1];
        
                else if(p[j-1]=='*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};
